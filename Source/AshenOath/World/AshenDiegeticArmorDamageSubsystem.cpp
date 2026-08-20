// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 466: Ashen Diegetic Armor Damage Subsystem

#include "AshenDiegeticArmorDamageSubsystem.h"

void UAshenDiegeticArmorDamageSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ArmorIntegrityMap.Add(FName(TEXT("Chestplate")), 100.0f);
	ArmorIntegrityMap.Add(FName(TEXT("Pauldrons")), 100.0f);
	ArmorIntegrityMap.Add(FName(TEXT("Greaves")), 100.0f);

	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticArmorDamageSubsystem: Initialized — Diegetic Armor Damage Subsystem ONLINE."));
}

void UAshenDiegeticArmorDamageSubsystem::ApplyArmorLimbDamage(FName LimbSlot, float DamageAmount)
{
	if (LimbSlot.IsNone()) return;

	float Current = ArmorIntegrityMap.Contains(LimbSlot) ? ArmorIntegrityMap[LimbSlot] : 100.0f;
	float NewIntegrity = FMath::Clamp(Current - DamageAmount, 0.0f, 100.0f);
	ArmorIntegrityMap.Add(LimbSlot, NewIntegrity);

	OnArmorDegraded.Broadcast(LimbSlot, NewIntegrity);

	UE_LOG(LogTemp, Warning, TEXT("UAshenDiegeticArmorDamageSubsystem: ARMOR LIMB DAMAGE -> '%s' Integrity: %.1f%% (-%.0f)."),
		*LimbSlot.ToString(), NewIntegrity, DamageAmount);
}

float UAshenDiegeticArmorDamageSubsystem::GetLimbArmorIntegrity(FName LimbSlot) const
{
	return ArmorIntegrityMap.Contains(LimbSlot) ? ArmorIntegrityMap[LimbSlot] : 100.0f;
}
