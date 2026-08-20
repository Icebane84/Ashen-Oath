// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 521: Ashen Diegetic Armor Scuff Decal Subsystem

#include "AshenDiegeticArmorScuffDecalSubsystem.h"

void UAshenDiegeticArmorScuffDecalSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticArmorScuffDecalSubsystem: Initialized — Armor Scuff Decal Engine ONLINE."));
}

void UAshenDiegeticArmorScuffDecalSubsystem::ApplyArmorScuffImpact(AActor* TargetActor, float DamageAmount)
{
	if (!TargetActor) return;

	const float ScuffPercent = FMath::Clamp(DamageAmount / 2.0f, 0.0f, 100.0f);
	OnArmorScuffApplied.Broadcast(TargetActor, ScuffPercent);

	UE_LOG(LogTemp, Warning, TEXT("UAshenDiegeticArmorScuffDecalSubsystem: ARMOR SCUFF APPLIED -> '%s' (Severity: %.1f%%)."),
		*TargetActor->GetName(), ScuffPercent);
}
