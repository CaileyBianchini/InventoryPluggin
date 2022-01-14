// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.generated.h"

UCLASS()
class PROGRAMMINGDEMO_API AInteractable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractable();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:

	//Functions for making items interactable
	UFUNCTION(BlueprintCallable)
	virtual void Interact();

	UFUNCTION(BlueprintCallable)
	virtual void InteractableInventoryImp();

	//All items will presumbaly have a static mesh when picked up
	UPROPERTY(EditAnywhere, Category = "Item Properties")
	class UStaticMeshComponent* ItemMesh;

	//All items will presumbaly have a help text 
	UPROPERTY(EditAnywhere, Category = "Item Properties")
	FString ItemHelpText;
};
