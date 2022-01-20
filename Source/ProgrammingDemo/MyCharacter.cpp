// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "PickUp.h"
#include "Inventory.h"
//#include "ProgrammingDemoGameModeBase.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);

	SpringArm->SetRelativeLocationAndRotation(
		FVector(0.0f, 0.0f, 90.0f),
		FRotator(0.0f, -10.0f, 0.0f)
	);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	//FOR EXAMPLE//
	Reach = 500.000f;
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	//This sets the limit of the inventory, can customize
	Inventory.SetNum(8);

	currentInteractable = nullptr;
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CheckForInteractables();
}


void AMyCharacter::MoveForward(float AxisValue)
{
	FRotator rotator = FRotator(0.0f, GetControlRotation().Yaw, 0.0f);
	FVector forward = rotator.Vector();
	AddMovementInput(forward, AxisValue);

	bIsMovingX = AxisValue != 0.0f;
	bUseControllerRotationYaw = bIsMovingX || bIsMovingY;
}

void AMyCharacter::MoveRight(float AxisValue)
{
	FRotator rotator = FRotator(0.0f, GetControlRotation().Yaw, 0.0f);
	FVector right = FVector::CrossProduct(FVector::UpVector, rotator.Vector());
	AddMovementInput(right, AxisValue);

	bIsMovingY = AxisValue != 0.0f;
	bUseControllerRotationYaw = bIsMovingX || bIsMovingY;
}

//THIS IS APART OF THE EXAMPLE//

void AMyCharacter::SetInput()
{
	check(InputComponent);

	InputComponent->BindAction("InteractItem", IE_Pressed, this, &AMyCharacter::Interact);
}

void AMyCharacter::SetupPlayerInputComponent(UInputComponent* Input)
{
	check(Input);

	Input->BindAction("InteractItem", IE_Pressed, this, &AMyCharacter::Interact);
}

bool AMyCharacter::AddItemToInventory(APickUp* Item)
{
	if (Item != NULL)
	{
		const int32 AvailableSlot = Inventory.Find(nullptr); //Find first slot with a nullptr in it

		if (AvailableSlot != INDEX_NONE)
		{
			Inventory[AvailableSlot] = Item;
			return true;
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Inventory full!"));
			return false;
		}

	}
	else return false;
}

UTexture2D* AMyCharacter::GetThumbnailAtInventorySlot(int32 Slot)
{
	if (Inventory[Slot] != NULL)
	{
		return Inventory[Slot]->PickUpThumbnail;
	}
	else return nullptr;
}

FString AMyCharacter::GivenNameAtInventorySlot(int32 Slot)
{
	if (Inventory[Slot] != NULL)
	{
		return Inventory[Slot]->ItemName;
	}
	return FString("Empty");
}

void AMyCharacter::UseItemAtInventorySlot(int32 Slot)
{

	if (Inventory[Slot] != NULL)
	{
		Inventory[Slot]->UseImp();
		Inventory[Slot] = NULL; //deletes item from inventory - can set up a system of multi uses
	}

}

void AMyCharacter::Interact()
{
	//to test
	GLog->Log("Got to Interact\n");

	if (currentInteractable != nullptr) 
	{
		currentInteractable->InteractableInventoryImp();
		//to test
		GLog->Log("passed the currentInteractable check\n");
		
	}
	else
	{
		//to test
		GLog->Log("did not pass the currentInteractable check\n");
	}
}

void AMyCharacter::CheckForInteractables()
{
	//to linetrace, got the start and end traces
	FVector StartTrace = Camera->GetComponentLocation(); //Camera is whatever the name of the camera your using for your player
	FVector EndTrace = StartTrace + Camera->GetForwardVector() * Reach;

	//Declare a hitresult to store the raycast to hit in
	FHitResult HitResult;

	//Initializes the query params - Ignore the actor
	FCollisionQueryParams collisionQP;

	collisionQP.AddIgnoredActor(this);

	//cast the lime trace
	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartTrace, EndTrace, ECC_Visibility, collisionQP))
	{
		if (APickUp* PotentialInteractable = Cast<APickUp>(HitResult.GetActor()))
		{
			currentInteractable = PotentialInteractable;
			HelpText = PotentialInteractable->ItemHelpText;
			//to test
			GLog->Log("potential interactable is there\n");
				return;
		}
		GLog->Log("potential interactable is null\n");
		return;
	}

	if (GetWorld() == NULL)
	{
		GLog->Log("there is no world\n");
		return;
	}

	GLog->Log("didnt even get to GetWorld()\n");
	return;


	//if (PotentialInteractable == nullptr)
	//{
	//	HelpText = FString("");
	//	currentInteractable = nullptr;
	//	//to test
	//	GLog->Log("potential interactable is null\n");
	//	return;
	//}
	//else
	//{
	//	currentInteractable = PotentialInteractable;
	//	HelpText = PotentialInteractable->ItemHelpText;
	//	//to test
	//	GLog->Log("potential interactable is there\n");
	//}
}

