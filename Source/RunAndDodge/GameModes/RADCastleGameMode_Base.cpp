// Fill out your copyright notice in the Description page of Project Settings.


#include "RADCastleGameMode_Base.h"
#include "../Traps/Crossbow/Bolt_Base.h"
#include "../RADCharacters/RADCharacter_Base.h"
#include "../GameStates/RADCastleGameState_Base.h"
#include "../Savers/Saver_Base.h"

#include "GameFramework/GameUserSettings.h"

void ARADCastleGameMode_Base::BeginPlay()
{
	Super::BeginPlay();

	RADGameState = Cast<ARADCastleGameState_Base>(GameState);
}

void ARADCastleGameMode_Base::SpawnObjectInObject(AActor* hitActor, AActor* otherHitActor)
{
	// If two bolts collide
	if (otherHitActor->ActorHasTag(FName(TEXT("Bolt"))))
	{
		auto firstBolt = GetWorld()->SpawnActor<ABolt_Base>(boltClass, hitActor->GetTransform());
		auto secondBolt = GetWorld()->SpawnActor<ABolt_Base>(boltClass, otherHitActor->GetTransform());

		firstBolt->SetLifeSpan(lifeSpanObjects);
		secondBolt->SetLifeSpan(lifeSpanObjects);

		firstBolt->boltMesh->SetSimulatePhysics(true);
		secondBolt->boltMesh->SetSimulatePhysics(true);

		firstBolt->boltMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
		secondBolt->boltMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);

		hitActor->Destroy();
		otherHitActor->Destroy();
	}
	// Collision with the world
	else
	{
		auto boltInObject = GetWorld()->SpawnActor<ABolt_Base>(boltClass, hitActor->GetTransform());
		boltInObject->SetLifeSpan(lifeSpanObjects);
		boltInObject->boltMesh->SetCollisionProfileName(FName(TEXT("NoCollision")));

		// Collision with a character
		if (otherHitActor->ActorHasTag(FName(TEXT("Player"))))
		{
			//boltInObject->AttachToActor(otherHitActor, FAttachmentTransformRules::KeepWorldTransform);
			character = Cast<ARADCharacter_Base>(otherHitActor);
			boltInObject->AttachToComponent(character->GetMesh(), FAttachmentTransformRules::KeepWorldTransform);
		}

		hitActor->Destroy();
	}
}

void ARADCastleGameMode_Base::StartGame()
{
	bIsGameOver = false;
	bIsWonLevel = false;
	RADGameState->StartGame();
}

void ARADCastleGameMode_Base::GameOver()
{
	bIsGameOver = true;
	bIsWonLevel = false;
	RADGameState->GameOver();
}

void ARADCastleGameMode_Base::WonLevel()
{
	bIsWonLevel = true;
	bIsGameOver = false;
	RADGameState->WonLevel();
}
