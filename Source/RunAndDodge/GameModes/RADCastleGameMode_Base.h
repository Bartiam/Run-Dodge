// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RADCastleGameMode_Base.generated.h"

class URADGameInstance_Base;

UCLASS()
class RUNANDDODGE_API ARADCastleGameMode_Base : public AGameModeBase
{
	GENERATED_BODY()

	URADGameInstance_Base* gameInstance;
	
protected:
	virtual void BeginPlay() override;

};
