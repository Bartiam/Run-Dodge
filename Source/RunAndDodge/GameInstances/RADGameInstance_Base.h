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
	// Переменные для настроек

	// Переменная вертикальной синхронизации
	bool bIsVSync = false;
	// Переменная для установки разрешения экрана
	FIntPoint screenResolution;
	// Переменная для установки качества текстур
	int textureQuality;
	// Переменная для установки качества текстур
	int shadowsQuality;
	// ==================================================== //

public:
	// Установка булевой переменной для вертикальной синхронизации
	UFUNCTION(BlueprintCallable)
	void SetbIsVSync(const bool& vSync);
	// Получение булевой переменной для вертикальной синхронизации
	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool GetbIsVSync() const;
	// ============================================================= //

	// Установка разрешения экрана
	UFUNCTION(BlueprintCallable)
	void SetScreenResolution(const FIntPoint& screenResolution);
	// Получение разрешения экрана
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FIntPoint GetScreenResolution() const;
	// ============================================================= //

	// Установка качества текстур
	UFUNCTION(BlueprintCallable)
	void SetTexturesQuality(const int& quality);
	// Получение качества текстур
	UFUNCTION(BlueprintCallable, BlueprintPure)
	int GetTexturesQuality() const;
	// ============================================================= //
};
