// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RADCastleGameMode_Base.generated.h"



UCLASS()
class RUNANDDODGE_API ARADCastleGameMode_Base : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

private:
	// Устновка настроек для текущего Game mode
	void SetupSettingsForGameMode();
};
