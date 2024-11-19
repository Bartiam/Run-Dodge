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

	// The best time in endless mode
	float firstLevelBestTime = 0.f;

public: // Getters and Setters

	// Getter the best time in endless mode
	UFUNCTION()
	float GetFirstLevelBestTime() const;

	// Setter the best time in endless mode
	UFUNCTION()
	void SetFirstLevelBestTime(const float& newTime);
};
