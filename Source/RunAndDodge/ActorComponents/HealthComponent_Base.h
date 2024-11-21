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

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private: // Private functions

	void ChangeCanRegenerationHealth();

private: // Private variable for this actor component
	
	float currentHealth = 0.f;

	FTimerHandle timerForBeginRegeneration;

	float NumberWhichHealthDecrease = 0.f;

	bool bIsCanRegeneration = false;

	class ARADCastleGameMode_Base* gameMode = nullptr;

	class ARADCharacter_Base* characterOwner = nullptr;

public: // Getters and setters for this actor component

	// Getter and setter current health
	UFUNCTION()
	void SetCurrentHealth(const float& newHealth);
	UFUNCTION()
	float GetCurrentHealth() const;

public: // Public variables

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float defaultHealth = 100.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Health")
	float timeToStartRegeneration = 0.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Health")
	float increaseHealth = 0.f;

public: // Public functions

	UFUNCTION()
	void TakeDamageHealth(AActor* damageActor, float damage, const UDamageType* damageType, AController* instigateBy, AActor* damageCauser);
	UFUNCTION()
	void HealthRegeneration();
};
