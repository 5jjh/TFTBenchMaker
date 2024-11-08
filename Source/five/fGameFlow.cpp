// Fill out your copyright notice in the Description page of Project Settings.


#include "fGameFlow.h"

#include "fPlayerController.h"
#include "ToolBuilderUtil.h"
#include "GameFramework/DefaultPawn.h"
#include "GameFramework/GameUserSettings.h"

// Sets default values
AfGameFlow::AfGameFlow()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AfGameFlow::BeginPlay()
{
	Super::BeginPlay();
	ClearExistingPlayers();
	BeginGame();
	
}


void AfGameFlow::BeginGame()
{
    UWorld* World = GetWorld();
    if (World)
    {
    	int32 NumPlayers = 4;

    	FIntPoint ScreenRes = GetWorld()->GetGameViewport()->Viewport->GetSizeXY();
    	float ScreenW = ScreenRes.X;
    	float ScreenH = ScreenRes.Y;

    	float ViewPortW = ScreenW / NumPlayers;
    	float ViewPortH = ScreenH;
    	
        for (int PlayerNumber = 0; PlayerNumber < 4; PlayerNumber++)
        {
        	FString CameraName = FString::Printf(TEXT("CineCameraActor_%d"), PlayerNumber);
        	ACameraActor* CameraActor = nullptr;
        	for (TActorIterator<ACameraActor> It(World); It; ++It)
        	{
        		ACameraActor* CurrentCam = *It;
        		if (CurrentCam && CurrentCam->GetName() == CameraName)
        		{
        			CameraActor = CurrentCam;
        			break;
        		}
        	}

        	if (CameraActor)
        	{
        		if (APlayerController* ExistingController = UGameplayStatics::GetPlayerController(World, PlayerNumber))
        		{
        			AfPlayerController* MyPlayerController = Cast<AfPlayerController>(ExistingController);
        			if (MyPlayerController)
        			{
						AfGamePawn* NewPawn = World->SpawnActor<AfGamePawn>();
						if (NewPawn)
						{
							MyPlayerController->Possess(NewPawn);
							NewPawn->GameBoard = World->SpawnActor<AfGameBoard>();
							if (NewPawn->GameBoard)
							{
								NewPawn->GameBoard->CreateBoard(PlayerNumber);
							}

							Players.Add(NewPawn);
						}
        				UE_LOG(LogTemp, Warning, TEXT("%s and %d"), *CameraActor->GetName(), PlayerNumber);
						MyPlayerController->SetViewTargetWithBlend(CameraActor, 0.0f);
						MyPlayerController->InitializeShopWidget();
					}
        			continue;
        		}
        		APlayerController* PlayerController = UGameplayStatics::CreatePlayer(World, PlayerNumber, true);
        		if (PlayerController)
        		{
        			AfPlayerController* MyPlayerController = Cast<AfPlayerController>(PlayerController);
        			if (MyPlayerController)
        			{
        				AfGamePawn* NewPawn = World->SpawnActor<AfGamePawn>();
        				if (NewPawn)
        				{
        					MyPlayerController->Possess(NewPawn);
        					NewPawn->GameBoard = World->SpawnActor<AfGameBoard>();
        					if (NewPawn->GameBoard)
        					{
        						NewPawn->GameBoard->CreateBoard(PlayerNumber);
        					}

        					Players.Add(NewPawn);
        				}
        				MyPlayerController->SetViewTargetWithBlend(CameraActor, 0.0f);
        				MyPlayerController->InitializeShopWidget();
        			}
        		}
        	}
        }

    	UGameUserSettings* GameSettings = UGameUserSettings::GetGameUserSettings();
    	if (GameSettings)
    	{
    		GameSettings->SetScreenResolution(FIntPoint(ViewPortW, ViewPortH));
    		GameSettings->ApplySettings(false);
    	}
    }

	
}


void AfGameFlow::EndGame()
{
	// End game logic
}

void AfGameFlow::UpdateState(EGameState State)
{
	if (GameState)
	{
		GameState->SetGameState(State);
	}
}

// Called every frame
void AfGameFlow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AfGameFlow::ClearExistingPlayers()
{
	UWorld* World = GetWorld();
	if (World)
	{
		TArray<APlayerController*> AllPlayerControllers;
		for (TActorIterator<APlayerController> It(World); It; ++It)
		{
			APlayerController* PlayerController = *It;
			if (PlayerController && PlayerController->IsLocalPlayerController())
			{
				PlayerController->UnPossess();
				PlayerController->Destroy();
			}
		}
	}
}

