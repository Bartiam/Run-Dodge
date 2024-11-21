// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelFinish_Base.generated.h"

class UStaticMeshComponent;

UCLASS()
class RUNANDDODGE_API ALevelFinish_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelFinish_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private: // Private variables

	class USceneComponent* rootComponent = nullptr;

public: // Public variables

	// Gate meshes
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Crossbow")
	UStaticMeshComponent* gateArch = nullptr;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Crossbow")
	UStaticMeshComponent* leftGate = nullptr;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Crossbow")
	UStaticMeshComponent* rightGate = nullptr;
	// overlap collision
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Crossbow")
	class UBoxComponent* overlapCollision = nullptr;


private: // Private finctions

	UFUNCTION()
	void FinishLevel(UPrimitiveComponent* overlapComp, AActor* otherActor, 
		UPrimitiveComponent* otherComp, int32 indexActor, bool bIsSweep, const FHitResult& hitResult);
};
