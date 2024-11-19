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

private:

	FTimerHandle timeElapsedSinceBeginLevel;

	float currentTime = 0.f;

	UFUNCTION()
	void SetCurrentTimeSinceBeginLevel();

	UPROPERTY()
	class ARAD_PlayerController_Base* playerController = nullptr;

	UPROPERTY()
	class URADGameInstance_Base* gameInstance = nullptr;

	UPROPERTY()
	class ARADCharacter_Base* character = nullptr;

public: // Public functions

	// return elapes time since begin play
	UFUNCTION()
	float GetCurrentTimeSinceBeginLevel() const;

	UFUNCTION()
	void StartGame();

	UFUNCTION()
	void EndGame();

public: // Public variables

	UPROPERTY()
	bool bIsGameEnded = false;
};
