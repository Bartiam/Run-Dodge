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

	float endlessModeBestTime = 0.f;

public: // Getters and Setters

	UFUNCTION()
	float GetEndlessModeBestTime() const;

	UFUNCTION()
	void SetEndlessModeBestTime(const float& newTime);
};
