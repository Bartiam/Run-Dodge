// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Catapult_Base.generated.h"

UCLASS()
class RUNANDDODGE_API ACatapult_Base : public AActor
{
	GENERATED_BODY()
	
public:	// Public variables
	ACatapult_Base();
	
	// Variable skeletal mesh use anim
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Catapult mesh")
	class USkeletalMeshComponent* skeletalMesh = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Catapult settings")
	TSubclassOf<class AProjectile_Base> projectileClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Catapult settings")
	class UAnimMontage* shotAnimation = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Catapult settings")
	float throwPower = 0.f;

	// Collisiton for looking character
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Looking collision")
	class UBoxComponent* LookingCollision = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private: // Private variables

	// Variable for grab and throw object
	class UPhysicsHandleComponent* physicsHandle = nullptr;
	// Anim instance for get current time animation
	class UAnimInstance* skeletalAnimInstance = nullptr;
	// Time to shot
	float startAnim = 0.f;
	// Time to reload
	float endAnim = 0.f;
	// Root component
	class USceneComponent* rootSceneComponent = nullptr;
	
	class AActor* character = nullptr;


private: // Private functions

	void ShotCatapult();

	// Capturing an object and moving it in space
	void ReloadCatapult();

	// Event when somebody begin overlap
	UFUNCTION()
	void HandleBeginOverlap(UPrimitiveComponent* overlappedComponent, AActor* otherActor, UPrimitiveComponent*
		otherComponent, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult);

	// Event when somebody end overlap
	UFUNCTION()
	void HandleEndOverlap(UPrimitiveComponent* overlappedComponent, AActor* otherActor, UPrimitiveComponent*
		otherComponent, int32 otherBodyIndex);
};
