// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RADCastleGameMode_Base.generated.h"

class URADGameInstance_Base;
class UGameUserSettings;

UCLASS()
class RUNANDDODGE_API ARADCastleGameMode_Base : public AGameModeBase
{
	GENERATED_BODY()

private:
	UPROPERTY()
	URADGameInstance_Base* gameInstance;
	UPROPERTY()
	UGameUserSettings* userSettings;
	
protected:
	virtual void BeginPlay() override;


private:
	// Set graphic option
	UFUNCTION()
	void SetGraphicOption();
};
