﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "RADGameInstance_Base.h"

#include "Kismet/GameplayStatics.h"

float URADGameInstance_Base::GetCurrentSensitivity() const
{
	return currentSensitivity;
}

void URADGameInstance_Base::SetCurrentSensitivity(float newSensitivity)
{
	currentSensitivity = newSensitivity;
}

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

bool URADGameInstance_Base::GetLearningEnabled() const
{
	return bIsLearningEnabled;
}

void URADGameInstance_Base::SetLearningEnabled(bool bIsEnabled)
{
	bIsLearningEnabled = bIsEnabled;
}

float URADGameInstance_Base::GetCurrentMusicVolume() const
{
	return musicVolume;
}

void URADGameInstance_Base::SetCurrentMusicVolume(float newMusicVolume)
{
	musicVolume = newMusicVolume;
}

float URADGameInstance_Base::GetCurrentSoundVolume() const
{
	return soundsVolume;
}

void URADGameInstance_Base::SetCurrentSoundVolume(float newSoundVolume)
{
	soundsVolume = newSoundVolume;
}

void URADGameInstance_Base::SaveRADGame()
{
	auto RADSaver = Cast<USaver_Base>(UGameplayStatics::CreateSaveGameObject(USaver_Base::StaticClass()));
	RADSaver->theBestLevelTimes = levelBestTimes;
	RADSaver->sensitivity = currentSensitivity;
	RADSaver->bIsLearningEnabled = bIsLearningEnabled;
	RADSaver->musicVolume = musicVolume;
	RADSaver->soundVolume = soundsVolume;
	UGameplayStatics::SaveGameToSlot(RADSaver, profileName, 0);
}

void URADGameInstance_Base::LoadRADGame()
{
	auto RADSaver = Cast<USaver_Base>(UGameplayStatics::LoadGameFromSlot(profileName, 0));
	if (RADSaver)
	{
		currentSensitivity = RADSaver->sensitivity;
		levelBestTimes = RADSaver->theBestLevelTimes;
		bIsLearningEnabled = RADSaver->bIsLearningEnabled;
		musicVolume = RADSaver->musicVolume;
		soundsVolume = RADSaver->soundVolume;
	}
}
