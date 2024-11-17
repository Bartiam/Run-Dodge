// Fill out your copyright notice in the Description page of Project Settings.


#include "Catapult_Base.h"
#include "Projectile_Base.h"

#include "Components/SkeletalMeshComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"

#include "Animation/AnimMontage.h"
#include "Animation/AnimInstance.h"

// Sets default values
ACatapult_Base::ACatapult_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Create root component
	rootSceneComponent = CreateDefaultSubobject<USceneComponent>(FName(TEXT("Root Component")));
	SetRootComponent(rootSceneComponent);
	// Create skeletal mesh
	skeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(FName(TEXT("Skeletal mesh")));
	skeletalMesh->SetupAttachment(RootComponent);
	skeletalMesh->SetCollisionProfileName(FName(TEXT("BlockAll")));
	// Create physics handle
	physicsHandle = CreateDefaultSubobject<UPhysicsHandleComponent>(FName(TEXT("Physics handle")));
	// Create looking collision
	LookingCollision = CreateDefaultSubobject<UBoxComponent>(FName(TEXT("Looking collision")));
	LookingCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	LookingCollision->SetCollisionResponseToAllChannels(ECR_Overlap);
	LookingCollision->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACatapult_Base::BeginPlay()
{
	Super::BeginPlay();
	ReloadCatapult();
}

// Called every frame
void ACatapult_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	LookingCollision->OnComponentBeginOverlap.AddDynamic(this, &ACatapult_Base::HandleBeginOverlap);
	LookingCollision->OnComponentEndOverlap.AddDynamic(this, &ACatapult_Base::HandleEndOverlap);
}

void ACatapult_Base::ShotCatapult()
{

}

void ACatapult_Base::ReloadCatapult()
{
	// Get position to spawn rock
	auto positionOfSocket = skeletalMesh->GetSocketLocation(FName(TEXT("ArmSocket")));
	// Create new projectile to shot
	auto newProjectile = GetWorld()->SpawnActor<AProjectile_Base>(projectileClass, FTransform(positionOfSocket));
	// grab projectile to arm bone
	physicsHandle->GrabComponentAtLocation(newProjectile->projectileMesh, FName(TEXT("Arm")), positionOfSocket);
}

void ACatapult_Base::HandleBeginOverlap(UPrimitiveComponent* overlappedComponent, AActor* otherActor,
	UPrimitiveComponent* otherComponent, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult)
{
	if (otherActor->ActorHasTag(FName(TEXT("Player"))))
	{
		character = otherActor;
	}
}

void ACatapult_Base::HandleEndOverlap(UPrimitiveComponent* overlappedComponent,
	AActor* otherActor, UPrimitiveComponent* otherComponent, int32 otherBodyIndex)
{
	if (otherActor->ActorHasTag(FName(TEXT("Player"))))
		character = nullptr;
}