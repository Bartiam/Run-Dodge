// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "RADHUDCastle_Base.generated.h"

class URADUIDuringTheGame_Base;
class URADUIBeforeStartGame_Base;

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

	// Variable UI end game widget
	UPROPERTY()
	URADUIBeforeStartGame_Base* widgetEndGame = nullptr;

public:
	// Class UI before game
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
	TSubclassOf<URADUIBeforeStartGame_Base> widgetBeforeGame_Class;
	// Class UI widget
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
	TSubclassOf<URADUIDuringTheGame_Base> widgetDuringTheGame_Class;
	// Class UI end game
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
	TSubclassOf<URADUIBeforeStartGame_Base> widgetEndGame_Class;


	UFUNCTION()
	void CreateWidgetDuringTheGame();

	UFUNCTION()
	void CreateEndGameWidget();

	// Getter widget during the game
	URADUIDuringTheGame_Base* GetWidgetDuringTheGame() const;
};
