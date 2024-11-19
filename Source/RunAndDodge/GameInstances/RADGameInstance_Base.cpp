// Fill out your copyright notice in the Description page of Project Settings.


#include "RADGameInstance_Base.h"

float URADGameInstance_Base::GetEndlessModeBestTime() const
{
	return endlessModeBestTime;
}

void URADGameInstance_Base::SetEndlessModeBestTime(const float& newTime)
{
	if (newTime > endlessModeBestTime)
		endlessModeBestTime = newTime;
}