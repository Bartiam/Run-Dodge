// Fill out your copyright notice in the Description page of Project Settings.


#include "Catapult_Base.h"
#include "Projectile_Base.h"

#include "Components/SkeletalMeshComponent.h"
#include "Components/PrimitiveComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Kismet/KismetMathLibrary.h"

#include "Animation/AnimMontage.h"

// Sets default values
ACatapult_Base::ACatapult_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Create skeletal mesh
	skeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(FName(TEXT("Skeletal mesh")));
	SetRootComponent(skeletalMesh);
	skeletalMesh->SetCollisionProfileName(FName(TEXT("BlockAll")));
	// Create physics handle
	physicsHandle = CreateDefaultSubobject<UPhysicsHandleComponent>(FName(TEXT("Physics handle")));
}

// Called when the game starts or when spawned
void ACatapult_Base::BeginPlay()
{
	Super::BeginPlay();
	GetDirectionTurn();
	skeletalMesh->PlayAnimation(catapultSettings.shotAnimation, true);
}

// Called every frame
void ACatapult_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACatapult_Base::ShotCatapult()
{
	physicsHandle->ReleaseComponent();
	float currentForwardPower = UKismetMathLibrary::RandomFloatInRange(catapultSettings.minThrowForwardPower, catapultSettings.maxThrowForwardPower);
	float currentThrowUpPower = UKismetMathLibrary::RandomFloatInRange(catapultSettings.minThrowUpPower, catapultSettings.maxThrowUpPower);
	auto vectorImpulse = FVector(GetActorForwardVector().X * currentForwardPower, GetActorForwardVector().Y * currentForwardPower, GetActorForwardVector().Z + currentThrowUpPower);
	projectile->projectileMesh->AddImpulse(vectorImpulse);

	GetDirectionTurn();
}

void ACatapult_Base::ReloadCatapult()
{
	// Get position to spawn rock
	auto positionOfSocket = skeletalMesh->GetSocketLocation(FName(TEXT("ArmSocket")));
	// Create new projectile to shot
	projectile = GetWorld()->SpawnActor<AProjectile_Base>(catapultSettings.projectileClass, FTransform(positionOfSocket));
	// Init
	projectile->InitProjectile(catapultSettings.projectileScale, catapultSettings.projectileDamage);
	// grab projectile to arm bone
	physicsHandle->GrabComponentAtLocation(projectile->projectileMesh, FName(TEXT("Arm")), positionOfSocket);
}

void ACatapult_Base::RotateCatapult()
{
	if (bIsTurnPositiveOrNegative)
	{
		currentRotateNumber += 1;
		FRotator newRotation = FRotator(GetActorRotation().Pitch, GetActorRotation().Yaw + 1, GetActorRotation().Roll);
		SetActorRotation(newRotation);
	}
	else
	{
		currentRotateNumber -= 1;
		FRotator newRotation = FRotator(GetActorRotation().Pitch, GetActorRotation().Yaw - 1, GetActorRotation().Roll);
		SetActorRotation(newRotation);
	}

	if (currentRotateNumber % 5 == 0)
	{
		GetWorldTimerManager().ClearTimer(timerToRotateCatapult);
	}
}

void ACatapult_Base::GetDirectionTurn()
{
	bIsTurnPositiveOrNegative = UKismetMathLibrary::RandomBool();

	if (currentRotateNumber == 30) bIsTurnPositiveOrNegative = false;
	if (currentRotateNumber == -30) bIsTurnPositiveOrNegative = true;

	GetWorldTimerManager().SetTimer(timerToRotateCatapult, this, &ACatapult_Base::RotateCatapult, 0.1f, true);
}
