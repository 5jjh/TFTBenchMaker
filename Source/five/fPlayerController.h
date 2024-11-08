// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "fShopWidget.h"
#include "Engine/GameViewportClient.h"
#include "GameFramework/PlayerController.h"
#include "fPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class FIVE_API AfPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AfPlayerController();

	void InitializeShopWidget();

	UfShopWidget* GetShopWidget();

	
protected:
	UPROPERTY()
	UfShopWidget* ShopWidget;

	UPROPERTY()
	TSubclassOf<UfShopWidget> ShopWidgetClass;
};
