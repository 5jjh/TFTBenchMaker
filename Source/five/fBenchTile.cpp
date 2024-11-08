// Fill out your copyright notice in the Description page of Project Settings.


#include "fBenchTile.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h" // Include the header for static mesh


// Sets default values
AfBenchTile::AfBenchTile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = StaticMeshComponent;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Main/Assets/Model/TileBench.TileBench"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComponent->SetStaticMesh(MeshAsset.Object);
	}

	StaticMeshComponent->SetWorldScale3D(FVector(0.8f, 0.8f, 0.8f));

}

// Called when the game starts or when spawned
void AfBenchTile::BeginPlay()
{
	Super::BeginPlay();
	
}



