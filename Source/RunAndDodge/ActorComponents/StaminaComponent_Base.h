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

private:
	// Private variables for this actor component
	UPROPERTY()
	float currentStamina = 0.f;

public: // Getters and setters for this actor component
	// Getter and setter for stamina
	UFUNCTION()
	void SetCurrentStamina(const float& newStamina);
	UFUNCTION()
	float GetCurrentStamina() const;
};
