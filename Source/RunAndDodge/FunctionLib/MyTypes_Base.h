// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyTypes_Base.generated.h"

class ABolt_Base;
class AProjectile_Base;

// State machine for movement character
UENUM(BlueprintType)
enum class EMovementState : uint8
{
	CROUCH UMETA(DisplayName = "Crounch state"),
	FAST_CROUCH UMETA(DisplayName = "Crounch run state"),
	WALK UMETA(DisplayName = "Walk state"),
	SIMPLE_RUN UMETA(DisplayName = "Simple run state"),
	SPRINT UMETA(DisplayName = "Sprint state")
};

// A structure for storing character speed variables
USTRUCT(BlueprintType)
struct FCharacterSpeed
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement speed")
	float crouchSpeed = 150.f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement speed")
	float fastCrouchSpeed = 300.f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement speed")
	float walkSpeed = 300.f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement speed")
	float simpleRunSpeed = 500.f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement speed")
	float sprintSpeed = 900.f;
};

// Structure for bolt settings
USTRUCT(BlueprintType)
struct FBoltSpecification
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Bolt settings")
	float boltDamage = 0.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Bolt settings")
	float boltSpeed = 0.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Bolt settings")
	FVector boltScale;
};

// Structure for crossbow settings
USTRUCT(BlueprintType)
struct FCrossbowSpecification
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Crossbow settings")
	float timeBeforeShoot = 0.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Crossbow settings")
	float timeReload = 0.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Crossbow settings")
	TSubclassOf<ABolt_Base> boltClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Crossbow settings")
	FBoltSpecification boltSettings;
};

// Structure for catapult settings
USTRUCT(BlueprintType)
struct FCatapultSpecification
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Catapult settings")
	TSubclassOf<AProjectile_Base> projectileClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Catapult settings")
	float minThrowForwardPower = 0.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Catapult settings")
	float maxThrowForwardPower = 0.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Catapult settings")
	float minThrowUpPower = 0.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Catapult settings")
	float maxThrowUpPower = 0.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Catapult settings")
	class UAnimMontage* shotAnimation = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Catapult settings")
	FVector projectileScale = FVector::Zero();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Catapult settings")
	float projectileDamage = 0.f;
};

UCLASS()
class RUNANDDODGE_API UMyTypes_Base : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

};
