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

	// Variables for graphics

		bool bIsVSync = false;

		int textureQuality;

		int shadowsQuality;

		int smoothing;
	// ==================================================== //

public:
	// Getters and setters for settings
		
		// VSync
		UFUNCTION(BlueprintCallable)
		void SetbIsVSync(const bool& vSync);

		UFUNCTION(BlueprintCallable, BlueprintPure)
		bool GetbIsVSync() const;



		// Textures
		UFUNCTION(BlueprintCallable)
		void SetTexturesQuality(const int& quality);

		UFUNCTION(BlueprintCallable, BlueprintPure)
		int GetTexturesQuality() const;



		// Shadows
		UFUNCTION(BlueprintCallable)
		void SetShadowsQuality(const int& quality);

		UFUNCTION(BlueprintCallable, BlueprintPure)
		int GetShadowsQuality() const;



		// Smoothing
		UFUNCTION(BlueprintCallable)
		void SetSmoothing(const int& smooth);

		UFUNCTION(BlueprintCallable, BlueprintPure)
		int GetSmoothing() const;

	// ============================================================= //
};
