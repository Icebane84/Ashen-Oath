// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenMartyrsTitheComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMartyrTitheSacrificedSignature, float, SacrificedMaxHealth, float, PartyBuffMultiplier);

/**
 * UAshenMartyrsTitheComponent
 *
 * Altruistic mechanic allowing Kaelen to permanently sacrifice max health for permanent party combat boons
 * and companion trust recovery (+15.0% trust, +25% combat buff per 100 HP tithed).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMartyrsTitheComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMartyrsTitheComponent();

	/** Sacrifices a portion of Kaelen's Max Health, granting permanent party buffs and trust restoration */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|MartyrTithe")
	bool PerformMartyrSacrifice(float SacrificedMaxHealthAmount);

	UFUNCTION(BlueprintPure, Category = "AshenOath|MartyrTithe")
	float GetTotalSacrificedHealth() const { return TotalSacrificedHealth; }

	UFUNCTION(BlueprintPure, Category = "AshenOath|MartyrTithe")
	float GetPartyBuffMultiplier() const { return 1.0f + (TotalSacrificedHealth / 100.0f) * 0.25f; }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|MartyrTithe|Events")
	FOnMartyrTitheSacrificedSignature OnMartyrTitheSacrificed;

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|MartyrTithe")
	float TotalSacrificedHealth = 0.0f;
};
