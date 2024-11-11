// Fill out your copyright notice in the Description page of Project Settings.


#include "../../Traps/Crossbow/Crossbow_Base.h"

#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
ACrossbow_Base::ACrossbow_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Create crossbow
	crossbow = CreateDefaultSubobject<UStaticMeshComponent>(FName(TEXT("Crossbow")));
	// Disable collision
	crossbow->SetCollisionProfileName(FName(TEXT("NoCollision")));
	// Set root component
	SetRootComponent(crossbow);
	// Create looking collision
	LookingCollision = CreateDefaultSubobject<UBoxComponent>(FName(TEXT("Box collision")));
	LookingCollision->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACrossbow_Base::BeginPlay()
{
	Super::BeginPlay();
	SpawnBolt();
}

// Called every frame
void ACrossbow_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACrossbow_Base::SpawnBolt()
{
	auto newBolt = GetWorld()->SpawnActor<UStaticMeshComponent>(boltClass, FTransform(positionToSpawnBolt));
}

