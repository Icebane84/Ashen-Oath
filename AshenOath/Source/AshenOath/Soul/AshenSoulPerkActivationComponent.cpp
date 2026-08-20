// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenSoulPerkActivationComponent.h"
#include "AshenOath_PoiseComponent.h"
#include "AshenOath_HealthComponent.h"
#include "GameFramework/Actor.h"

UAshenSoulPerkActivationComponent::UAshenSoulPerkActivationComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSoulPerkActivationComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenSoulPerkActivationComponent::ActivatePerk(FName PerkId)
{
	if (PerkId.IsNone() || ActivePerkIds.Contains(PerkId))
	{
		return false;
	}

	ActivePerkIds.Add(PerkId);
	ApplyPerkModifiers(PerkId, true);

	OnPerkActivated.Broadcast(PerkId);
	UE_LOG(LogTemp, Warning, TEXT("UAshenSoulPerkActivationComponent: Activated perk '%s'!"), *PerkId.ToString());

	return true;
}

bool UAshenSoulPerkActivationComponent::DeactivatePerk(FName PerkId)
{
	if (!ActivePerkIds.Contains(PerkId))
	{
		return false;
	}

	ActivePerkIds.Remove(PerkId);
	ApplyPerkModifiers(PerkId, false);

	OnPerkDeactivated.Broadcast(PerkId);
	UE_LOG(LogTemp, Log, TEXT("UAshenSoulPerkActivationComponent: Deactivated perk '%s'."), *PerkId.ToString());

	return true;
}

bool UAshenSoulPerkActivationComponent::IsPerkActive(FName PerkId) const
{
	return ActivePerkIds.Contains(PerkId);
}

void UAshenSoulPerkActivationComponent::ApplyPerkModifiers(FName PerkId, bool bApply)
{
	AActor* OwnerActor = GetOwner();
	if (!OwnerActor) return;

	if (PerkId == FName("Perk_UnshakeableStance"))
	{
		if (UAshenOath_PoiseComponent* Poise = OwnerActor->FindComponentByClass<UAshenOath_PoiseComponent>())
		{
			float CurrentMax = Poise->GetMaxPoise();
			float Delta = CurrentMax * 0.25f; // +25% Max Poise
			Poise->SetMaxPoise(bApply ? CurrentMax + Delta : CurrentMax - Delta);
		}
	}
	else if (PerkId == FName("Perk_VitalResonance"))
	{
		if (UAshenOath_HealthComponent* Health = OwnerActor->FindComponentByClass<UAshenOath_HealthComponent>())
		{
			float CurrentMax = Health->GetMaxHealth();
			float Delta = 25.0f; // +25 HP
			Health->SetMaxHealth(bApply ? CurrentMax + Delta : CurrentMax - Delta);
		}
	}
}
