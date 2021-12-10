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


	virtual void Interact_Implementation() override;

	UPROPERTY(EditAnywhere, Category = "Pickup Properties")

	UPROPERTY(EditAnywhere, Category = "PickUp Properties")
	int32 Value;

	//This item is called when Item is picked up
	void OnPickedUp();
};
