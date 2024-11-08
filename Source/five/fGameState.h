// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "fGameBoard.h"
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"
#include "fGameState.generated.h"


UENUM(BlueprintType)
enum class EGameState : uint8
{
	Carousel UMETA(DisplayName = "Carousel"),
	PVE UMETA(DisplayName = "PVE"),
	Augment UMETA(DisplayName = "Augment"),
	PVP UMETA(DisplayName = "PVP"),
	PreCombat UMETA(DisplayName = "Pre Combat"),
	PostCombat UMETA(DisplayName = "Post Combat")
};

/**
 * 
 */
UCLASS(Blueprintable)
class FIVE_API UfGameState : public UObject
{
	GENERATED_BODY()
	
public:
	UfGameState();
	
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EGameState CurrentState;

	UPROPERTY(BlueprintReadOnly, Category = "Phase")
	int CurrentPhase; 
	
	UFUNCTION(BlueprintCallable, Category = "State")
	void SetGameState(const EGameState State);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cameras")
	ACameraActor* CarouselCamera;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cameras")
	ACameraActor* BoardCamera;



private:
	void UpdateCamera() const;
};
