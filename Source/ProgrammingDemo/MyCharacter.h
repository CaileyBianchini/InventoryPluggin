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

	// ALSO APART OF THE EXAMPLE	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//END OF EXAMPLE IN THIS BIT

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void MoveForward(float AxisValue);

	UFUNCTION(BlueprintCallable)
	void MoveRight(float AxisValue);


//THIS IS APART OF THE EXAMPLE//

public:

	//This toggles the inventory
	UFUNCTION(BlueprintCallable)
	void InventoryToggleOpenClose();

	//help text to help player
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
	FString HelpText;

	//Adds an item to the inventory 
	UFUNCTION(BlueprintPure, Category = "Inventory Functions")
	bool AddItemToInventory(APickUp* Item);

	//Gets the thumbnail for a given inventory slot
	UFUNCTION(BlueprintPure, Category = "Inventory Functions")
	UTexture2D* GetThumbnailAtInventorySlot(int32 Slot);

	//Gets the item name for a given inventory slot
	UFUNCTION(BlueprintPure, Category = "Inventory Functions")
	FString GivenNameAtInventorySlot(int32 Slot);

	//uses the item at a given inventory slot
	UFUNCTION(BlueprintCallable, Category = "Inventory Functions")
	void UseItemAtInventorySlot(int32 Slot);

private:
	

	//interacts with the current interactable if there is an item to do so
	void Interact();

	//checks for interactable items directly in front of the player using a linetrace - called per tick
	void CheckForInteractables();


public:
	//The players reach
	float Reach;

	//the interactable the player is looking at
	AInteractable* currentInteractable;

	//the players inventory, represented as a tarray of a pickup objects
	UPROPERTY(EditAnywhere)
	TArray<APickUp*> Inventory;

//THIS IS THE END OF THE EXAMPLE//
private:
	bool bIsMovingX = false;
	bool bIsMovingY = false;

};
