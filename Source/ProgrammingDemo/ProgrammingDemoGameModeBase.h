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

	virtual void BeginPlay() override;

public:

	AProgrammingDemoGameModeBase();

	enum ENUMState : uint8
	{
		HS_Ingame,
		HS_Inventory,		//after this was supposed to be HS_Shop_General
		HS_Item
	};
	
	//Checks the hud  state, and then calls applyHUD accordingly to apply whatever hud we want
	void ApplyHUDChanges();

	//getter for HUD state
	uint8 GetHUDEState();

	//setter for HUD state, applied new state and then calls ApplyHUDChanges()
	UFUNCTION(BlueprintCallable, Category = "HUD Function")
	void ChangeHUDState(uint8 NewState);

	//applies a hud to the screen, returns true if successful, false otherwise
	bool ApplyHUD(TSubclassOf<class UUserWidget> WidgetToApply, bool bShowMouseCursor, bool EnableClickEvents);

protected:

	uint8 HUDState;

	//the HUD to be shown ingame
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HUDWidgets", Meta = (BlueprintProtected = "true"))
		TSubclassOf<class UUserWidget> IngameHUDClass;

	//the HUD to be shown in the inventory
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HUDWidgets", Meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget> InventoryHUDClass;

	//Shop subclass taken out << DELETE ALL REFRENCES TO SHOP BEFORE FINAL

	UPROPERTY()
		class UUserWidget* CurrentWidget;

};
