// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RADUIDuringTheGame_Base.generated.h"



UCLASS()
class RUNANDDODGE_API URADUIDuringTheGame_Base : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

private:
	UPROPERTY()
	class ARADCharacter_Base* character = nullptr;
	UPROPERTY()
	class UHealthComponent_Base* characterHealthComponent = nullptr;

public:
	// Getter for character health
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetCurrentHealth() const;
	// Getter for character stamina
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetCurrentStamina() const;
};
