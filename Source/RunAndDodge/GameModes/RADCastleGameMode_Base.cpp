// Fill out your copyright notice in the Description page of Project Settings.


#include "../GameModes/RADCastleGameMode_Base.h"
#include "../GameInstances/RADGameInstance_Base.h"

#include "GameFramework/GameUserSettings.h"

void ARADCastleGameMode_Base::BeginPlay()
{
	Super::BeginPlay();
	// Cast game instance
	gameInstance = Cast<URADGameInstance_Base>(GetGameInstance());
	userSettings = Cast<UGameUserSettings>(UGameUserSettings::GetGameUserSettings());
}

void ARADCastleGameMode_Base::SetGraphicOption()
{

}
