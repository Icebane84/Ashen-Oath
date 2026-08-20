// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 354: Ashen Resonance Anchoring Sync Component

#include "AshenResonanceAnchoringSyncComponent.h"
#include "AshenOath_HealthComponent.h"

UAshenResonanceAnchoringSyncComponent::UAshenResonanceAnchoringSyncComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenResonanceAnchoringSyncComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenResonanceAnchoringSyncComponent::ExecuteSyncCombo(FName SyncComboID, AActor* CompanionPartner, AActor* TargetActor)
{
	if (SyncComboID.IsNone() || !CompanionPartner) return false;

	const float Damage = 550.0f;
	if (TargetActor)
	{
		UAshenOath_HealthComponent* TargetHealth = TargetActor->FindComponentByClass<UAshenOath_HealthComponent>();
		if (TargetHealth)
		{
			TargetHealth->ReceiveDamage(Damage, GetOwner());
		}
	}

	OnSyncComboExecuted.Broadcast(SyncComboID, Damage);

	UE_LOG(LogTemp, Warning, TEXT("UAshenResonanceAnchoringSyncComponent: DUAL SYNC COMBO '%s' EXECUTED with '%s' — Dealt %.0f Damage."),
		*SyncComboID.ToString(), *CompanionPartner->GetName(), Damage);

	return true;
}
