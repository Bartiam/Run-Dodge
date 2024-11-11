// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Crossbow_Base.generated.h"

class UStaticMeshComponent;

UCLASS()
class RUNANDDODGE_API ACrossbow_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACrossbow_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// crossbow bolt
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Bolt")
	TSubclassOf<UStaticMeshComponent> boltClass;

	// crossbow mesh
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Crossbow")
	UStaticMeshComponent* crossbow = nullptr;

	// Position to spawn bolt
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Position to spawn bolt")
	FVector positionToSpawnBolt = FVector::Zero();

	// Collisiton for looking character
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Looking collision")
	class UBoxComponent* LookingCollision = nullptr;

	UFUNCTION()
	void SpawnBolt();
};
