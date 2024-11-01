// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "RADGameInstance_Base.generated.h"



UCLASS()
class RUNANDDODGE_API URADGameInstance_Base : public UGameInstance
{
	GENERATED_BODY()
	
private:
	// Settings variables
	bool bIsVSync = false;

public:
	// Setting a Boolean variable to denote VSYNC
	UFUNCTION(BlueprintCallable)
	void SetbIsVSync(const bool& vSync);
	// Getting a Boolean variable VSYNC
	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool GetbIsVSync() const;
};
