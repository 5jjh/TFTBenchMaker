// Fill out your copyright notice in the Description page of Project Settings.


#include "fGameBoard.h"
#include "Logging/LogMacros.h"



// Sets default values
AfGameBoard::AfGameBoard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}


void AfGameBoard::CreateBoard(int PlayerNumber)
{
    float SectorSize = 400.f;
    if (TileBoard.Num() == 0)
    {
        for (int Row = 0; Row < 6; ++Row)
        {
            for (int Column = 0; Column < 5; ++Column)
            {
                FVector SpawnLocation;
                
                if (Row % 2 == 0) 
                {
                    SpawnLocation = FVector(
                        static_cast<float>(Column) - static_cast<float>(5) / 2.f,
                          static_cast<float>(Row / 1.25),
                        0.f
                    ) * SectorSize + FVector((PlayerNumber * 4000) + 3000, 5000, 110);
                }
                else 
                {
                    SpawnLocation = FVector(
                        static_cast<float>(Column) - static_cast<float>(5) / 2.f + 0.5f, 
                          static_cast<float>(Row / 1.25),
                        0.f
                    ) * SectorSize + FVector((PlayerNumber * 4000) + 3000, 5000, 110);
                }
              

                FRotator SpawnRotation = FRotator(0, 0, 0);
                FActorSpawnParameters SpawnParams;
                SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
              
                AfGameTile* NewTile = GetWorld()->SpawnActor<AfGameTile>(TileClass, SpawnLocation, SpawnRotation, SpawnParams);
                if (NewTile)
                {
                    TileBoard.Add(NewTile);
                }
            }
        }
    }

    SectorSize = 320.f;
    if (TileBench.Num() == 0)
    {
        for (int Bench = 0; Bench < 7; ++Bench)
        {
            FVector BenchLocation = FVector(
                static_cast<float>(Bench) - static_cast<float>(7)/ 2.f,
                0.f,
                0.f
                ) * SectorSize + FVector ((PlayerNumber * 4000) + 3050, 4600, 110);
            
            FRotator BenchSpawnRotation = FRotator(0, 0, 0);
            FActorSpawnParameters BenchSpawnParams;
            BenchSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
            AfBenchTile* NewBenchTile = GetWorld()->SpawnActor<AfBenchTile>(BenchTileClass, BenchLocation, BenchSpawnRotation, BenchSpawnParams);

            if (NewBenchTile)
            {
                TileBench.Add(NewBenchTile);
            }
        }
    }

    if (EnemyTileBench.Num() == 0)
    {
        for (int Bench = 0; Bench < 7; ++Bench)
        {
            FVector BenchLocation = FVector(
                static_cast<float>(Bench) - static_cast<float>(7)/ 2.f,
                0.f,
                0.f
                ) * SectorSize + FVector ((PlayerNumber * 4000) + 3050, 7000, 110);
            
            FRotator BenchSpawnRotation = FRotator(0, 0, 0);
            FActorSpawnParameters BenchSpawnParams;
            BenchSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
            AfBenchTile* NewBenchTile = GetWorld()->SpawnActor<AfBenchTile>(BenchTileClass, BenchLocation, BenchSpawnRotation, BenchSpawnParams);

            if (NewBenchTile)
            {
                EnemyTileBench.Add(NewBenchTile);
            }
        }
    }

    if (TileEco.Num() == 0)
    {
        for (int Eco = 0; Eco < 5; ++Eco)
        {
            FVector EcoLocation = FVector(
                0.f,
                static_cast<float>(Eco / 1.25),
                0.f
                ) * SectorSize + FVector ((PlayerNumber * 4000) + 4250, 5300, 110);

            FRotator EcoSpawnRotation = FRotator(0, 0, 0);
            FActorSpawnParameters EcoSpawnParams;
            EcoSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
            AfEcoTile* NewEcoTile = GetWorld()->SpawnActor<AfEcoTile>(EcoTileClass, EcoLocation, EcoSpawnRotation, EcoSpawnParams);

            if (NewEcoTile)
            {
                TileEco.Add(NewEcoTile);
            }
        }
    }

    if (EnemyTileEco.Num() == 0)
    {
        for (int Eco = 0; Eco < 5; ++Eco)
        {
            FVector EcoLocation = FVector(
                0.f,
                static_cast<float>(Eco / 1.25),
                0.f
                ) * SectorSize + FVector ((PlayerNumber * 4000) + 1550, 5300, 110);

            FRotator EcoSpawnRotation = FRotator(0, 0, 0);
            FActorSpawnParameters EcoSpawnParams;
            EcoSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
            AfEcoTile* NewEcoTile = GetWorld()->SpawnActor<AfEcoTile>(EcoTileClass, EcoLocation, EcoSpawnRotation, EcoSpawnParams);

            if (NewEcoTile)
            {
                EnemyTileEco.Add(NewEcoTile);
            }
        }
    }

    
   
}


// Called every frame
void AfGameBoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


