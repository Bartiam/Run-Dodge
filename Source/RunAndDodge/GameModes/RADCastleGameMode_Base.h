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

public: // Public variables

	// Bolt which swapn in objects
	TSubclassOf<class ABolt_Base> boltClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Lifetime objects")
	float lifeSpanObjects = 0.f;

public: // Public functions

	// Spawn object in object
	UFUNCTION()
	void SpawnObjectInObject(AActor* hitActor, AActor* otherHitActor);

};
