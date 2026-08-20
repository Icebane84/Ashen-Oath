// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 586: Ashen Armor Scuff Decal Subsystem

#include "AshenArmorScuffDecalSubsystem.h"
#include "GameFramework/Actor.h"

void UAshenArmorScuffDecalSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenArmorScuffDecalSubsystem: Initialized — Armor Scuff Decal Subsystem ONLINE."));
}

void UAshenArmorScuffDecalSubsystem::ProjectArmorScuffDecal(AActor* TargetActor, float DamageWearAmount)
{
	if (!TargetActor) return;

	OnArmorScuffApplied.Broadcast(TargetActor, DamageWearAmount);

	UE_LOG(LogTemp, Log, TEXT("UAshenArmorScuffDecalSubsystem: ARMOR SCUFF DECAL PROJECTED -> Actor '%s' (Wear Amount: %.1f)."),
		*TargetActor->GetName(), DamageWearAmount);
}
