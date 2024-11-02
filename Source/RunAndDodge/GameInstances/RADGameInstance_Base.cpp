// Fill out your copyright notice in the Description page of Project Settings.


#include "../GameInstances/RADGameInstance_Base.h"


void URADGameInstance_Base::SetbIsVSync(const bool& vSync)
{ bIsVSync = vSync; }


bool URADGameInstance_Base::GetbIsVSync() const
{ return bIsVSync; }


void URADGameInstance_Base::SetTexturesQuality(const int& quality)
{
	textureQuality = quality;
}


int URADGameInstance_Base::GetTexturesQuality() const
{
	return textureQuality;
}


void URADGameInstance_Base::SetShadowsQuality(const int& quality)
{
	shadowsQuality = quality;
}


int URADGameInstance_Base::GetShadowsQuality() const
{
	return shadowsQuality;
}


void URADGameInstance_Base::SetSmoothing(const int& smooth)
{
	smoothing = smooth;
}


int URADGameInstance_Base::GetSmoothing() const
{
	return smoothing;
}
