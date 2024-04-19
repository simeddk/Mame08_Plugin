// Fill out your copyright notice in the Description page of Project Settings.


#include "CMeshActor_Copied.h"

// Sets default values
ACMeshActor_Copied::ACMeshActor_Copied()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ACMeshActor_Copied::OnConstruction(const FTransform& Transform)
{
}

void ACMeshActor_Copied::SetPositions(const TArray<FVector>& InPositions)
{
}

void ACMeshActor_Copied::SetIndices(const TArray<int32>& InIndices)
{
}

void ACMeshActor_Copied::SetNormals(const TArray<FVector>& InNormals)
{
}

void ACMeshActor_Copied::SetUVs(const TArray<FVector2D>& InUVs)
{
}

void ACMeshActor_Copied::SetColors(const TArray<FColor>& InColors)
{
}

// Called when the game starts or when spawned
void ACMeshActor_Copied::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACMeshActor_Copied::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

