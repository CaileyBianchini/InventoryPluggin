// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "PickUp.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "MyCharacter.generated.h"

UCLASS()
class PROGRAMMINGDEMO_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

private: 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void MoveForward(float AxisValue);

	UFUNCTION(BlueprintCallable)
	void MoveRight(float AxisValue);

public:
	//The players reach
	float Reach;

//THIS IS APART OF THE EXAMPLE//
private:
	//This toggles the inventory
	void ToggleInventory();

	//interacts with the current interactable if there is an item to do so
	void Interact();

	//checks for interactable items directly in front of the player using a linetrace - called per tick
	void CheckForInteractables();

//THIS IS THE END OF THE EXAMPLE//
private:
	bool bIsMovingX = false;
	bool bIsMovingY = false;

};
