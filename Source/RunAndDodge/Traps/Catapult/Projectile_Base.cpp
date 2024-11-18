// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile_Base.h"

#include "Components/StaticMeshComponent.h"

// Sets default values
AProjectile_Base::AProjectile_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create projectile
	projectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName(TEXT("Projectile")));
	projectileMesh->SetCollisionProfileName(FName(TEXT("PhysicsActor")));
	projectileMesh->SetSimulatePhysics(true);
	// Set root component
	SetRootComponent(projectileMesh);
}

// Called when the game starts or when spawned
void AProjectile_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile_Base::InitProjectile(const FVector& projectileScale, const float& projectileDamage)
{
	SetLifeSpan(lifeSpan);
	SetActorScale3D(projectileScale);
	damage = projectileDamage;
}

