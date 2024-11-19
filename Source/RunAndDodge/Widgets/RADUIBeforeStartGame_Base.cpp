// Fill out your copyright notice in the Description page of Project Settings.


#include "RADUIBeforeStartGame_Base.h"
#include "../GameInstances/RADGameInstance_Base.h"

void URADUIBeforeStartGame_Base::NativeConstruct()
{
	gameInstance = Cast<URADGameInstance_Base>(GetGameInstance());
}

float URADUIBeforeStartGame_Base::GetBestEndlessModeTime()
{
	return gameInstance->GetFirstLevelBestTime();
}
