// Fill out your copyright notice in the Description page of Project Settings.


#include "RADCastleGameState_Base.h"
#include "../RADPlayerControllers/RAD_PlayerController_Base.h"
#include "../HUDs/RADHUDCastle_Base.h"
#include "../GameInstances/RADGameInstance_Base.h"

#include "Kismet/GameplayStatics.h"

void ARADCastleGameState_Base::BeginPlay()
{
	playerController = Cast<ARAD_PlayerController_Base>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	gameInstance = Cast<URADGameInstance_Base>(GetGameInstance());
}

void ARADCastleGameState_Base::SetCurrentTimeSinceBeginLevel()
{
	currentTime += 0.1f;
}

float ARADCastleGameState_Base::GetCurrentTimeSinceBeginLevel() const
{ return currentTime; }

void ARADCastleGameState_Base::StartGame()
{
	bIsGameEnded = false;

	playerController->SetGameInputSettings(bIsGameEnded);

	GetWorldTimerManager().SetTimer(timeElapsedSinceBeginLevel, this, &ARADCastleGameState_Base::SetCurrentTimeSinceBeginLevel, 0.1f, true);
}

void ARADCastleGameState_Base::EndGame()
{
	gameInstance->SetTheBestTime(currentTime);
	bIsGameEnded = true;
	GetWorldTimerManager().ClearTimer(timeElapsedSinceBeginLevel);
	playerController->SetGameInputSettings(bIsGameEnded);
}
