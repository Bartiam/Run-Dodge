// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyTypes_Base.generated.h"


// A structure for storing character speed variables
USTRUCT(BlueprintType)
struct FCharacterSpeed
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement speed")
	float crounchSpeed = 150.f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement speed")
	float crounchRunSpeed = 300.f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement speed")
	float walkSpeed = 300.f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement speed")
	float simpleRunSpeed = 500.f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement speed")
	float sprintSpeed = 900.f;
};

UENUM(BlueprintType)
enum class EMovementState : uint8
{
	CROUNCH UMETA(DisplayName = "Crounch state"),
	CROUNCH_RUN UMETA(DisplayName = "Crounch run state"),
	WALK UMETA(DisplayName = "Walk state"),
	SIMPLE_RUN UMETA(DisplayName = "Simple run state"),
	SPRINT UMETA(DisplayName = "Sprint state")
};

UCLASS()
class RUNANDDODGE_API UMyTypes_Base : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
};
