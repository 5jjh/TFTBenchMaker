// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "fGameState.h"
#include "fGamePawn.h"
#include "Engine/World.h"
#include "Engine/GameViewportClient.h"
#include "EngineUtils.h"
#include "Camera/CameraActor.h"
#include "GameFramework/PlayerController.h"
#include "fGameFlow.generated.h"

UCLASS()
class FIVE_API AfGameFlow : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AfGameFlow();

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(BlueprintReadOnly, Category = "State")
	UfGameState* GameState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Players")
	TArray<AfGamePawn*> Players;
	
	UFUNCTION(BlueprintCallable, Category = "Game")
	void BeginGame();

	UFUNCTION(BlueprintCallable, Category = "Game")
	void EndGame();

	void ClearExistingPlayers();


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void UpdateState(EGameState State);
	
};
