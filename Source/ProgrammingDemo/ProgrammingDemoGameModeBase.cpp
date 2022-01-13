// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProgrammingDemoGameModeBase.h"
#include "Inventory.h"
#include "MyCharacter.h"
#include "HUDInventory.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"//this is added for UGameplayStatics

//
//void AProgrammingDemoGameModeBase::BeginPlay()
//{
//	//As soon as the player enters the game, apply HUD to the screen, 
//	ApplyHUDChanges();
//}
//
//AProgrammingDemoGameModeBase::AProgrammingDemoGameModeBase()
//{
//	//Use our custom HUD class
//	HUDClass = AHUDInventory::StaticClass();
//
//	//Sets the default hudstate to be the ingame state
//	HUDState = ENUMState::HS_Ingame;
//}
//
//void AProgrammingDemoGameModeBase::ApplyHUDChanges()
//{
//	//remove the previous hud, since we're applying a new one
//	if (CurrentWidget != nullptr)
//	{
//		CurrentWidget->RemoveFromParent();
//	}
//
//	switch (HUDState)
//	{
//		case ENUMState::HS_Ingame:
//		{
//			ApplyHUD(IngameHUDClass, false, false);
//			break;
//		}
//		case ENUMState::HS_Inventory:
//		{
//			ApplyHUD(InventoryHUDClass, true, true);
//			break;
//		}
//		default:
//		{
//			ApplyHUD(IngameHUDClass, false, false);
//			break;
//		}
//	}
//}
//
//uint8 AProgrammingDemoGameModeBase::GetHUDEState()
//{
//	return HUDState;
//}
//
//void AProgrammingDemoGameModeBase::ChangeHUDState(uint8 NewState)
//{
//	HUDState = NewState;
//	ApplyHUDChanges();
//}
//
//bool AProgrammingDemoGameModeBase::ApplyHUD(TSubclassOf<class UUserWidget> WidgetToApply, bool bShowMouseCursor, bool EnableClickEvents)
//{
//	//get a reference to the player, and the controller
//	AMyCharacter* MyCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
//	APlayerController* MyController = GetWorld()->GetFirstPlayerController();
//
//	//Nullcheck whatever widget we're trying to apply
//	if (WidgetToApply != nullptr)
//	{
//		//Set mouse visibility and click events according to params
//		MyController->bShowMouseCursor = bShowMouseCursor;
//		MyController->bEnableClickEvents = EnableClickEvents;
//
//		//creates the widget
//		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), WidgetToApply);
//
//		if (CurrentWidget != nullptr)
//		{
//			CurrentWidget->AddToViewport();
//			return true;
//		}
//		else return false;
//	}
//	else return false;
//}
