// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "../FunctionLib/MyTypes_Base.h"

#include "Saver_Base.generated.h"


UCLASS()
class RUNANDDODGE_API USaver_Base : public USaveGame
{
	GENERATED_BODY()

public: // Public variables to save

	TArray<float> theBestLevelTimes;

	FString saveProfileName = "MainProfile";
};
