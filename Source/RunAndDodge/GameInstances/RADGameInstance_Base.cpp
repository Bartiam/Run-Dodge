// Fill out your copyright notice in the Description page of Project Settings.


#include "RADGameInstance_Base.h"

float URADGameInstance_Base::GetTheBestLevelTime() const
{
	return firstLevelBestTime;
}

void URADGameInstance_Base::SetTheBestLevelTime(const float& newTime)
{
	if (firstLevelBestTime <= 0.f || newTime < firstLevelBestTime)
	{
		firstLevelBestTime = newTime;
		bIsNewRecord = true;
	}
}

FString URADGameInstance_Base::GetNameCurrentLevel()
{
	return firstLevelName;
}
