// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

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
	Reach = 250.0f;
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CheckForInteractables();
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

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

void AMyCharacter::ToggleInventory()
{
}

void AMyCharacter::Interact()
{
}

void AMyCharacter::CheckForInteractables()
{
	//to linetrace, got the start and end traces
	FVector StartTrace = Camera->GetComponentLocation(); //Camera is whatever the name of the camera your using for your player
	FVector EndTrace = (Camera->GetForwardVector() * Reach) + StartTrace;

	//Declare a hitresult to store the raycast to hit in
	FHitResult HitResult;

	//Initializes the query params - Ignore the actor
	FCollisionQueryParams collisionQP;

	collisionQP.AddIgnoredActor(this);

	//cast the lime trace
	GetWorld()->LineTraceSingleByChannel(HitResult, StartTrace, EndTrace, ECC_WorldDynamic, collisionQP);

	AInteractable* PotentialInteractable = Cast<AInteractable>(HitResult.GetActor());


	if (PotentialInteractable == NULL)
	{
		HelpText = FString("");
		currentInteractable = nullptr;
		return;
	}

}

