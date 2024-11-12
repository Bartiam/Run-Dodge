// Fill out your copyright notice in the Description page of Project Settings.


#include "RADCharacter_Base.h"
#include "../ActorComponents/HealthComponent_Base.h"
#include "../ActorComponents/StaminaComponent_Base.h"

#include "Camera/CameraComponent.h"

#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ARADCharacter_Base::ARADCharacter_Base()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve pe		rformance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.f, 540.0f, 0.f); // ...at this rotation rate
	GetCharacterMovement()->MaxWalkSpeed = characterSpeed.simpleRunSpeed;
	GetCharacterMovement()->MaxWalkSpeedCrouched = characterSpeed.crouchSpeed;
	GetCharacterMovement()->GetNavAgentPropertiesRef().bCanCrouch = true;
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->CrouchedHalfHeight = 88.f;

	// Create spring arm
	springArm = CreateDefaultSubobject<USpringArmComponent>(FName("Spring Arm"));
	springArm->SetupAttachment(RootComponent);
	springArm->SetUsingAbsoluteRotation(true);
	springArm->bDoCollisionTest = true;
	springArm->bUsePawnControlRotation = true;

	springArm->TargetArmLength = 300.f;
	springArm->SocketOffset.Z = 100.f;

	// Create camera component
	camera = CreateDefaultSubobject<UCameraComponent>(FName("Camera"));
	camera->SetupAttachment(springArm);
	camera->bUsePawnControlRotation = true;

	// Create health component
	healthComponent = CreateDefaultSubobject<UHealthComponent_Base>(FName("Health component"));
	// Create stamina component
	staminaComponent = CreateDefaultSubobject<UStaminaComponent_Base>(FName("Stamina component"));
	// Set tag
	Tags.Add(FName(TEXT("Player")));
}

// Called when the game starts or when spawned
void ARADCharacter_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARADCharacter_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsCharacterSprint)
	{
		staminaComponent->numberWhichStaminaChanges = DeltaTime * staminaComponent->decreaseStamina;
	}
	else
	{
		staminaComponent->numberWhichStaminaChanges = DeltaTime * staminaComponent->increaseStamina;
	}
}

// Called to bind functionality to input
void ARADCharacter_Base::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ARADCharacter_Base::UpdateMovementSpeed()
{
	switch (currentMovementState)
	{
	case EMovementState::CROUCH:
		GetCharacterMovement()->MaxWalkSpeedCrouched = characterSpeed.crouchSpeed;
		break;
	case EMovementState::FAST_CROUCH:
		GetCharacterMovement()->MaxWalkSpeedCrouched = characterSpeed.fastCrouchSpeed;
		break;
	case EMovementState::WALK:
		GetCharacterMovement()->MaxWalkSpeed = characterSpeed.walkSpeed;
		break;
	case EMovementState::SIMPLE_RUN:
		GetCharacterMovement()->MaxWalkSpeed = characterSpeed.simpleRunSpeed;
		break;
	case EMovementState::SPRINT:
		GetCharacterMovement()->MaxWalkSpeed = characterSpeed.sprintSpeed;
		break;
	}
}

const UHealthComponent_Base* ARADCharacter_Base::GetHealthComponent() const
{
	return healthComponent;
}

const UStaminaComponent_Base* ARADCharacter_Base::GetStaminaComponent() const
{
	return staminaComponent;
}

void ARADCharacter_Base::UpdateMovementState()
{
	if (bIsCharacterSprint && GetCharacterMovement()->IsCrouching())
	{
		currentMovementState = EMovementState::FAST_CROUCH;
	}
	else if (GetCharacterMovement()->IsCrouching())
	{
		currentMovementState = EMovementState::CROUCH;
	}
	else if (bIsCharacterSprint)
	{
		currentMovementState = EMovementState::SPRINT;
	}
	else if (bIsCharacterWalk)
	{
		currentMovementState = EMovementState::WALK;
	}
	else
	{
		currentMovementState = EMovementState::SIMPLE_RUN;
	}

	UpdateMovementSpeed();
}

void ARADCharacter_Base::CharacterJumping()
{
	if (!GetCharacterMovement()->IsFalling() && 
		staminaComponent->GetCurrentStamina() > staminaComponent->staminaSpentOnJump)
	{
		Jump();
		bIsCharacterJump = true;
		staminaComponent->ReduseStaminaJump();
	}
}

