// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ProgrammingDemoGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PROGRAMMINGDEMO_API AProgrammingDemoGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	enum ENUMState : uint8
	{
		HS_Ingame,
		HS_Inventory,		//after this was supposed to be HS_Shop_General
		HS_Weapon
	};
	
	//Checks the hud  state, and then calls applyHUD accordingly to apply whatever hud we want
	void ApplyHUDChanges();

	//getter for HUD state
	uint8 GetHUDEState();

	UFUNCTION(BlueprintCallable, Category = "HUD Function")
	//setter for HUD state, applied new state and then calls ApplyHUDChanges()
	void ChangeHUDState(uint8 NewState);
};
