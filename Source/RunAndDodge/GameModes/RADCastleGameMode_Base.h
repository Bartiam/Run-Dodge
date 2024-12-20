﻿// Fill out your copyright notice in the Description page of Project Settings.

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

public: // Public variables

	class ARADCharacter_Base* character = nullptr;

	// Bolt which swapn in objects
	TSubclassOf<class ABolt_Base> boltClass;

	// The life of objects in the world
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Lifetime objects")
	float lifeSpanObjects = 0.f;

	bool bIsGameOver;
	bool bIsWonLevel;

public: // Public functions

	// Spawn object in object
	UFUNCTION()
	void SpawnObjectInObject(ABolt_Base* hitActor, AActor* otherHitActor);

	UFUNCTION(BlueprintCallable)
	void StartGame();

	UFUNCTION()
	void GameOver();

	UFUNCTION()
	void WonLevel();

private: // Private variables

	UPROPERTY()
	class ARADCastleGameState_Base* RADGameState = nullptr;
};
