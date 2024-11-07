// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "RADHUDCastle_Base.generated.h"



UCLASS()
class RUNANDDODGE_API ARADHUDCastle_Base : public AHUD
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

private:
	// Variable UI widget
	UPROPERTY()
	class URADUIDuringTheGame_Base* widgetDuringTheGame = nullptr;
	
	void CreateWidgetDuringTheGame();

public:
	// Class UI widget
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widget During the game")
	TSubclassOf<URADUIDuringTheGame_Base> widgetDuringTheGame_Class;
};
