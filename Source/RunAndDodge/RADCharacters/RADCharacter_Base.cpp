// Fill out your copyright notice in the Description page of Project Settings.


#include "../RADCharacters/RADCharacter_Base.h"

#include "Camera/CameraComponent.h"

#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ARADCharacter_Base::ARADCharacter_Base()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

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

}

// Called to bind functionality to input
void ARADCharacter_Base::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

