// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Saver_Base.generated.h"


UCLASS()
class RUNANDDODGE_API USaver_Base : public USaveGame
{
	GENERATED_BODY()

public: // Public variables to save

	UPROPERTY(SaveGame)
	TArray<int> theBestLevelTimes;

	UPROPERTY(SaveGame)
	float sensitivity;

	UPROPERTY(SaveGame)
	bool bIsLearningEnabled;

	UPROPERTY(SaveGame)
	float musicVolume;
};
