// Fill out your copyright notice in the Description page of Project Settings.


#include "RADGameInstance_Base.h"

float URADGameInstance_Base::GetFirstLevelBestTime() const
{
	return firstLevelBestTime;
}

void URADGameInstance_Base::SetFirstLevelBestTime(const float& newTime)
{
	if (firstLevelBestTime == 0.f || newTime < firstLevelBestTime)
		firstLevelBestTime = newTime;
}