// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../../Interfaces/IInteractable.h"

#include "Crossbow_Base.generated.h"

class UStaticMeshComponent;
class ABolt_Base;

UCLASS()
class RUNANDDODGE_API ACrossbow_Base : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACrossbow_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public: // Public variables	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// crossbow bolt
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Bolt")
	TSubclassOf<ABolt_Base> boltClass;

	// crossbow mesh
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Crossbow")
	UStaticMeshComponent* crossbow = nullptr;

	// Collisiton for looking character
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Looking collision")
	class UBoxComponent* LookingCollision = nullptr;

	// Root component
	UPROPERTY()
	class USceneComponent* rootSceneComponent = nullptr;

	UPROPERTY(BlueprintReadOnly)
	bool bIsCharacterOverlapped = false;

	UPROPERTY(BlueprintReadOnly)
	class ARADCharacter_Base* character = nullptr;

	UPROPERTY(EditAnywhere)
	FVector scaleOfTheBolt = FVector::Zero();

	UPROPERTY(EditAnywhere)
	float heightOfBolt = 0.f;

private: // Private variables

	FVector positionToSpawnBolt = FVector::Zero();

	UPROPERTY()
	ABolt_Base* bolt = nullptr;

	FTimerHandle timerToReload;

public: // Public functions

	UFUNCTION()
	void SpawnBolt();

private: // Private functions

	// Event when somebody begin overlap
	UFUNCTION()
	void HandleBeginOverlap(UPrimitiveComponent* overlappedComponent, AActor* otherActor, UPrimitiveComponent*
		otherComponent, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult);

	// Event when somebody end overlap
	UFUNCTION()
	void HandleEndOverlap(UPrimitiveComponent* overlappedComponent, AActor* otherActor, UPrimitiveComponent*
		otherComponent, int32 otherBodyIndex);

	// Shot
	UFUNCTION()
	void ShootBolt();

	// Reload
	UFUNCTION()
	void ReloadCrossbow();

};
