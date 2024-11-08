// Fill out your copyright notice in the Description page of Project Settings.


#include "fEcoTile.h"

// Sets default values
AfEcoTile::AfEcoTile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = StaticMeshComponent;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Main/Assets/Model/EcoBase.EcoBase"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComponent->SetStaticMesh(MeshAsset.Object);
	}

}

// Called when the game starts or when spawned
void AfEcoTile::BeginPlay()
{
	Super::BeginPlay();
	
}



