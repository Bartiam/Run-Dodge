// Fill out your copyright notice in the Description page of Project Settings.


#include "../RADPlayerControllers/RAD_PlayerController_Base.h"
#include "../RADCharacters/RADCharacter_Base.h"

#include "EnhancedInput/Public/EnhancedInputComponent.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"

void ARAD_PlayerController_Base::BeginPlay()
{
	Super::BeginPlay();

	SetInputMode(inputMode);
	SetShowMouseCursor(false);

	// Add input mapping context
	if (UEnhancedInputLocalPlayerSubsystem* subSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		subSystem->AddMappingContext(inputMappingContext, 0);
	}

	character = Cast<ARADCharacter_Base>(GetPawn());
}

void ARAD_PlayerController_Base::SetupInputComponent()
{
	Super::SetupInputComponent();

	// InputComponent to EnhancedInputComponent
	if (UEnhancedInputComponent* enhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		// Bind movement
		enhancedInputComponent->BindAction(movementInputCharacter, ETriggerEvent::Triggered, this, &ARAD_PlayerController_Base::MovementCharacter);

		// Bind Jump
		enhancedInputComponent->BindAction(jumpInputCharacter, ETriggerEvent::Triggered, this, &ARAD_PlayerController_Base::JumpCharacter);
		enhancedInputComponent->BindAction(jumpInputCharacter, ETriggerEvent::Completed, this, &ARAD_PlayerController_Base::StopJumpCharacter);

		// Bind look
		enhancedInputComponent->BindAction(lookInputCharacter, ETriggerEvent::Triggered, this, &ARAD_PlayerController_Base::LookCharacter);
	}
}

void ARAD_PlayerController_Base::MovementCharacter(const FInputActionValue& value)
{
	FVector2D moveVector = value.Get<FVector2D>();

	if (IsValid(character))
	{
		// find out which way is forward
		const FRotator rotationYaw = FRotator(0.f, GetControlRotation().Yaw, 0.f);

		// get forward vector
		const FVector forwardDirection = FRotationMatrix(rotationYaw).GetUnitAxis(EAxis::X);
		// get right vector
		const FVector rightDirection = FRotationMatrix(rotationYaw).GetUnitAxis(EAxis::Y);
		// add movement
		character->AddMovementInput(forwardDirection, moveVector.Y);
		character->AddMovementInput(rightDirection, moveVector.X);
	}
}

void ARAD_PlayerController_Base::JumpCharacter()
{
	if (IsValid(character))
		character->Jump();
}

void ARAD_PlayerController_Base::StopJumpCharacter()
{
	if (IsValid(character))
		character->StopJumping();
}

void ARAD_PlayerController_Base::LookCharacter(const FInputActionValue& value)
{
	const FVector2D lookAxisVector = value.Get<FVector2D>();

	AddYawInput(lookAxisVector.X);
	AddPitchInput(lookAxisVector.Y);
}
