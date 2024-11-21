// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent_Base.h"
#include "../GameModes/RADCastleGameMode_Base.h"
#include "../RADCharacters/RADCharacter_Base.h"

#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UHealthComponent_Base::UHealthComponent_Base()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UHealthComponent_Base::BeginPlay()
{
	Super::BeginPlay();

	currentHealth = defaultHealth;
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent_Base::TakeDamageHealth);

	gameMode = Cast<ARADCastleGameMode_Base>(UGameplayStatics::GetGameMode(GetWorld()));
	characterOwner = Cast<ARADCharacter_Base>(GetOwner());
}


// Called every frame
void UHealthComponent_Base::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (bIsCanRegeneration)
	{
		HealthRegeneration();
		NumberWhichHealthDecrease = DeltaTime * increaseHealth;
	}
}

void UHealthComponent_Base::SetCurrentHealth(const float& newHealth)
{
	currentHealth = newHealth;
}

float UHealthComponent_Base::GetCurrentHealth() const
{
	return currentHealth;
}

void UHealthComponent_Base::TakeDamageHealth(AActor* damageActor, float damage, const UDamageType* damageType, AController* instigateBy, AActor* damageCauser)
{
	GetWorld()->GetTimerManager().ClearTimer(timerForBeginRegeneration);
	bIsCanRegeneration = false;
	currentHealth -= damage;
	if (currentHealth <= 0.f)
	{
		currentHealth = 0.f;
		characterOwner->CharacterDied();
		gameMode->GameOver();
	}
	else
		GetWorld()->GetTimerManager().SetTimer(timerForBeginRegeneration, this, &UHealthComponent_Base::ChangeCanRegenerationHealth, timeToStartRegeneration, false);
}

void UHealthComponent_Base::HealthRegeneration()
{
	currentHealth += NumberWhichHealthDecrease;

	if (currentHealth >= defaultHealth)
	{
		currentHealth = defaultHealth;
		bIsCanRegeneration = false;
		return;
	}
}

void UHealthComponent_Base::ChangeCanRegenerationHealth()
{ bIsCanRegeneration = true; }