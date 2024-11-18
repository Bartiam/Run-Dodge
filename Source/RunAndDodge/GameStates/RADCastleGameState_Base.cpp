// Fill out your copyright notice in the Description page of Project Settings.


#include "RADCastleGameState_Base.h"

void ARADCastleGameState_Base::SetCurrentTimeSinceBeginLevel()
{
	currentTime += 0.1f;
}

float ARADCastleGameState_Base::GetCurrentTimeSinceBeginLevel() const
{ return currentTime; }

void ARADCastleGameState_Base::StartGame()
{
	GetWorldTimerManager().SetTimer(timeElapsedSinceBeginLevel, this, &ARADCastleGameState_Base::SetCurrentTimeSinceBeginLevel, 0.1f, true);
}
