// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile_Base.generated.h"

UCLASS()
class RUNANDDODGE_API AProjectile_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	AProjectile_Base();

	// Sets public values for this actor's properties
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Projectile")
	class UStaticMeshComponent* projectileMesh = nullptr;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Projectile")
	float lifeSpan = 0.f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Overlap collision")
	class USphereComponent* overlapCollision = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private: // Private variables

	float damage = 0.f;

	TSubclassOf<UDamageType> damageTypeClass;

public: // Public variables
	UFUNCTION()
	void InitProjectile(const FVector& projectileScale, const float& projectileDamage);

private: // Private functions

	UFUNCTION()
	void HandleBeginOverlap(UPrimitiveComponent* hitComponent, AActor* otherActorHit,
		UPrimitiveComponent* otherHitComponent, int32 indesOtherActor, bool bFromSweep, const FHitResult& hitResult);
};
