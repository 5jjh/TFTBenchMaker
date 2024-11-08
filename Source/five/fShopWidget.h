// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "fShopWidget.generated.h"

/**
 * 
 */
UCLASS()
class FIVE_API UfShopWidget : public UUserWidget
{
	GENERATED_BODY()


public:

	UfShopWidget(const FObjectInitializer& ObjectInitializer);
	
	virtual void NativeConstruct() override;
	
protected:
	UPROPERTY(meta = (BindWidget))
	class UButton* PurchaseButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* RefreshButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* LevelButton;

private:
		UFUNCTION()
		void OnPurchaseClick();

		UFUNCTION()
		void OnRefreshClick();

		UFUNCTION()
		void OnLevelClick();
};
