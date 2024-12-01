// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "../../FunctionLib/MyTypes_Base.h"

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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Catapult settings")
	FCatapultSpecification catapultSettings;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private: // Private variables

	// Variable for grab and throw object
	class UPhysicsHandleComponent* physicsHandle = nullptr;

	// Projectile
	class AProjectile_Base* projectile = nullptr;

	FTimerHandle timerToRotateCatapult;

	// The number by which the catapult has already turned
	int8 currentRotateNumber = 0.f;

	// Is the rotation positive or negative
	bool bIsTurnPositiveOrNegative = false;

	// The maximum possible turn
	const int8 maxTurnCatapult = 30;
	// The minimum possible turn
	const int8 minTurnCatapult = -30;

	UAudioComponent* shotAudioComponent = nullptr;
	UAudioComponent* reloadAudioComponent = nullptr;

public: // Public functions

	// Releases the object giving it a boost
	UFUNCTION(BlueprintCallable)
	void ShotCatapult();

	// Capturing an object and moving it in space
	UFUNCTION(BlueprintCallable)
	void ReloadCatapult();

	UFUNCTION(BlueprintCallable)
	void PlaySoundDuringShot();

private: // Private functions

	// Turns the catapult after firing
	UFUNCTION()
	void RotateCatapult();

	// Gets the direction to turn
	UFUNCTION()
	void GetDirectionTurn();
};
