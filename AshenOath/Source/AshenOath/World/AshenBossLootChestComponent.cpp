// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 251: Ashen Boss Loot Chest Component

#include "AshenBossLootChestComponent.h"
#include "AshenOath_CurrencyComponent.h"

UAshenBossLootChestComponent::UAshenBossLootChestComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	EmberRewardAmount = 500.0f;
	RareItemRewardID = FName("Item_GreywatchPaladinSword");
	bIsOpened = false;
}

void UAshenBossLootChestComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenBossLootChestComponent::OpenChest(AActor* OpeningActor, FName RequiredKeyID)
{
	if (bIsOpened) return false;

	bIsOpened = true;

	if (OpeningActor)
	{
		UAshenOath_CurrencyComponent* CurrencyComp = OpeningActor->FindComponentByClass<UAshenOath_CurrencyComponent>();
		if (CurrencyComp)
		{
			CurrencyComp->AddEmbers(EmberRewardAmount);
		}
	}

	OnChestOpened.Broadcast(EmberRewardAmount, RareItemRewardID);

	UE_LOG(LogTemp, Warning, TEXT("UAshenBossLootChestComponent: BOSS CHEST OPENED by '%s' — Awarded %.0f Embers and Rare Item '%s'."),
		OpeningActor ? *OpeningActor->GetName() : TEXT("Unknown"), EmberRewardAmount, *RareItemRewardID.ToString());

	return true;
}
