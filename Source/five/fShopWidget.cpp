// Fill out your copyright notice in the Description page of Project Settings.


#include "fShopWidget.h"
#include "Components/Button.h"

UfShopWidget::UfShopWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	
}


void UfShopWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (PurchaseButton)
	{
		PurchaseButton->OnClicked.AddDynamic(this, &UfShopWidget::OnPurchaseClick);
	}

	if (RefreshButton)
	{
		RefreshButton->OnClicked.AddDynamic(this, &UfShopWidget::OnRefreshClick);
	}

	if (LevelButton)
	{
		LevelButton->OnClicked.AddDynamic(this, &UfShopWidget::OnLevelClick);
	}
}


void UfShopWidget::OnPurchaseClick()
{
	UE_LOG(LogTemp, Warning, TEXT("PurchaseButton was clicked"));
}

void UfShopWidget::OnRefreshClick()
{
	UE_LOG(LogTemp, Warning, TEXT("RefreshButton was clicked"));
}

void UfShopWidget::OnLevelClick()
{
	UE_LOG(LogTemp, Warning, TEXT("LevelButton was clicked"));
}


