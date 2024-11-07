// Fill out your copyright notice in the Description page of Project Settings.


#include "../Widgets/RADUIDuringTheGame_Base.h"
#include "../RADCharacters/RADCharacter_Base.h"
#include "../ActorComponents/HealthComponent_Base.h"
#include "../ActorComponents/StaminaComponent_Base.h"

void URADUIDuringTheGame_Base::NativeConstruct()
{
	character = Cast<ARADCharacter_Base>(GetOwningPlayerPawn());
}

float URADUIDuringTheGame_Base::GetCurrentHealth() const
{
	if (IsValid(character))
	{
		return character->GetHealthComponent()->GetCurrentHealth() * 0.01f;
	}

	return 0.0f;
}

float URADUIDuringTheGame_Base::GetCurrentStamina() const
{
	if (IsValid(character))
	{
		return character->GetStaminaComponent()->GetCurrentStamina() * 0.01f;
	}

	return 0.0f;
}
