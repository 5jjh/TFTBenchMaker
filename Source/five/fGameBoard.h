// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "fGameTile.h"
#include "fBenchTile.h"
#include "fEcoTile.h"
#include "GameFramework/Actor.h"
#include "fGameBoard.generated.h"

UCLASS()
class FIVE_API AfGameBoard : public AActor
{
	GENERATED_BODY()


	
public:	
	// Sets default values for this actor's properties
	AfGameBoard();


protected:
	UPROPERTY(EditDefaultsOnly, BluePrintReadOnly, Category = "Tiles")
	TSubclassOf<AfGameTile> TileClass = AfGameTile::StaticClass();

	UPROPERTY(EditDefaultsOnly, BluePrintReadOnly, Category = "Tiles")
	TSubclassOf<AfBenchTile> BenchTileClass = AfBenchTile::StaticClass();
	
	UPROPERTY(EditDefaultsOnly, BluePrintReadOnly, Category = "Tiles")
	TSubclassOf<AfEcoTile> EcoTileClass = AfEcoTile::StaticClass();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<AfGameTile*> TileBoard;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<AfBenchTile*> TileBench;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<AfBenchTile*> EnemyTileBench;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<AfEcoTile*> TileEco;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<AfEcoTile*> EnemyTileEco; 

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void CreateBoard(int PlayerNumber);

};
