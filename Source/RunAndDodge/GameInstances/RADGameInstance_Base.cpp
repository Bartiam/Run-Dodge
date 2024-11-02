// Fill out your copyright notice in the Description page of Project Settings.


#include "../GameInstances/RADGameInstance_Base.h"

void URADGameInstance_Base::SetbIsVSync(const bool& vSync)
{ bIsVSync = vSync; }

bool URADGameInstance_Base::GetbIsVSync() const
{ return bIsVSync; }

void URADGameInstance_Base::SetScreenResolution(const FIntPoint & resolution)
{
	screenResolution = resolution;
}

FIntPoint URADGameInstance_Base::GetScreenResolution() const
{
	return screenResolution;
}

void URADGameInstance_Base::SetTexturesQuality(const int& quality)
{
	textureQuality = quality;
}

int URADGameInstance_Base::GetTexturesQuality() const
{
	return textureQuality;
}
