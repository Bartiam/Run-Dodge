// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "RADCastleGameState_Base.generated.h"

UCLASS()
class RUNANDDODGE_API ARADCastleGameState_Base : public AGameStateBase
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;

private: // Private variables

	class USaver_Base* RADSaver = nullptr;

	FTimerHandle timeElapsedSinceBeginLevel;

	float currentTime = 0.f;

	UPROPERTY()
	class ARAD_PlayerController_Base* playerController = nullptr;

	UPROPERTY()
	class URADGameInstance_Base* gameInstance = nullptr;

	UPROPERTY()
	class ARADCharacter_Base* character = nullptr;

	UPROPERTY()
	class ARADCastleGameMode_Base* gameMode = nullptr;

private: // Private functions

	UFUNCTION()
	void SetCurrentTimeSinceBeginLevel();

public: // Public functions

	// return elapes time since begin play
	UFUNCTION()
	float GetCurrentTimeSinceBeginLevel() const;

	UFUNCTION()
	void StartGame();

	UFUNCTION()
	void GameOver();

	UFUNCTION()
	void WonLevel();
};
