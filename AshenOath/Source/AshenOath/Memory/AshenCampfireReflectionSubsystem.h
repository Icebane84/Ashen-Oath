// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Memory/AshenCampfireTypes.h"
#include "Combat/AshenOathbringerMetallurgyTypes.h"
#include "AshenCampfireReflectionSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCampfirePhaseChanged, ECampfireReflectionPhase, NewPhase);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCampfireMemoryIntegrated, const FCampfireIntegrationResult&, Result);

/**
 * UAshenCampfireReflectionSubsystem
 *
 * The Sanctuary Subsystem managing campfire reflection, memory crystallization through the
 * 4 Interpretive Lenses, paying off Integration Debt, and triggering Oathbringer's metallurgical morph.
 * (PATCH v158.17.0 / PRS-001-SPEC-SOUL-001)
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenCampfireReflectionSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/** Begins a campfire sanctuary rest sequence */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Campfire")
	void BeginCampfireRest();

	/** Transitions the reflection state machine */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Campfire")
	void SetReflectionPhase(ECampfireReflectionPhase NewPhase);

	/**
	 * Integrates buffered memory fragments through the chosen Interpretive Lens.
	 * Atomically clears Integration Debt (Debt -> 0.0) and applies permanent bonuses.
	 */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Campfire")
	FCampfireIntegrationResult IntegrateBufferedMemories(EInterpretiveLens ChosenLens);

	/** Adds a memory fragment to the pending campfire queue */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Campfire")
	void QueueMemoryFragment(const FCampfireMemoryFragment& Fragment);

	/** Accessor for the current campfire state phase */
	UFUNCTION(BlueprintPure, Category = "Ashen|Campfire")
	ECampfireReflectionPhase GetCurrentPhase() const { return CurrentPhase; }

	/** Accessor for pending fragments */
	UFUNCTION(BlueprintPure, Category = "Ashen|Campfire")
	const TArray<FCampfireMemoryFragment>& GetPendingFragments() const { return PendingFragments; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Campfire")
	FOnCampfirePhaseChanged OnCampfirePhaseChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Campfire")
	FOnCampfireMemoryIntegrated OnCampfireMemoryIntegrated;

private:
	ECampfireReflectionPhase CurrentPhase = ECampfireReflectionPhase::Completed;
	TArray<FCampfireMemoryFragment> PendingFragments;

	EOathbringerMetallurgicalTier DeriveTargetMetallurgyTier(float Resolve, float Corruption, float Debt) const;
};
