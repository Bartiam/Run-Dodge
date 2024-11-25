// Fill out your copyright notice in the Description page of Project Settings.


#include "RADCastleGameState_Base.h"
#include "../RADPlayerControllers/RAD_PlayerController_Base.h"
#include "../HUDs/RADHUDCastle_Base.h"
#include "../GameInstances/RADGameInstance_Base.h"
#include "../RADCharacters/RADCharacter_Base.h"
#include "../GameModes/RADCastleGameMode_Base.h"
#include "../Savers/Saver_Base.h"

#include "Kismet/GameplayStatics.h"

void ARADCastleGameState_Base::BeginPlay()
{
	playerController = Cast<ARAD_PlayerController_Base>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	gameInstance = Cast<URADGameInstance_Base>(GetGameInstance());
	character = Cast<ARADCharacter_Base>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	gameMode = Cast<ARADCastleGameMode_Base>(UGameplayStatics::GetGameMode(GetWorld()));

	// This will be deleted
	gameInstance->SetIndexLevel(1);
}

void ARADCastleGameState_Base::SetCurrentTimeSinceBeginLevel()
{
	currentTime += 1;
}

int ARADCastleGameState_Base::GetCurrentTimeSinceBeginLevel() const
{ return currentTime; }

void ARADCastleGameState_Base::StartGame()
{
	playerController->SetControlSettings(gameMode->bIsGameOver, gameMode->bIsWonLevel);
	GetWorldTimerManager().SetTimer(timeElapsedSinceBeginLevel, this, &ARADCastleGameState_Base::SetCurrentTimeSinceBeginLevel, 1, true);
}

void ARADCastleGameState_Base::GameOver()
{
	playerController->SetControlSettings(gameMode->bIsGameOver, gameMode->bIsWonLevel);
	playerController->DisableInput(playerController);
	GetWorldTimerManager().ClearTimer(timeElapsedSinceBeginLevel);
}

void ARADCastleGameState_Base::WonLevel()
{
	gameInstance->SetTheBestLevelTime(currentTime);
	playerController->SetControlSettings(gameMode->bIsGameOver, gameMode->bIsWonLevel);
	GetWorldTimerManager().ClearTimer(timeElapsedSinceBeginLevel);
}