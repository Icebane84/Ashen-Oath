// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenResonanceMatrixCalculator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnResonanceSynergyCalculatedSignature, float, SynergyMultiplier, int32, ActiveSynergyCount);

/**
 * UAshenResonanceMatrixCalculator
 *
 * Calculates pairwise identity node synergy bonuses across unlocked Constellation perks.
 * When adjacent nodes (e.g. UnshakeableStance + VitalResonance) are active simultaneously,
 * applies a 1.15x - 1.30x synergy multiplier to statutory attributes.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenResonanceMatrixCalculator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenResonanceMatrixCalculator();

protected:
	virtual void BeginPlay() override;

public:
	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Constellation")
	float CalculateResonanceMultiplier(const TSet<FName>& UnlockedPerks);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Constellation")
	float CurrentSynergyMultiplier = 1.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Constellation")
	int32 ActiveSynergyCount = 0;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Constellation|Events")
	FOnResonanceSynergyCalculatedSignature OnResonanceSynergyCalculated;
};
