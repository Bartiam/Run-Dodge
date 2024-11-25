// Fill out your copyright notice in the Description page of Project Settings.


#include "RAD_PlayerController_Base.h"
#include "../RADCharacters/RADCharacter_Base.h"
#include "../HUDs/RADHUDCastle_Base.h"
#include "../Widgets/RADUIDuringTheGame_Base.h"
#include "../Widgets/RADUIBeforeStartGame_Base.h"
#include "../GameInstances/RADGameInstance_Base.h"

#include "EnhancedInput/Public/EnhancedInputComponent.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"

void ARAD_PlayerController_Base::BeginPlay()
{
	Super::BeginPlay();

	SetInputMode(inputGameOnly);
	SetShowMouseCursor(false);

	// Add input mapping context
	if (UEnhancedInputLocalPlayerSubsystem* subSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		subSystem->AddMappingContext(inputMappingContext, 0);
	}

	gameInstance = Cast<URADGameInstance_Base>(GetGameInstance());
	character = Cast<ARADCharacter_Base>(GetPawn());
	HUD = Cast<ARADHUDCastle_Base>(GetHUD());

	gameSensitivity = gameInstance->GetCurrentSensitivity();
}

void ARAD_PlayerController_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
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
	if (!character->bIsCharacterTired)
	{
		character->CharacterJumping();
	}
	else
	{
		HUD->GetWidgetDuringTheGame()->CharacterIsTired();
	}
}

void ARAD_PlayerController_Base::StopJumpCharacter()
{
	character->StopJumping();
	character->bIsCharacterJump = false;
}

void ARAD_PlayerController_Base::LookCharacter(const FInputActionValue& value)
{
	const FVector2D lookAxisVector = value.Get<FVector2D>();

	AddYawInput(lookAxisVector.X * gameSensitivity * GetWorld()->DeltaTimeSeconds);
	AddPitchInput(lookAxisVector.Y * gameSensitivity * GetWorld()->DeltaTimeSeconds);
}

void ARAD_PlayerController_Base::SprintCharacter()
{
	if (!character->bIsCharacterTired)
	{
		character->bIsCharacterSprint = true;
		character->UpdateMovementState();
	}
	else
	{
		HUD->GetWidgetDuringTheGame()->CharacterIsTired();
	}
}

void ARAD_PlayerController_Base::SprintStopped()
{
	character->bIsCharacterSprint = false;
	character->UpdateMovementState();
}

void ARAD_PlayerController_Base::CrouchCharacter()
{
	character->CharacterCrouch();
}

void ARAD_PlayerController_Base::CrouchStopped()
{
	character->CharacterUnCrouch();
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

ARADHUDCastle_Base* ARAD_PlayerController_Base::GetMyHUD() const
{ return HUD; }

void ARAD_PlayerController_Base::SetControlSettings(const bool& bIsGameEnded, const bool& bIsWonLevel)
{
	if (bIsGameEnded)
	{
		if (!IsValid(HUD->GetWidgetEndGame()))
		{
			HUD->GetWidgetDuringTheGame()->RemoveFromParent();
			HUD->CreateEndGameWidget();
			SetInputMode(inputGameAndUI);
			SetShowMouseCursor(true);
		}
	}
	else if (bIsWonLevel)
	{
		HUD->GetWidgetDuringTheGame()->RemoveFromParent();
		HUD->CreateWonGameWidget();
		SetInputMode(inputGameAndUI);
		SetShowMouseCursor(true);
	}
	else
	{
		HUD->CreateWidgetDuringTheGame();
	}
}
