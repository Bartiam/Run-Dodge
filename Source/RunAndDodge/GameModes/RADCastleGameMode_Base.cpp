// Fill out your copyright notice in the Description page of Project Settings.


#include "RADCastleGameMode_Base.h"
#include "../GameInstances/RADGameInstance_Base.h"
#include "../Traps/Crossbow/Bolt_Base.h"

#include "GameFramework/GameUserSettings.h"

void ARADCastleGameMode_Base::BeginPlay()
{
	Super::BeginPlay();
}

void ARADCastleGameMode_Base::SpawnObjectInObject(const AActor* hitActor)
{
	auto collideObject = Cast<ABolt_Base>(hitActor);

	auto boltInObject = GetWorld()->SpawnActor<ABolt_Base>(boltClass, collideObject->GetTransform());
	boltInObject->SetLifeSpan(lifeSpanObjects);
}