// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "RADHUDCastle_Base.generated.h"

class URADUIDuringTheGame_Base;

UCLASS()
class RUNANDDODGE_API ARADHUDCastle_Base : public AHUD
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

private:
	// Variable UI widget
	UPROPERTY()
	URADUIDuringTheGame_Base* widgetDuringTheGame = nullptr;

public:
	// Class UI widget
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widget During the game")
	TSubclassOf<URADUIDuringTheGame_Base> widgetDuringTheGame_Class;
	// Class UI before game

	void CreateWidgetDuringTheGame();

	// Getter widget during the game
	URADUIDuringTheGame_Base* GetWidgetDuringTheGame() const;
};
