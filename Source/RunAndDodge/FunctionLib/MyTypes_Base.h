// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyTypes_Base.generated.h"

class AShell_Base;

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
struct FShellSpecification
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Bolt settings")
	float shellDamage = 0.f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Bolt settings")
	float shellSpeed = 0.f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Bolt settings")
	FVector shellScale;
};

// Structure for crossbow settings
USTRUCT(BlueprintType)
struct FCrossbowSpecification
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Crossbow settings")
	float timeBeforeShoot = 0.f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Crossbow settings")
	float timeReload = 0.f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Crossbow settings")
	TSubclassOf<AShell_Base> shellClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Crossbow settings")
	FShellSpecification shellSettings;
};

UCLASS()
class RUNANDDODGE_API UMyTypes_Base : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

};
