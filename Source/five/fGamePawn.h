// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "fPlayerController.h"
#include "fGameBoard.h"
#include "fShopWidget.h"
#include "GameFramework/Pawn.h"
#include "fGamePawn.generated.h"

UCLASS()
class FIVE_API AfGamePawn : public APawn
{
	GENERATED_BODY()

public:
	AfGamePawn();



public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Board")
	AfGameBoard* GameBoard;

	void SetPlayerNumber(int PlayerN);

	int GetPlayerNumber();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY()
	UfShopWidget* ShopWidget;
	
	
	AfPlayerController* PlayerController;
	

private:
	int PlayerNumber;
};
