// Fill out your copyright notice in the Description page of Project Settings.


#include "Shell_Base.h"
#include "Components/BoxComponent.h"
#include "../../GameModes/RADCastleGameMode_Base.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
AShell_Base::AShell_Base()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create bolt mesh
	shellMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName(TEXT("Shell")));
	SetRootComponent(shellMesh);
	shellMesh->SetCollisionProfileName(FName(TEXT("BlockAll")));
	// Add tag
	Tags.Add(FName(TEXT("Shell")));
}

// Called when the game starts or when spawned
void AShell_Base::BeginPlay()
{
	Super::BeginPlay();

	currentGameMode = Cast<ARADCastleGameMode_Base>(UGameplayStatics::GetGameMode(GetWorld()));
}

// Called every frame
void AShell_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bIsShoot)
		MovementBolt(DeltaTime);
}

void AShell_Base::InitBoltSettings(const FShellSpecification& shellInfo)
{
	shellSettings = shellInfo;
	SetActorScale3D(shellSettings.shellScale);
	shellMesh->OnComponentHit.AddDynamic(this, &AShell_Base::ComponentHit);
}

void AShell_Base::InteractBolt(AActor* interactor)
{

}

void AShell_Base::MovementBolt(float deltaTime)
{
	float timeSpeed = shellSettings.shellSpeed * deltaTime;

	FVector currentDirection = GetActorForwardVector() * timeSpeed;
	AddActorWorldOffset(currentDirection, true);
}

void AShell_Base::ComponentHit(UPrimitiveComponent* hitComponent, AActor* otherActorHit,
	UPrimitiveComponent* otherHitComponent, FVector normalImpuls, const FHitResult& hitResult)
{
	currentGameMode->SpawnObjectInObject(this, otherActorHit);

	if (otherActorHit->ActorHasTag(FName(TEXT("Player"))))
	{
		auto interactInterface = Cast<IInteractable>(otherActorHit);
		interactInterface->InteractBolt(otherActorHit);
	}
}

