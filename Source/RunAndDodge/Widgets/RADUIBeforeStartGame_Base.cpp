// Fill out your copyright notice in the Description page of Project Settings.


#include "RADUIBeforeStartGame_Base.h"
#include "../GameInstances/RADGameInstance_Base.h"

void URADUIBeforeStartGame_Base::NativeConstruct()
{
	gameInstance = Cast<URADGameInstance_Base>(GetGameInstance());
}

FString URADUIBeforeStartGame_Base::GetTheBestTimeThisLevel()
{
	auto tempVar = gameInstance->GetTheBestLevelTime();
	FString result = FString::FromInt(tempVar);

	if (tempVar <= 0.f)
	{
		result = FString(TEXT("Не пройдено"));
		return result;
	}

	return result;
}

FString URADUIBeforeStartGame_Base::GetLevelName()
{
	return gameInstance->GetNameCurrentLevel();
}

FString URADUIBeforeStartGame_Base::GetTextBestTime()
{
	FString result = FString(TEXT("Лучший забег: "));

	if (gameInstance->bIsNewRecord)
		result = FString(TEXT("НОВЫЙ РЕКОРД!"));

	return result;
}
