// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenConstellationRespecComponent.h"
#include "AshenSoulPerkActivationComponent.h"
#include "AshenOath_ImprintBufferComponent.h"
#include "GameFramework/Actor.h"

UAshenConstellationRespecComponent::UAshenConstellationRespecComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenConstellationRespecComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenConstellationRespecComponent::RefundPerkNode(FName PerkID)
{
	AActor* OwnerActor = GetOwner();
	if (!OwnerActor) return false;

	UAshenSoulPerkActivationComponent* PerkComp = OwnerActor->FindComponentByClass<UAshenSoulPerkActivationComponent>();
	UAshenOath_ImprintBufferComponent* ImprintComp = OwnerActor->FindComponentByClass<UAshenOath_ImprintBufferComponent>();

	if (!PerkComp || !PerkComp->IsPerkActive(PerkID))
	{
		return false;
	}

	PerkComp->DeactivatePerk(PerkID);
	const int32 ImprintCost = 1;

	if (ImprintComp)
	{
		ImprintComp->AddImprint(EImprintType::Identity, 1.0f);
	}

	OnRespecExecuted.Broadcast(PerkID, ImprintCost);
	UE_LOG(LogTemp, Warning, TEXT("UAshenConstellationRespecComponent: Refunded perk '%s' (+%d imprints)."), *PerkID.ToString(), ImprintCost);

	return true;
}

int32 UAshenConstellationRespecComponent::ResetAllConstellationPerks()
{
	AActor* OwnerActor = GetOwner();
	if (!OwnerActor) return 0;

	UAshenSoulPerkActivationComponent* PerkComp = OwnerActor->FindComponentByClass<UAshenSoulPerkActivationComponent>();
	if (!PerkComp) return 0;

	TArray<FName> PerksToRefund = PerkComp->ActivePerkIds.Array();
	int32 TotalRefunded = 0;

	for (const FName& PerkID : PerksToRefund)
	{
		if (RefundPerkNode(PerkID))
		{
			TotalRefunded++;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UAshenConstellationRespecComponent: Complete respec executed! Refunded %d total perk nodes."), TotalRefunded);
	return TotalRefunded;
}
