// Fill out your copyright notice in the Description page of Project Settings.


#include "RADHUDCastle_Base.h"
#include "../Widgets/RADUIDuringTheGame_Base.h"
#include "../Widgets/RADUIBeforeStartGame_Base.h"

void ARADHUDCastle_Base::BeginPlay()
{
	Super::BeginPlay();
	// Create widget
	auto widgetBeforGame = CreateWidget<URADUIBeforeStartGame_Base>(GetWorld(), widgetBeforeGame_Class);
	// Add widget to viewport
	widgetBeforGame->AddToViewport();
}

void ARADHUDCastle_Base::CreateWidgetDuringTheGame()
{
	// Create widget
	widgetDuringTheGame = CreateWidget<URADUIDuringTheGame_Base>(GetWorld(), widgetDuringTheGame_Class);
	// Add widget to viewport
	widgetDuringTheGame->AddToViewport();
}

void ARADHUDCastle_Base::CreateEndGameWidget()
{
	widgetEndGame = CreateWidget<URADUIBeforeStartGame_Base>(GetWorld(), widgetEndGame_Class);
	widgetEndGame->AddToViewport();
}

URADUIDuringTheGame_Base* ARADHUDCastle_Base::GetWidgetDuringTheGame() const
{
	return widgetDuringTheGame;
}
