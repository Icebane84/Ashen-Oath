// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Crafting/AshenAlchemicalFieldWorkstationComponent.h"

UAshenAlchemicalFieldWorkstationComponent::UAshenAlchemicalFieldWorkstationComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	SelectedRecipeItem = EAlchemicalItemType::GloomwoodTripwire;
}
void UAshenAlchemicalFieldWorkstationComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenAlchemicalFieldWorkstationComponent::SelectRecipeDial(EAlchemicalItemType InItem)
{
	SelectedRecipeItem = InItem;
	UE_LOG(LogTemp, Log, TEXT("UAshenAlchemicalFieldWorkstationComponent: Clockwork Assembly Wheel selected recipe: %d"),
		static_cast<int32>(SelectedRecipeItem));
}

int32 UAshenAlchemicalFieldWorkstationComponent::GetCraftedItemCount(EAlchemicalItemType InItem) const
{
	// Default starting utility count
	return 2;
}
