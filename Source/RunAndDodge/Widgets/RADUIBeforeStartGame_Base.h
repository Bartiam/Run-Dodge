// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RADUIBeforeStartGame_Base.generated.h"

UCLASS()
class RUNANDDODGE_API URADUIBeforeStartGame_Base : public UUserWidget
{
	GENERATED_BODY()

private: // Private variables

	UPROPERTY()
	class URADGameInstance_Base* gameInstance = nullptr;

private: // Private functions

	virtual void NativeConstruct() override;

public: // Public functions

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetBestEndlessModeTime();
};
