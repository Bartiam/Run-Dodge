// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "../../Interfaces/IInteractable.h"

#include "Bolt_Base.generated.h"

UCLASS()
class RUNANDDODGE_API ABolt_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABolt_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Static mesh component
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Bolt mesh")
	UStaticMeshComponent* boltMesh = nullptr;

	bool bIsShoot = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Specifications of bolt")
	float damageOfBolt = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Specifications of bolt")
	float speedOfBolt = 0.f;

private:

	UFUNCTION()
	void MovementBolt(float deltaTime);

};
