// Fill out your copyright notice in the Description page of Project Settings.


#include "../ActorComponents/StaminaComponent_Base.h"
#include "../RADCharacters/RADCharacter_Base.h"

#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UStaminaComponent_Base::UStaminaComponent_Base()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UStaminaComponent_Base::BeginPlay()
{
	Super::BeginPlay();

	currentStamina = defaultStamina;
	characterOwner = Cast<ARADCharacter_Base>(GetOwner());
}


// Called every frame
void UStaminaComponent_Base::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (bIsCanIncreaseStamina)
		AugmentStamina();
}

void UStaminaComponent_Base::SetCurrentStamina(const float& newStamina)
{
	currentStamina = newStamina;
}

float UStaminaComponent_Base::GetCurrentStamina() const
{
	return currentStamina;
}

void UStaminaComponent_Base::ReduseStamina()
{
	if (!characterOwner->GetVelocity().IsZero())
	{
		bIsCanIncreaseStamina = false;
		bIsStartsTimerToIncreaseStamina = false;
		currentStamina -= numberWhichStaminaChanges;
	}

	if (!bIsStartsTimerToIncreaseStamina)
	{
		GetWorld()->GetTimerManager().ClearTimer(timerToAugmentStamina);

		if (currentStamina <= 0.f)
		{
			currentStamina = 0.f;
			characterOwner->bIsCharacterSprint = false;
			characterOwner->bIsCharacterTired = true;

			characterOwner->UpdateMovementState();

			GetWorld()->GetTimerManager().SetTimer(timerToAugmentStamina, this, &UStaminaComponent_Base::ChangeCanIncreaseStamina, timeToRecoverStaminaAfterZero, false);

			return;
		}

		GetWorld()->GetTimerManager().SetTimer(timerToAugmentStamina, this, &UStaminaComponent_Base::ChangeCanIncreaseStamina, timeToRecoverStamina, false);

		bIsStartsTimerToIncreaseStamina = true;
	}
}

void UStaminaComponent_Base::AugmentStamina()
{
	currentStamina += numberWhichStaminaChanges;

	if (currentStamina >= recoveryFromTired)
	{
		bIsCharacterTired = false;

		auto myPlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		FKey shiftKey = EKeys::LeftShift;

		if (myPlayerController->IsInputKeyDown(shiftKey))
		{
			characterOwner->bIsCharacterSprint = true;
			characterOwner->UpdateMovementState();
		}
	}

	if (currentStamina >= defaultStamina)
	{
		currentStamina = defaultStamina;
		bIsCanIncreaseStamina = false;
	}
}

void UStaminaComponent_Base::ChangeCanIncreaseStamina()
{ bIsCanIncreaseStamina = true; }

