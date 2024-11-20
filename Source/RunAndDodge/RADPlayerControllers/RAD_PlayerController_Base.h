// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RAD_PlayerController_Base.generated.h"

class UInputAction;
class ARADHUDCastle_Base;

UCLASS()
class RUNANDDODGE_API ARAD_PlayerController_Base : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

public: // Public variables
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

	FInputModeGameAndUI inputGameAndUI;
	FInputModeGameOnly inputGameOnly;

	class ARADCharacter_Base* character = nullptr;
	ARADHUDCastle_Base* HUD = nullptr;

	FTimerHandle timerToAccelirationRun;

public: // Getters and setters

	UFUNCTION()
	ARADHUDCastle_Base* GetMyHUD() const;

public: // Public functions

	UFUNCTION()
	void SetControlSettings(const bool& bIsGameEnded, const bool& bIsWonLevel);
};
