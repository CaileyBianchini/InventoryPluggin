// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SpinComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROGRAMMINGDEMO_API USpinComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USpinComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void SetRotationSpeed(FRotator Speed);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float YawSpeed = 20.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float PitchSpeed = 20.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RollSpeed = 20.0f;
};
