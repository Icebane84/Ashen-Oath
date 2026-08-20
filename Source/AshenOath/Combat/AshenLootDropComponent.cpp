// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenLootDropComponent.h"
#include "AshenOath_CurrencyComponent.h"
#include "AshenAlchemicalCraftingComponent.h"
#include "GameFramework/Actor.h"

UAshenLootDropComponent::UAshenLootDropComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenLootDropComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenLootDropComponent::TriggerLootDrop(AActor* KillerActor)
{
	if (!KillerActor) return;

	AActor* EnemyOwner = GetOwner();

	// Grant Embers
	if (UAshenOath_CurrencyComponent* Currency = KillerActor->FindComponentByClass<UAshenOath_CurrencyComponent>())
	{
		Currency->AddEmbers(EmberRewardAmount);
		UE_LOG(LogTemp, Warning, TEXT("UAshenLootDropComponent: Enemy '%s' dropped %.0f Embers to '%s'!"),
			EnemyOwner ? *EnemyOwner->GetName() : TEXT("Enemy"), EmberRewardAmount, *KillerActor->GetName());
	}

	// Grant Alchemical Reagents
	if (!AlchemicalReagentId.IsNone())
	{
		if (UAshenAlchemicalCraftingComponent* Crafting = KillerActor->FindComponentByClass<UAshenAlchemicalCraftingComponent>())
		{
			Crafting->AddIngredient(AlchemicalReagentId, ReagentQuantity);
			UE_LOG(LogTemp, Log, TEXT("UAshenLootDropComponent: Granted %d x '%s' reagent."),
				ReagentQuantity, *AlchemicalReagentId.ToString());
		}
	}

	OnLootDropped.Broadcast(EnemyOwner, EmberRewardAmount, AlchemicalReagentId);
}
