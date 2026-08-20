// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenAlchemicalCraftingComponent.h"
#include "AshenOath_QuickbarComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"

UAshenAlchemicalCraftingComponent::UAshenAlchemicalCraftingComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	// Default starting ingredients
	IngredientPouch.Add(FName("SulfurDust"), 5);
	IngredientPouch.Add(FName("GhostbloomPetals"), 5);
	IngredientPouch.Add(FName("EmberAsh"), 5);
}

void UAshenAlchemicalCraftingComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenAlchemicalCraftingComponent::AddIngredient(FName IngredientId, int32 Quantity)
{
	if (Quantity <= 0) return;

	int32& CurrentAmount = IngredientPouch.FindOrAdd(IngredientId);
	CurrentAmount += Quantity;

	UE_LOG(LogTemp, Log, TEXT("UAshenAlchemicalCraftingComponent: Added %d x '%s' (Total: %d)"), Quantity, *IngredientId.ToString(), CurrentAmount);
}

int32 UAshenAlchemicalCraftingComponent::GetIngredientQuantity(FName IngredientId) const
{
	const int32* Found = IngredientPouch.Find(IngredientId);
	return Found ? *Found : 0;
}



bool UAshenAlchemicalCraftingComponent::CraftRecipe(FName RecipeId, AActor* PlayerPawn)
{
	if (!PlayerPawn || RecipeId.IsNone()) return false;

	UAshenOath_QuickbarComponent* Quickbar = PlayerPawn->FindComponentByClass<UAshenOath_QuickbarComponent>();
	if (!Quickbar) return false;

	const FName ReqIngredient(TEXT("SulfurDust"));
	if (GetIngredientQuantity(ReqIngredient) < 1)
	{
		OnItemCrafted.Broadcast(RecipeId, false);
		return false;
	}

	int32& Count = IngredientPouch.FindOrAdd(ReqIngredient);
	Count = FMath::Max(0, Count - 1);

	OnItemCrafted.Broadcast(RecipeId, true);
	UE_LOG(LogTemp, Warning, TEXT("UAshenAlchemicalCraftingComponent: Successfully crafted '%s'!"), *RecipeId.ToString());

	return true;
}
