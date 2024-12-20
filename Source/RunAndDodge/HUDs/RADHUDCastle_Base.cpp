﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "RADHUDCastle_Base.h"
#include "../Widgets/RADUIDuringTheGame_Base.h"
#include "../Widgets/RADUIBeforeStartGame_Base.h"

void ARADHUDCastle_Base::BeginPlay()
{
	Super::BeginPlay();
	// Create widget
	widgetBeforeGame = CreateWidget<UUserWidget>(GetWorld(), widgetBeforeGame_Class);
	// Add widget to viewport
	widgetBeforeGame->AddToViewport();
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
	widgetEndGame = CreateWidget<UUserWidget>(GetWorld(), widgetEndGame_Class);
	widgetEndGame->AddToViewport();
}

void ARADHUDCastle_Base::CreateWonGameWidget()
{
	widgetWonLevel = CreateWidget<URADUIBeforeStartGame_Base>(GetWorld(), widgetWonLevel_Class);
	widgetWonLevel->AddToViewport();
}

URADUIDuringTheGame_Base* ARADHUDCastle_Base::GetWidgetDuringTheGame() const
{
	return widgetDuringTheGame;
}

UUserWidget* ARADHUDCastle_Base::GetWidgetEndGame() const
{
	return widgetEndGame;
}

UUserWidget* ARADHUDCastle_Base::GetWidgetBeforeGame() const
{
	return widgetBeforeGame;
}