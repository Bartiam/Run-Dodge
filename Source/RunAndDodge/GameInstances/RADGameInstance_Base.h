// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "RADGameInstance_Base.generated.h"

UCLASS()
class RUNANDDODGE_API URADGameInstance_Base : public UGameInstance
{
	GENERATED_BODY()

private: // Private virables

	float theBestTime = 0.f;

public: // Getters and Setters

	UFUNCTION()
	float GetTheBestTime() const;

	UFUNCTION()
	void SetTheBestTime(const float& newTime);
};
