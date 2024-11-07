// Fill out your copyright notice in the Description page of Project Settings.


#include "../ActorComponents/StaminaComponent_Base.h"

// Sets default values for this component's properties
UStaminaComponent_Base::UStaminaComponent_Base()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UStaminaComponent_Base::BeginPlay()
{
	Super::BeginPlay();

	currentStamina = defaultStamina;
	
}


// Called every frame
void UStaminaComponent_Base::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UStaminaComponent_Base::SetCurrentStamina(const float& newStamina)
{
	currentStamina = newStamina;
}

float UStaminaComponent_Base::GetCurrentStamina() const
{
	return currentStamina;
}

