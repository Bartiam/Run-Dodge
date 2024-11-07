// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "../FunctionLib/MyTypes_Base.h"

#include "RADCharacter_Base.generated.h"

class UHealthComponent_Base;
class UStaminaComponent_Base;

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

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private: // Private variables

	// Character camera component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* springArm = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* camera = nullptr;

	// Character health component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Health components", meta = (AllowPrivateAccess = "true"))
	UHealthComponent_Base* healthComponent = nullptr;

	// Character stamina component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stamina component", meta = (AllowPrivateAccess = "true"))
	UStaminaComponent_Base* staminaComponent = nullptr;

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
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Bool value")
	bool bIsSprint = false;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Bool value")
	bool bIsCrouch = false;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Bool value")
	bool bIsWalk = false;

public: // Public functions

	UFUNCTION()
	void UpdateMovementState();
};
