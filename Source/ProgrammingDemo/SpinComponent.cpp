// Fill out your copyright notice in the Description page of Project Settings.


#include "SpinComponent.h"

// Sets default values for this component's properties
USpinComponent::USpinComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USpinComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USpinComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	AActor* owner = GetOwner();


	FRotator rotation = owner->GetActorRotation();

	rotation.Yaw += YawSpeed * DeltaTime;
	rotation.Pitch += PitchSpeed * DeltaTime;
	rotation.Roll += RollSpeed * DeltaTime;
	owner->SetActorRotation(rotation);
}

void USpinComponent::SetRotationSpeed(FRotator Speed)
{
	YawSpeed = Speed.Yaw;
	PitchSpeed = Speed.Pitch;
	RollSpeed = Speed.Roll;
}

