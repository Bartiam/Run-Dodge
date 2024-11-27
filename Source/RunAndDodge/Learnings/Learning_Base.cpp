// Fill out your copyright notice in the Description page of Project Settings.


#include "Learning_Base.h"
#include "../GameInstances/RADGameInstance_Base.h"

#include "Components/BoxComponent.h"
#include "Blueprint/UserWidget.h"

// Sets default values
ALearning_Base::ALearning_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	// Create looking collision
	lookingCollision = CreateDefaultSubobject<UBoxComponent>(FName(TEXT("Looking collision")));
	SetRootComponent(lookingCollision);
	// Set collision 
	lookingCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	lookingCollision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
}

// Called when the game starts or when spawned
void ALearning_Base::BeginPlay()
{
	Super::BeginPlay();

	gameInstance = Cast<URADGameInstance_Base>(GetGameInstance());

	lookingCollision->OnComponentBeginOverlap.AddDynamic(this, &ALearning_Base::HandleBeginOverlap);

	if (!gameInstance->GetLearningEnabled())
	{
		Destroy();
	}
}

void ALearning_Base::HandleBeginOverlap(UPrimitiveComponent* hitComponent, AActor* otherActor,
	UPrimitiveComponent* otherHitComponent, int32 index, bool bIsSweep, const FHitResult& hitResult)
{
	if (otherActor->ActorHasTag(FName(TEXT("Player"))))
	{
		auto learningWidget = CreateWidget<UUserWidget>(learningWidget_Class);
		learningWidget->AddToViewport();
		Destroy();
	}
}

