// Fill out your copyright notice in the Description page of Project Settings.


#include "fGameState.h"


UfGameState::UfGameState()
{
	CurrentState = EGameState::Carousel;
	CurrentPhase = 0;
}

void UfGameState::SetGameState(const EGameState State)
{
	if (CurrentState != State)
	{
		CurrentState = State;
		CurrentPhase += 1;
		UpdateCamera();
		
	}
}

void UfGameState::UpdateCamera() const
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PlayerController)
	{
		if (CurrentState == EGameState::Carousel)
		{
			PlayerController->SetViewTarget(CarouselCamera);
		}

		else if (CurrentState == EGameState::PostCombat && CurrentPhase == 5)
		{
			PlayerController->SetViewTarget(BoardCamera);
		}
	}
}


