// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spike_Base.generated.h"

class UBoxComponent;

UCLASS()
class RUNANDDODGE_API ASpike_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpike_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private: // Private variables

	TSubclassOf<UDamageType> damageTypeClass;

	FTimerHandle timerToRiseUp;

	FTimerHandle timerToRiseDown;

public: // Public variables

	// What the spikes will look like
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class UStaticMeshComponent* spikeMesh = nullptr;
	// Deals damage when it comes into contact with a character
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UBoxComponent* damageCollision = nullptr;
	// Reacts to the character when it is stepped on
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UBoxComponent* checkCollision = nullptr;

	// Damage spike
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	float damage = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	float raisUpByZ = 0.f;

private: // Private functions

	UFUNCTION()
	void DamageBeginOverlap(UPrimitiveComponent* hitComponent, AActor* otherActor,
		UPrimitiveComponent* otherHitComponent, int32 indexOtherActor, bool bFromSweep, const FHitResult& hitResult);

	UFUNCTION()
	void CheckBeginOverlap(UPrimitiveComponent* hitComponent, AActor* otherActor,
		UPrimitiveComponent* otherHitComponent, int32 indexOtherComponent, bool bIsFromSweep, const FHitResult& hitResult);

	UFUNCTION()
	void RiseUpSpike();

	UFUNCTION()
	void RiseDownSpike();

};
