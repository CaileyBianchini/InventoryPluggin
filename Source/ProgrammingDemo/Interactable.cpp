// Fill out your copyright notice in the Description page of Project Settings.

#include "Interactable.h"
#include "ProgrammingDemo.h"


// Sets default values
AInteractable::AInteractable()
{
 	
	ItemHelpText = FString("Press E To Interact.");
}

// Called when the game starts or when spawned
void AInteractable::BeginPlay()
{
	Super::BeginPlay();
	
}

void AInteractable::Interact()
{

}

void AInteractable::InteractableInventoryImp()
{
	GLog->Log("Interactable base class: Interact() Oop, You shouldn't be seeing this!");
}

//void AInteractable::InteractableToInventory()
//{
//	GLog->Log("Interactable base class: Interact() Oop, You shouldn't be seeing this!");
//}

