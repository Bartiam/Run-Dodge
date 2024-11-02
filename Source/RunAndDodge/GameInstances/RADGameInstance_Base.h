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
	// ���������� ��� ��������

	// ���������� ������������ �������������
	bool bIsVSync = false;
	// ���������� ��� ��������� ���������� ������
	FIntPoint screenResolution;
	// ���������� ��� ��������� �������� �������
	int textureQuality;
	// ���������� ��� ��������� �������� �������
	int shadowsQuality;
	// ==================================================== //

public:
	// ��������� ������� ���������� ��� ������������ �������������
	UFUNCTION(BlueprintCallable)
	void SetbIsVSync(const bool& vSync);
	// ��������� ������� ���������� ��� ������������ �������������
	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool GetbIsVSync() const;
	// ============================================================= //

	// ��������� ���������� ������
	UFUNCTION(BlueprintCallable)
	void SetScreenResolution(const FIntPoint& screenResolution);
	// ��������� ���������� ������
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FIntPoint GetScreenResolution() const;
	// ============================================================= //

	// ��������� �������� �������
	UFUNCTION(BlueprintCallable)
	void SetTexturesQuality(const int& quality);
	// ��������� �������� �������
	UFUNCTION(BlueprintCallable, BlueprintPure)
	int GetTexturesQuality() const;
	// ============================================================= //
};
