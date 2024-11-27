// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Learning_Base.generated.h"

UCLASS()
class RUNANDDODGE_API ALearning_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALearning_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private: // Private functions

	UFUNCTION()
	void HandleBeginOverlap(UPrimitiveComponent* hitComponent, AActor* otherActor, UPrimitiveComponent*
		otherHitComponent, int32 index, bool bIsSweep, const FHitResult& hitResult);

private: // Private variables

	class URADGameInstance_Base* gameInstance = nullptr;

public: // Public variables

	UPROPERTY(EditAnywhere)
	class UBoxComponent* lookingCollision = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Learning widget")
	TSubclassOf<class UUserWidget> learningWidget_Class;
};
