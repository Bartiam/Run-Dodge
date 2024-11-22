// Fill out your copyright notice in the Description page of Project Settings.


#include "RADGameInstance_Base.h"

#include "Kismet/GameplayStatics.h"

float URADGameInstance_Base::GetTheBestLevelTime() const
{
	return levelBestTimes[0];
}

void URADGameInstance_Base::SetTheBestLevelTime(const float& newTime)
{
	if (levelBestTimes[0] <= 0.f || newTime < levelBestTimes[0])
	{
		levelBestTimes[0] = newTime;
		bIsNewRecord = true;
		SaveRADGame();
	}
}

FString URADGameInstance_Base::GetNameCurrentLevel()
{
	return levelNames[0];
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
	levelBestTimes = RADSaver->theBestLevelTimes;
}
