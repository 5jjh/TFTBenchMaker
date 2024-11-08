// Fill out your copyright notice in the Description page of Project Settings.


#include "fPlayerController.h"


AfPlayerController::AfPlayerController()
{
	static ConstructorHelpers::FClassFinder<UfShopWidget> ShopWidgetBPClass(TEXT("/Game/Main/Assets/BP/WBP_Shop.WBP_Shop"));
	FSoftClassPath ShopWidgetClassRef(TEXT("/Game/Main/Assets/BP/WBP_Shop.WBP_Shop_C"));
	if (UClass* WidgetClass = ShopWidgetClassRef.TryLoadClass<UUserWidget>())
	{
		UE_LOG(LogTemp, Warning, TEXT("HERE"));
		ShopWidgetClass = WidgetClass;
	}
}



void AfPlayerController::InitializeShopWidget()
{
	UE_LOG(LogTemp, Warning, TEXT("HERE1"));
	if (ShopWidgetClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("HERE2"));
		ShopWidget = CreateWidget<UfShopWidget>(this, ShopWidgetClass);
		if (ShopWidget)  
		{
			UE_LOG(LogTemp, Warning, TEXT("HERE3"));
			ShopWidget->AddToViewport();
			FVector2D ViewPortSize = FVector2D(GetWorld()->GetGameViewport()->Viewport->GetSizeXY());
			FVector2D WidgetSize = ShopWidget->GetDesiredSize();
			FVector2D DesiredPosition = FVector2D((ViewPortSize.X - WidgetSize.X) / 2, ViewPortSize.Y - WidgetSize.Y);
			ShopWidget->SetPositionInViewport(DesiredPosition);
			
		}
	}
}

UfShopWidget* AfPlayerController::GetShopWidget()
{
	return ShopWidget;
}

