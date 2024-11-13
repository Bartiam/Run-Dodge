// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../../FunctionLib/MyTypes_Base.h"
#include "../../Interfaces/IInteractable.h"

#include "Shell_Base.generated.h"

UCLASS()
class RUNANDDODGE_API AShell_Base : public AActor, public IInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AShell_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public: // Public functions 

	// Static mesh component
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Shell mesh")
	class UStaticMeshComponent* shellMesh = nullptr;

	bool bIsShoot = false;
	
	FShellSpecification shellSettings;

	UFUNCTION()
	void InitBoltSettings(const FShellSpecification& shellInfo);

	virtual void InteractBolt(AActor* interactor) override;

private: // Private functions

	UFUNCTION()
	void MovementBolt(float deltaTime);

	UFUNCTION()
	void ComponentHit(UPrimitiveComponent* hitComponent, AActor* otherActorHit,
		UPrimitiveComponent* otherHitComponent, FVector normalImpuls, const FHitResult& hitResult);

private: // Private variables

	UPROPERTY()
	class ARADCastleGameMode_Base* currentGameMode = nullptr;
};
