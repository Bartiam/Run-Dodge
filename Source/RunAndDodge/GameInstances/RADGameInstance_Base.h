// Fill out your copyright notice in the Description page of Project Settings.

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

	FString profileName = FString(TEXT("MainProfile"));
	int indexLevel = 0;

	// Save variables //
	float currentSensitivity = 100.f;
	TArray<int> levelBestTimes = { 0 };
	bool bIsLearningEnabled = true;
	// =================================== //

	TArray<FString> levelNames = { FString(TEXT("Вход в замок")) };

public: // Getters and Setters

	// Getter current sensitivity
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetCurrentSensitivity() const;

	// Setter current sensitivity
	UFUNCTION(BlueprintCallable)
	void SetCurrentSensitivity(float newSensitivity);

	// Getter the best time
	UFUNCTION()
	int GetTheBestLevelTime() const;

	// Setter the best time
	UFUNCTION()
	void SetTheBestLevelTime(const int& newTime);

	// Getter name current level
	UFUNCTION()
	FString GetNameCurrentLevel();

	// Setter index current level
	UFUNCTION(BlueprintCallable)
	void SetIndexLevel(int newIndex);

	// Getter learning enabled
	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool GetLearningEnabled() const;

	// Setter learning enabled
	UFUNCTION(BlueprintCallable)
	void SetLearningEnabled(bool bIsEnabled);

public: // Public variables

	UPROPERTY(BlueprintReadWrite)
	bool bIsNewRecord = false;

public: // Public functions

	UFUNCTION(BlueprintCallable)
	void SaveRADGame();

	UFUNCTION(BlueprintCallable)
	void LoadRADGame();
};
