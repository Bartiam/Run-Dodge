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
	TMap<FString, float> infoAboutLevels;
	// The best time in endless mode
	float firstLevelBestTime = 0.f;

	FString firstLevelName = FString(TEXT("Вход в замок"));

public: // Getters and Setters

	// Getter the best time
	UFUNCTION()
	float GetTheBestLevelTime() const;

	// Setter the best time
	UFUNCTION()
	void SetTheBestLevelTime(const float& newTime);

	// Getter name level
	FString GetNameCurrentLevel();

public: // Public variables

	bool bIsNewRecord = false;
};
