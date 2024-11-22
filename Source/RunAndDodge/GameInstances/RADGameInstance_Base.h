﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "../FunctionLib/MyTypes_Base.h"
#include "../Savers/Saver_Base.h"

#include "RADGameInstance_Base.generated.h"

class USaver_Base;

UCLASS()
class RUNANDDODGE_API URADGameInstance_Base : public UGameInstance
{
	GENERATED_BODY()

private: // Private virables

	FString profileName = FString(TEXT("ProfileOne"));
	int indexLevel = 0;

	TArray<FString> levelNames = { FString(TEXT("Вход в замок")) };
	TArray<float> levelBestTimes = { 0.f };

public: // Getters and Setters

	// Getter the best time
	UFUNCTION()
	float GetTheBestLevelTime() const;

	// Setter the best time
	UFUNCTION()
	void SetTheBestLevelTime(const float& newTime);

	// Getter name current level
	UFUNCTION()
	FString GetNameCurrentLevel();

	// Setter index current level
	UFUNCTION(BlueprintCallable)
	void SetIndexLevel(int newIndex);

public: // Public variables

	UPROPERTY(BlueprintReadWrite)
	bool bIsNewRecord = false;

public: // Public functions

	UFUNCTION(BlueprintCallable)
	void SaveRADGame();

	UFUNCTION(BlueprintCallable)
	void LoadRADGame();
};
