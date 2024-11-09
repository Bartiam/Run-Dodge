// Fill out your copyright notice in the Description page of Project Settings.


#include "../GameStates/RADCastleCameState_Base.h"

void ARADCastleCameState_Base::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(timeElapsedSinceBeginLevel, this, &ARADCastleCameState_Base::SetCurrentTimeSinceBeginLevel, 0.1f, true);
}

void ARADCastleCameState_Base::SetCurrentTimeSinceBeginLevel()
{
	currentTime += 0.1f;
}

float ARADCastleCameState_Base::GetCurrentTimeSinceBeginLevel() const
{ return currentTime; }
