// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StaminaComponent_Base.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RUNANDDODGE_API UStaminaComponent_Base : public UActorComponent
{
	GENERATED_BODY()

public:	
	UStaminaComponent_Base();

	// Sets default variables for this component's properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stamina")
	float defaultStamina = 100.f;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public: // public variables 

	// Variables for calculate stamina
	bool bIsCanIncreaseStamina = false;
	bool bIsStartsTimerToIncreaseStamina = false;

	FTimerHandle timerToAugmentStamina;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Stamina")
	float decreaseStamina = 1.f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Stamina")
	float increaseStamina = 1.f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Stamina")
	float recoveryFromTired = 40.f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Stamina")
	float timeToRecoverStamina = 0.5f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Stamina")
	float timeToRecoverStaminaAfterZero = 2.f;

	UPROPERTY()
	float numberWhichStaminaChanges = 0.f;

private: // Private variables for this actor component

	UPROPERTY()
	float currentStamina = 0.f;

	UPROPERTY()
	class ARADCharacter_Base* characterOwner;

public: // Getters and setters for this actor component

	// Getter and setter for current stamina
	UFUNCTION()
	void SetCurrentStamina(const float& newStamina);
	UFUNCTION()
	float GetCurrentStamina() const;

public: // public functions

	UFUNCTION()
	void ReduseStamina();

	UFUNCTION()
	void AugmentStamina();

private: // private functions

	UFUNCTION()
	void ChangeCanIncreaseStamina();
};
