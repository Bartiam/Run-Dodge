// Fill out your copyright notice in the Description page of Project Settings.


#include "Crossbow_Base.h"
#include "Shell_Base.h"
#include "../../RADCharacters/RADCharacter_Base.h"
#include "../../GameModes/RADCastleGameMode_Base.h"

#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SceneComponent.h"

#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACrossbow_Base::ACrossbow_Base()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create scene component
	rootSceneComponent = CreateDefaultSubobject<USceneComponent>(FName(TEXT("Root")));
	SetRootComponent(rootSceneComponent);

	// Create crossbow
	crossbow = CreateDefaultSubobject<UStaticMeshComponent>(FName(TEXT("Crossbow")));
	// Disable collision
	crossbow->SetCollisionProfileName(FName(TEXT("NoCollision")));
	crossbow->SetupAttachment(RootComponent);

	// Create looking collision
	LookingCollision = CreateDefaultSubobject<UBoxComponent>(FName(TEXT("Box collision")));
	LookingCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	LookingCollision->SetCollisionResponseToAllChannels(ECR_Overlap);
	LookingCollision->SetupAttachment(RootComponent);

	// Create spawn collision
	spawnCollision = CreateDefaultSubobject<UBoxComponent>(FName(TEXT("Spawn collision")));
	spawnCollision->SetupAttachment(crossbow);
}

// Called when the game starts or when spawned
void ACrossbow_Base::BeginPlay()
{
	Super::BeginPlay();

	LookingCollision->OnComponentBeginOverlap.AddDynamic(this, &ACrossbow_Base::HandleBeginOverlap);
	LookingCollision->OnComponentEndOverlap.AddDynamic(this, &ACrossbow_Base::HandleEndOverlap);

	currentGameMode = Cast<ARADCastleGameMode_Base>(UGameplayStatics::GetGameMode(GetWorld()));
	currentGameMode->shellClass = crossbowSettings.shellClass;

	SpawnBolt();
}

// Called every frame
void ACrossbow_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACrossbow_Base::SpawnBolt()
{
	FVector positionToSpawnBolt = FVector(spawnCollision->GetComponentLocation().X, spawnCollision->GetComponentLocation().Y, spawnCollision->GetComponentLocation().Z);

	bolt = GetWorld()->SpawnActor<AShell_Base>(crossbowSettings.shellClass, FTransform(positionToSpawnBolt));
	bolt->InitBoltSettings(crossbowSettings.shellSettings);
	bolt->SetActorRotation(crossbow->GetComponentRotation());
	bolt->AttachToComponent(crossbow, FAttachmentTransformRules::KeepWorldTransform);
}

void ACrossbow_Base::HandleBeginOverlap(UPrimitiveComponent* overlappedComponent, AActor* otherActor,
	UPrimitiveComponent* otherComponent, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult)
{
	if (otherActor->ActorHasTag(FName(TEXT("Player"))))
	{
		character = Cast<ARADCharacter_Base>(otherActor);
		GetWorldTimerManager().SetTimer(timerToShoot, this, &ACrossbow_Base::ShootBolt, crossbowSettings.timeBeforeShoot, false);
	}
}

void ACrossbow_Base::HandleEndOverlap(UPrimitiveComponent* overlappedComponent,
	AActor* otherActor, UPrimitiveComponent* otherComponent, int32 otherBodyIndex)
{
	if (otherActor->ActorHasTag(FName(TEXT("Player"))))
		character = nullptr;
}

void ACrossbow_Base::ShootBolt()
{
	bolt->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	bolt->bIsShoot = true;
	GetWorldTimerManager().SetTimer(timerToReload, this, &ACrossbow_Base::ReloadCrossbow, crossbowSettings.timeReload, false);
}

void ACrossbow_Base::ReloadCrossbow()
{
	SpawnBolt();
}