// Fill out your copyright notice in the Description page of Project Settings.


#include "RADGameInstance_Base.h"

#include "Kismet/GameplayStatics.h"
#include "../Savers/Saver_Base.h"

float URADGameInstance_Base::GetTheBestLevelTime() const
{
	return levelBestTimes[0];
}

void URADGameInstance_Base::SetTheBestLevelTime(const float& newTime)
{
	if (levelBestTimes[0] <= 0.f || newTime < levelBestTimes[0])
	{
		levelBestTimes[0] = newTime;
		SaveRADGame();
	}
}

FString URADGameInstance_Base::GetNameCurrentLevel()
{
	return levelNames[0];
}

void URADGameInstance_Base::SaveRADGame()
{
	USaver_Base* RADSaver = Cast<USaver_Base>(UGameplayStatics::CreateSaveGameObject(USaver_Base::StaticClass()));
	RADSaver->theBestLevelTimes = levelBestTimes;
	UGameplayStatics::SaveGameToSlot(RADSaver, RADSaver->saveProfileName, 0);
}

void URADGameInstance_Base::LoadRADGame()
{
	USaver_Base* RADSaver = Cast<USaver_Base>(UGameplayStatics::CreateSaveGameObject(USaver_Base::StaticClass()));
	RADSaver = Cast<USaver_Base>(UGameplayStatics::LoadGameFromSlot(RADSaver->saveProfileName, 0));
	if (RADSaver)
		levelBestTimes = RADSaver->theBestLevelTimes;
	else
	SaveRADGame();
}
