// Fill out your copyright notice in the Description page of Project Settings.


#include "RADGameInstance_Base.h"

#include "Kismet/GameplayStatics.h"

int URADGameInstance_Base::GetTheBestLevelTime() const
{
	return levelBestTimes[indexLevel - 1];
}

void URADGameInstance_Base::SetTheBestLevelTime(const int& newTime)
{
	if (levelBestTimes[indexLevel - 1] <= 0.f || newTime < levelBestTimes[indexLevel - 1])
	{
		levelBestTimes[indexLevel - 1] = newTime;
		bIsNewRecord = true;
		SaveRADGame();
	}
}

FString URADGameInstance_Base::GetNameCurrentLevel()
{
	return levelNames[indexLevel - 1];
}

void URADGameInstance_Base::SetIndexLevel(int newIndex)
{
	indexLevel = newIndex;
}

void URADGameInstance_Base::SaveRADGame()
{
	auto RADSaver = Cast<USaver_Base>(UGameplayStatics::CreateSaveGameObject(USaver_Base::StaticClass()));
	RADSaver->theBestLevelTimes = levelBestTimes;
	UGameplayStatics::SaveGameToSlot(RADSaver, profileName, 0);
}

void URADGameInstance_Base::LoadRADGame()
{
	auto RADSaver = Cast<USaver_Base>(UGameplayStatics::LoadGameFromSlot(profileName, 0));
	if (RADSaver)
		levelBestTimes = RADSaver->theBestLevelTimes;
}
