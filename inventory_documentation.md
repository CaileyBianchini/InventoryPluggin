INVENTORY SOURCE FILES AND FUNCTIONS

Files: MyCharacter.h & .cpp

Attributes

         Name: BeginPlay()
             Description: called when the game starts or when spawned
             Type:protected virtual void override
             Property:
         Name: AddItemToInventory(APickUp* Item)
             Description: adds item to the invetory
             Type:public bool
             Property:UFUNCTION(BlueprintCallable, Category = "Inventory Functions")
         Name: GetThumbnailAtInventorySlot(int32 Slot)
             Description: gets the thumbnail for a given inventory slot 
             Type:public UTexture2D*
             Property:UFUNCTION(BlueprintPure, Category = "Inventory Functions")
         Name: GivenNameAtInventorySlot(int32 Slot)
             Description: gets the items name for a given inventory slot
             Type:public FString
             Property: UFUNCTION(BlueprintPure, Category = "Inventory Functions")
         Name: UseItemAtInventory(int32 Slot)
             Description: use the item at a given slot
             Type:publiv void
             Property:UFUNCTION(BlueprintCallable, Category = "Inventory Functions")
         Name: SetInput()
             Description: this sets the input for opening invetory 
             Type:private void
             Property:
         Name: Interact()
             Description: checks for interactable items directly in front of the player using a linetrace - called per tick 
             Type:private void
             Property:


File:Interactable.h & .cpp

Attributes
	This is the base class of PickUp that tells both the item and player that the item is an interactable

         Name: AInteractable()
             Description: Sets defualt values for this actor's properties 
             Type:public
             Property:
         Name: BeginPlay()
             Description: called when the game starts or when spawned
             Type: virtual void override
         Name: Interact()
             Description: Function made for making items interactable  
             Type:public virtual void
	     Property: UFUNTION(BlueprintCallable)
         Name: InteractableInventoryImp()
             Description: This is the basde function for pickup
             Type:public virtual void
             Property:UFUNCTION(BlueprintCallable)
         Name: ItemMesh
             Description: all items will presumbaly have a static mesh when picked up 
             Type:public class UStaticMeshComponent*
             Property: UPROPERTY(EditAnywhere, Category = "Item Properties") 
         Name: ItemHelpText
             Description: All items will presumbaly have a help text
             Type:FString
             Property:UPROPERTY(EditAnywhere, Category = "Item Properties")

File:PickUp.h & .cpp

Attributes
this inherits from interactable and tells what the interactable actually does when picked up

         Name: APickUp()
             Description: sets defualt for values  
             Type: public
             Property:
         Name: BeginPlay()
             Description: called when the game starts or when spawned
             Type:protected virtual void override
             Property:
         Name: Use()
             Description: this is called to use item   
             Type: public void
             Property:UFUNCTION(BlueprintCallable)
         Name:UseImp()
             Description: this is similar to Use but its a implementation
             Type: public virtual void
             Property: UFUNCTION(BlueprintCallable)
         Name: OnPickedUp()
             Description: this item is called when Item is picked up
             Type:public void
             Property:























