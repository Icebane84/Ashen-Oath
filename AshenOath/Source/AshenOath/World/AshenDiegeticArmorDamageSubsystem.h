// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenDiegeticArmorDamageSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnArmorDegradedSignature, FName, LimbSlot, float, RemainingIntegrityPercent);

/**
 * UAshenDiegeticArmorDamageSubsystem
 *
 * World Subsystem projecting armor degradation into 3 distinct layers:
 * Layer 1 (Combat): Damage mitigation reduction.
 * Layer 2 (VFX/Material): Material Parameter Collection mesh destruction & scratch blend.
 * Layer 3 (Dialogue): NPC reaction to ruined armor.
 */
UCLASS()
class ASHENOATH_API UAshenDiegeticArmorDamageSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|ArmorDamage")
	void ApplyArmorLimbDamage(FName LimbSlot, float DamageAmount);

	UFUNCTION(BlueprintPure, Category = "AshenOath|ArmorDamage")
	float GetLimbArmorIntegrity(FName LimbSlot) const;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ArmorDamage|Events")
	FOnArmorDegradedSignature OnArmorDegraded;

private:
	TMap<FName, float> ArmorIntegrityMap;
};
