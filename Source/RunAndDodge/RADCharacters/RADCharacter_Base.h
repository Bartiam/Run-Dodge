// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RADCharacter_Base.generated.h"

UCLASS()
class RUNANDDODGE_API ARADCharacter_Base : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARADCharacter_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:
	// Character camera component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* springArm = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* camera = nullptr;

	// Character health component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Health components", meta = (AllowPrivateAccess = "true"))
	class UHealthComponent_Base* healthComponent = nullptr;

public:
	// Getter for health component
	UFUNCTION()
	UHealthComponent_Base* GetHealthComponent() const;
};
