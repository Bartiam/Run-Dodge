// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile_Base.h"

#include "Components/StaticMeshComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Components/SphereComponent.h"

#include "Kismet/GameplayStatics.h"

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
	// Create overlap collision
	overlapCollision = CreateDefaultSubobject<USphereComponent>(FName(TEXT("Overlap collision")));
	overlapCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	overlapCollision->SetCollisionResponseToAllChannels(ECR_Overlap);
	overlapCollision->SetupAttachment(RootComponent);

	Tags.Add(FName(TEXT("Projectile")));
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

	// Adding an event hit trigger
	overlapCollision->OnComponentBeginOverlap.AddDynamic(this, &AProjectile_Base::HandleBeginOverlap);
}

void AProjectile_Base::HandleBeginOverlap(UPrimitiveComponent* hitComponent, AActor* otherActorHit,
	UPrimitiveComponent* otherHitComponent, int32 indesOtherActor, bool bFromSweep, const FHitResult& hitResult)
{
	if (otherActorHit->ActorHasTag(FName(TEXT("Player"))))
	{
		UGameplayStatics::ApplyDamage(otherActorHit, damage, GetInstigatorController(), this, damageTypeClass);
	}

	if (!otherActorHit->ActorHasTag(FName(TEXT("Crossbow"))) && !otherActorHit->ActorHasTag(FName(TEXT("Projectile"))))
	{
		damage -= 50.f;
		if (damage <= 0.f)
			damage = 0.f;
	}
}