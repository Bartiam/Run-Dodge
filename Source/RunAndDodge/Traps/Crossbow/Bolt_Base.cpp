// Fill out your copyright notice in the Description page of Project Settings.


#include "Bolt_Base.h"

#include "Components/BoxComponent.h"

// Sets default values
ABolt_Base::ABolt_Base()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create bolt mesh
	boltMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName(TEXT("Bolt")));
	SetRootComponent(boltMesh);
	boltMesh->SetCollisionProfileName(FName(TEXT("BlockAll")));
}

// Called when the game starts or when spawned
void ABolt_Base::BeginPlay()
{
	Super::BeginPlay();
	boltMesh->OnComponentHit.AddDynamic(this, &ABolt_Base::ComponentHitEvent);
}

// Called every frame
void ABolt_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bIsShoot)
		MovementBolt(DeltaTime);
}

void ABolt_Base::InitBoltSettings(const FBoltSpecification& boltInfo)
{
	boltSettings = boltInfo;
	SetActorScale3D(boltSettings.boltScale);
}

void ABolt_Base::MovementBolt(float deltaTime)
{
	float timeSpeed = boltSettings.boltSpeed * deltaTime;

	FVector currentDirection = GetActorForwardVector() * timeSpeed;
	AddActorWorldOffset(currentDirection, true);
}

void ABolt_Base::ComponentHitEvent(UPrimitiveComponent* hitComponent, AActor* otherActorHit,
	UPrimitiveComponent* otherHitComponent, FVector normalImpuls, const FHitResult& hitResult)
{
	
	
}

