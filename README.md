# ProgrammingDemo - Inventory

## Summary
 A pluggin to make it easier to implemnt inventory

## Buttons
> **Property**  | **Value**
> ---------------|--------------------------------
> W            | Walks forward
> S             | Walks backward
> A             | Walks Left
> D             | Walks Right
> E             | Pick up items
> Q             | Open Inventory
> Click Slot| Uses item in slot

## How To Implement

>Setting Up Your Interactables

1. make PickUp as a blueprint
2. Put your wanted item mesh into the pickup item.
3. Put your wanted values in the details

> Setting Up Player

1. put ActionInput node you will dedicate for opening inventory
2. put node called "Get Player Controller"
3. get node "Create Widget" and connect first 2 nodes to it
4. get node "Add to Viewport" and connect "Create Widget"s values to it
5. add a "Set Mouse Cursor" amd connect to veiwport and connect "Get Player Controller"
   to the target value in the Set
6. get "Set Input Node UI Only", conect "Get Player Controller" and add that to
   Set Input's Player Controller. Grab the return value of Create Widget and put that value 
   into Set Inputs In Widget to Focus


> Set Inventory Widgets

1. use button for the slots and put image inside of the button : this is for the slot and thumbnail
2. put text under the button : this is for the name of the item
3. go to the button and click the texture for the image in button
	> input image of that detail < 
4. at the output in details, cretae a valubale called "ReturnValue" and set the type as "Slate Brush"
5. you will then create a function called "GetThumbnail" while inside the blueprint
6. go inside of the GetThumbnail function
7. go to details, add input valubale called "Slots" and its type will be interger
8. add output valubale called Thumbnail and type will be a slate brush
9. get node "Get Player Character" connect it to a node called "Cast to MyCharcter"
10. Simplify the cast
11. connect that cast node to a node called "GetThumbnailAtInventorySlot" (from MyCharacter code)
12. connect the GetThumnail Slot value and connect it to "GetThumbnailAtInventorySlot"
13. connect that node to a node called "Make Brush into Texture"
14. connect that node to the return node
15. go back to the blueprint and call the "GetThumbnail" function and connect the three nodes
    with the getter in between
16. repeat steps 1- 4 and step 15 for each slot you make. The value in the Onclicked "GetThumbnail" 
    for valubale "Slots" will increment for each slot you make
17. you will do the same thing for the text but with "getItemNameAtInventorySlot" and different naming
    and value types 
18. In OnClicked for each button create a function called "useItem"
19. get node "Get Player Character" connect it to a node called "Cast to MyCharcter"
20. Simplify the cast
21. grab node called "Use Item At Inventory Slot" (from code) and connect values
22. go back to blueprint and at OnClicked and connect the fuction "useItem" to it
23. repeat for each node while incremating


