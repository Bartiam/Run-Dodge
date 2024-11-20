// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "../FunctionLib/MyTypes_Base.h"

#include "RADCharacter_Base.generated.h"

class UHealthComponent_Base;
class UStaminaComponent_Base;
class UAnimMontage;

UCLASS()
class RUNANDDODGE_API ARADCharacter_Base : public ACharacter
{
	GENERATED_BODY()

public:
	ARADCharacter_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private: // Private variables

	bool bIsCharacterDied = false;

	// Character camera component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* springArm = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* camera = nullptr;

	// character movement state
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement state", meta = (AllowPrivateAccess = "true"))
	EMovementState currentMovementState;

	// Character updates movement speed
	UFUNCTION()
	void UpdateMovementSpeed();


public: // Getters and setters

	// Getter for health component
	UFUNCTION()
	const UHealthComponent_Base* GetHealthComponent() const;

	// Getter for stamina component
	UFUNCTION()
	const UStaminaComponent_Base* GetStaminaComponent() const;

public: // Public variables

	// Character movement speed
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement speed")
	FCharacterSpeed characterSpeed;

	// Flags for change movement state
	bool bIsCharacterSprint = false;
	bool bIsCharacterWalk = false;
	bool bIsCharacterTired = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bIsCharacterJump = false;

	// Character health component
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health components", meta = (AllowPrivateAccess = "true"))
	UHealthComponent_Base* healthComponent = nullptr;

	// Character stamina component
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stamina component", meta = (AllowPrivateAccess = "true"))
	UStaminaComponent_Base* staminaComponent = nullptr;

public: // Public functions

	UFUNCTION()
	void UpdateMovementState();

	UFUNCTION()
	void CharacterJumping();

	UFUNCTION()
	void CharacterDied();
};
