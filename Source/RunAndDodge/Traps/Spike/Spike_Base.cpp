// Fill out your copyright notice in the Description page of Project Settings.


#include "Spike_Base.h"

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASpike_Base::ASpike_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Create spike mesh
	spikeMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName(TEXT("Spike mesh")));
	// Set spike as a root component
	SetRootComponent(spikeMesh);
	// set mesh collision
	spikeMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// Create damage collision
	damageCollision = CreateDefaultSubobject<UBoxComponent>(FName(TEXT("Damage collision")));
	// Attach to the root component
	damageCollision->SetupAttachment(RootComponent);
	// Set collision
	damageCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	damageCollision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);

	// Create check collision
	checkCollision = CreateDefaultSubobject<UBoxComponent>(FName(TEXT("Check collision")));
	// Attach to root component
	checkCollision->SetupAttachment(RootComponent);
	// Set Collision
	checkCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	checkCollision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	// Create audio component
	spikeSoundAudioComponent = CreateDefaultSubobject<UAudioComponent>(FName(TEXT("Audio component")));
	spikeSoundAudioComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ASpike_Base::BeginPlay()
{
	Super::BeginPlay();
	damageCollision->OnComponentBeginOverlap.AddDynamic(this, &ASpike_Base::DamageBeginOverlap);
	checkCollision->OnComponentBeginOverlap.AddDynamic(this, &ASpike_Base::CheckBeginOverlap);
}

void ASpike_Base::DamageBeginOverlap(UPrimitiveComponent* hitComponent, AActor* otherActor,
	UPrimitiveComponent* otherHitComponent, int32 indexOtherActor, bool bFromSweep, const FHitResult& hitResult)
{
	if (otherActor->ActorHasTag(FName(TEXT("Player"))))
	{
		UGameplayStatics::ApplyDamage(otherActor, damage, GetInstigatorController(), this, damageTypeClass);
	}
}

void ASpike_Base::CheckBeginOverlap(UPrimitiveComponent* hitComponent, AActor* otherActor,
	UPrimitiveComponent* otherHitComponent, int32 indexOtherComponent, bool bIsFromSweep, const FHitResult& hitResult)
{
	if (otherActor->ActorHasTag(FName(TEXT("Player"))))
	{
		GetWorldTimerManager().SetTimer(timerToRiseUp, this, &ASpike_Base::RiseUpSpike, 1.f, false);
	}
}

void ASpike_Base::RiseUpSpike()
{
	spikeSoundAudioComponent->Play();
	SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + raisUpByZ));
	checkCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetWorldTimerManager().SetTimer(timerToRiseDown, this, &ASpike_Base::RiseDownSpike, 1.f, false);
}

void ASpike_Base::RiseDownSpike()
{
	spikeSoundAudioComponent->Play();
	SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z - raisUpByZ));
	checkCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}