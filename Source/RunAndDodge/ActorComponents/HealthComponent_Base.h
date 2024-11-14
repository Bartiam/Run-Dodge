// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent_Base.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RUNANDDODGE_API UHealthComponent_Base : public UActorComponent
{
	GENERATED_BODY()

public:	
	UHealthComponent_Base();
	// Sets default public values for this component's properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float defaultHealth = 100.f;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	// Private variable for this actor component
	float currentHealth = 0.f;

	FTimerHandle timerForBeginRegeneration;

public: // Getters and setters for this actor component

	// Getter and setter current health
	UFUNCTION()
	void SetCurrentHealth(const float& newHealth);
	UFUNCTION()
	float GetCurrentHealth() const;

public: // Public functions

	UFUNCTION()
	void TakeDamageHealth(const float& damage);
	UFUNCTION()
	void HealthRegeneration();
};
