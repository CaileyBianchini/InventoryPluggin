// Fill out your copyright notice in the Description page of Project Settings.

#include "PickUp.h"
#include "ProgrammingDemo.h"
#include "Components/StaticMeshComponent.h"
#include "MyCharacter.h" //this is the class that deals with player input movements
#include "Kismet/GameplayStatics.h"//this is added for UGameplayStatics


APickUp::APickUp()
{
	//Set up the mesh for the pickup, set up item name, help text and item value
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pickup Mesh"));
	ItemMesh->SetSimulatePhysics(true);

	ItemName = FString("Item Name");
	ItemHelpText = FString("Press E to pick up"); //can change to whatever pickup button is
	Value = 0;
}

void APickUp::BeginPlay()
{
	/*ItemHelpText = FString::Printf(TEXT("%s: Press E to pick up."), ItemName);*/
	ItemHelpText = FString("%s: Press E to pick up " + ItemName);
}

void APickUp::Use()
{
	//you can put whtever you want right here
}

void APickUp::InteractableInventoryImp()
{
	AMyCharacter* Character = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	
	if (Character->AddItemToInventory(this))
	{
		OnPickedUp();
		GLog->Log("character was picked up \n");
	}
}

void APickUp::UseImp()
{
	GLog->Log("Use() from base PickUp class. YOU SHOULD NOT SEE THIS \n");
}

void APickUp::OnPickedUp()
{
	ItemMesh->SetVisibility(false); //replace with DestroyComponent() optional
	ItemMesh->SetSimulatePhysics(false);
	ItemMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}
