// Fill out your copyright notice in the Description page of Project Settings.


#include "RADCastleGameMode_Base.h"
#include "../GameInstances/RADGameInstance_Base.h"
#include "../Traps/Crossbow/Shell_Base.h"
#include "../RADCharacters/RADCharacter_Base.h"

#include "GameFramework/GameUserSettings.h"

void ARADCastleGameMode_Base::BeginPlay()
{
	Super::BeginPlay();
}

void ARADCastleGameMode_Base::SpawnObjectInObject(AActor* hitActor, AActor* otherHitActor)
{
	// If two bolts collide
	if (otherHitActor->ActorHasTag(FName(TEXT("Shell"))))
	{
		auto firstBolt = GetWorld()->SpawnActor<AShell_Base>(shellClass, hitActor->GetTransform());
		auto secondBolt = GetWorld()->SpawnActor<AShell_Base>(shellClass, hitActor->GetTransform());

		firstBolt->SetLifeSpan(lifeSpanObjects);
		secondBolt->SetLifeSpan(lifeSpanObjects);

		firstBolt->shellMesh->SetSimulatePhysics(true);
		secondBolt->shellMesh->SetSimulatePhysics(true);

		hitActor->Destroy();
		otherHitActor->Destroy();
	}
	// Collision with the world
	else
	{
		auto boltInObject = GetWorld()->SpawnActor<AShell_Base>(shellClass, hitActor->GetTransform());
		boltInObject->SetLifeSpan(lifeSpanObjects);
		boltInObject->shellMesh->SetCollisionProfileName(FName(TEXT("NoCollision")));

		// Collision with a character
		if (otherHitActor->ActorHasTag(FName(TEXT("Player"))))
		{
			boltInObject->AttachToActor(otherHitActor, FAttachmentTransformRules::KeepWorldTransform);
		}

		hitActor->Destroy();
	}
}