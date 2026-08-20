// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSoulPerkActivationComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPerkActivatedSignature, FName, PerkId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPerkDeactivatedSignature, FName, PerkId);

/**
 * UAshenSoulPerkActivationComponent
 *
 * Evaluates and applies passive statutory perks unlocked via the Soul Constellation identity tree.
 * Modifies character attributes (Max Poise, Alchemical Efficiency, Empathic Healing) in real time.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSoulPerkActivationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSoulPerkActivationComponent();

protected:
	virtual void BeginPlay() override;

public:
	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Perks")
	bool ActivatePerk(FName PerkId);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Perks")
	bool DeactivatePerk(FName PerkId);

	UFUNCTION(BlueprintPure, Category = "AshenOath|Perks")
	bool IsPerkActive(FName PerkId) const;

	// --- Active Perk Container ---
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Perks")
	TSet<FName> ActivePerkIds;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Perks|Events")
	FOnPerkActivatedSignature OnPerkActivated;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Perks|Events")
	FOnPerkDeactivatedSignature OnPerkDeactivated;

private:
	void ApplyPerkModifiers(FName PerkId, bool bApply);
};
