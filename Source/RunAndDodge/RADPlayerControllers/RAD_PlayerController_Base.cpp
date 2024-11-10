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

		// Bind sprint
		enhancedInputComponent->BindAction(sprintInputCharacter, ETriggerEvent::Triggered, this, &ARAD_PlayerController_Base::SprintCharacter);
		enhancedInputComponent->BindAction(sprintInputCharacter, ETriggerEvent::Completed, this, &ARAD_PlayerController_Base::SprintStopped);

		// Bind crouch
		enhancedInputComponent->BindAction(crouchInputCharacter, ETriggerEvent::Triggered, this, &ARAD_PlayerController_Base::CrouchCharacter);
		enhancedInputComponent->BindAction(crouchInputCharacter, ETriggerEvent::Completed, this, &ARAD_PlayerController_Base::CrouchStopped);

		// Bind walk
		enhancedInputComponent->BindAction(walkInputCharacter, ETriggerEvent::Triggered, this, &ARAD_PlayerController_Base::WalkingCharacter);
		enhancedInputComponent->BindAction(walkInputCharacter, ETriggerEvent::Completed, this, &ARAD_PlayerController_Base::WalkStopped);
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
	character->Jump();
	character->bIsCharacterJump = true;
}

void ARAD_PlayerController_Base::StopJumpCharacter()
{
	character->StopJumping();
	character->bIsCharacterJump = false;
}

void ARAD_PlayerController_Base::LookCharacter(const FInputActionValue& value)
{
	const FVector2D lookAxisVector = value.Get<FVector2D>();

	AddYawInput(lookAxisVector.X);
	AddPitchInput(lookAxisVector.Y);
}

void ARAD_PlayerController_Base::SprintCharacter()
{
	if (!character->bIsCharacterTired)
	{
		character->bIsCharacterSprint = true;
		character->UpdateMovementState();
	}
}

void ARAD_PlayerController_Base::SprintStopped()
{
	character->bIsCharacterSprint = false;
	character->UpdateMovementState();
}

void ARAD_PlayerController_Base::CrouchCharacter()
{
	character->Crouch();
	character->UpdateMovementState();
}

void ARAD_PlayerController_Base::CrouchStopped()
{
	character->UnCrouch();
	character->UpdateMovementState();
}

void ARAD_PlayerController_Base::WalkingCharacter()
{
	character->bIsCharacterWalk = true;
	character->UpdateMovementState();
}

void ARAD_PlayerController_Base::WalkStopped()
{
	character->bIsCharacterWalk = false;
	character->UpdateMovementState();
}
