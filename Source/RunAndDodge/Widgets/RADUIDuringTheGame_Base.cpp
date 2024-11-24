// Fill out your copyright notice in the Description page of Project Settings.


#include "RADUIDuringTheGame_Base.h"
#include "../RADCharacters/RADCharacter_Base.h"
#include "../ActorComponents/HealthComponent_Base.h"
#include "../ActorComponents/StaminaComponent_Base.h"
#include "../GameStates/RADCastleGameState_Base.h"

#include "Kismet/GameplayStatics.h"

void URADUIDuringTheGame_Base::NativeConstruct()
{
	character = Cast<ARADCharacter_Base>(GetOwningPlayerPawn());
	gameState = Cast<ARADCastleGameState_Base>(UGameplayStatics::GetGameState(GetWorld()));
}

float URADUIDuringTheGame_Base::GetCurrentHealth() const
{
	if (IsValid(character))
	{
		return character->GetHealthComponent()->GetCurrentHealth() * 0.01f;
	}

	return 0.f;
}

float URADUIDuringTheGame_Base::GetCurrentStamina() const
{
	if (IsValid(character))
	{
		return character->GetStaminaComponent()->GetCurrentStamina() * 0.01f;
	}

	return 0.f;
}

FString URADUIDuringTheGame_Base::GetCurrentTime() const
{
	return FString::FromInt(gameState->GetCurrentTimeSinceBeginLevel());
}
