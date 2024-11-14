// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent_Base.h"

// Sets default values for this component's properties
UHealthComponent_Base::UHealthComponent_Base()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent_Base::BeginPlay()
{
	Super::BeginPlay();

	currentHealth = defaultHealth;
	
}


// Called every frame
void UHealthComponent_Base::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent_Base::SetCurrentHealth(const float& newHealth)
{
	currentHealth = newHealth;
}

float UHealthComponent_Base::GetCurrentHealth() const
{
	return currentHealth;
}

void UHealthComponent_Base::TakeDamageHealth(const float& damage)
{

}

void UHealthComponent_Base::HealthRegeneration()
{

}

