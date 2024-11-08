// Fill out your copyright notice in the Description page of Project Settings.


#include "fGamePawn.h"

// Sets default values
AfGamePawn::AfGamePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PlayerController = nullptr;
	GameBoard = nullptr;
	PlayerNumber = 0;

}



void AfGamePawn::SetPlayerNumber(int PlayerN)
{
	PlayerNumber = PlayerN;
}

int AfGamePawn::GetPlayerNumber()
{
	return PlayerNumber;
}




// Called to bind functionality to input
void AfGamePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

