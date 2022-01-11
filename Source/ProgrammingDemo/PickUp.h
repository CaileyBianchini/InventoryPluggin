// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "PickUp.generated.h"

/**
 * 
 */
UCLASS()
class PROGRAMMINGDEMO_API APickUp : public AInteractable
{
	GENERATED_BODY()


public:

	APickUp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UFUNCTION(BlueprintCallable)
	virtual void InteractableToInventory();

	UFUNCTION(BlueprintCallable)
	void Use();
	/*virtual void UseOfInteractable(); */

	UFUNCTION(BlueprintCallable)
	virtual void UseImp();

public:

	//this is what will give the item its thumbnail
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Pickup Properties")
	UTexture2D* PickUpThumbnail;

	//this is what will name the item
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Pickup Properties")
	FString ItemName;

	//this will give the item a stack number 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PickUp Properties")
	int32 Value;

	//This item is called when Item is picked up
	void OnPickedUp();
};
