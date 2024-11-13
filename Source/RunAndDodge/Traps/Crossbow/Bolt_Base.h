// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../../FunctionLib/MyTypes_Base.h"

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
	class UStaticMeshComponent* boltMesh = nullptr;

	bool bIsShoot = false;
	
	FBoltSpecification boltSettings;

	UFUNCTION()
	void InitBoltSettings(const FBoltSpecification& boltInfo);

private:

	UFUNCTION()
	void MovementBolt(float deltaTime);

	UFUNCTION()
	void ComponentHitEvent(UPrimitiveComponent* hitComponent, AActor* otherActorHit,
		UPrimitiveComponent* otherHitComponent, FVector normalImpuls, const FHitResult& hitResult);
};
