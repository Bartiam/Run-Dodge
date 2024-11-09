// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "RADCastleCameState_Base.generated.h"

UCLASS()
class RUNANDDODGE_API ARADCastleCameState_Base : public AGameStateBase
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

private:
	FTimerHandle timeElapsedSinceBeginLevel;

	float currentTime = 0.f;

	UFUNCTION()
	void SetCurrentTimeSinceBeginLevel();

public: // Public functions

	// return elapes time since begin play
	UFUNCTION()
	float GetCurrentTimeSinceBeginLevel() const;

};
