// Fill out your copyright notice in the Description page of Project Settings.


#include "RADHUDCastle_Base.h"
#include "../Widgets/RADUIDuringTheGame_Base.h"

void ARADHUDCastle_Base::BeginPlay()
{
	Super::BeginPlay();

	CreateWidgetDuringTheGame();
}

void ARADHUDCastle_Base::CreateWidgetDuringTheGame()
{
	// Create widget
	widgetDuringTheGame = CreateWidget<URADUIDuringTheGame_Base>(GetWorld(), widgetDuringTheGame_Class);
	// Add widget to viewport
	widgetDuringTheGame->AddToViewport();
}

URADUIDuringTheGame_Base* ARADHUDCastle_Base::GetWidgetDuringTheGame() const
{
	return widgetDuringTheGame;
}
