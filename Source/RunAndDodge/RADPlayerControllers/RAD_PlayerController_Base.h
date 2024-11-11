// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RAD_PlayerController_Base.generated.h"

class UInputAction;

UCLASS()
class RUNANDDODGE_API ARAD_PlayerController_Base : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

public:
	// Input
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputAction* movementInputCharacter = nullptr;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputAction* lookInputCharacter = nullptr;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputAction* jumpInputCharacter = nullptr;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputAction* sprintInputCharacter = nullptr;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputAction* crouchInputCharacter = nullptr;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputAction* walkInputCharacter = nullptr;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	class UInputMappingContext* inputMappingContext = nullptr;

private: // Private functions

	// player input
	virtual void SetupInputComponent() override;

	// player movement
	UFUNCTION()
	void MovementCharacter(const FInputActionValue& value);

	// player jump
	UFUNCTION()
	void JumpCharacter();

	// player stop jumping
	UFUNCTION()
	void StopJumpCharacter();

	// Player look
	UFUNCTION()
	void LookCharacter(const FInputActionValue& value);

	// Player sprint
	UFUNCTION()
	void SprintCharacter();

	// Player stop sprint
	UFUNCTION()
	void SprintStopped();

	// Player crouch
	UFUNCTION()
	void CrouchCharacter();

	// Player stop crouch
	UFUNCTION()
	void CrouchStopped();

	// Player walking
	UFUNCTION()
	void WalkingCharacter();

	// Player stop walking
	UFUNCTION()
	void WalkStopped();

private: // Private variables
	const FInputModeGameOnly inputMode;

	class ARADCharacter_Base* character = nullptr;
	class ARADHUDCastle_Base* HUD = nullptr;

	FTimerHandle timerToAccelirationRun;
};
