// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelFinish_Base.h"
#include "../GameModes/RADCastleGameMode_Base.h"

#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ALevelFinish_Base::ALevelFinish_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create root component
	rootComponent = CreateDefaultSubobject<USceneComponent>(FName(TEXT("Root component")));
	SetRootComponent(rootComponent);

	// Create overlap collision
	overlapCollision = CreateDefaultSubobject<UBoxComponent>(FName(TEXT("Overlap collision")));
	overlapCollision->SetupAttachment(rootComponent);
	overlapCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

	// Create gate arch 
	gateArch = CreateDefaultSubobject<UStaticMeshComponent>(FName(TEXT("Gate Arch")));
	gateArch->SetupAttachment(rootComponent);

	// Create left gate 
	leftGate = CreateDefaultSubobject<UStaticMeshComponent>(FName(TEXT("Left gate")));
	leftGate->SetupAttachment(rootComponent);

	// Create right gate
	rightGate = CreateDefaultSubobject<UStaticMeshComponent>(FName(TEXT("Right gate")));
	rightGate->SetupAttachment(rootComponent);
}

// Called when the game starts or when spawned
void ALevelFinish_Base::BeginPlay()
{
	Super::BeginPlay();
	
	overlapCollision->OnComponentBeginOverlap.AddDynamic(this, &ALevelFinish_Base::FinishLevel);
	gameMode = Cast<ARADCastleGameMode_Base>(UGameplayStatics::GetGameMode(GetWorld()));
}

void ALevelFinish_Base::FinishLevel(UPrimitiveComponent* overlapComp, AActor* otherActor, 
	UPrimitiveComponent* otherComp, int32 indexActor, bool bIsSweep, const FHitResult& hitResult)
{
	if (otherActor->ActorHasTag(FName(TEXT("Player"))))
		gameMode->WonLevel();
}
