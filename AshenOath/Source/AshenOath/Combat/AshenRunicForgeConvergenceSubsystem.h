// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Combat/AshenRunicForgeTypes.h"
#include "AshenRunicForgeConvergenceSubsystem.generated.h"

/**
 * UAshenRunicForgeConvergenceSubsystem
 * 
 * Central world subsystem orchestrating Oathbringer's 5-tier ascension progression, 4-guard sigil socket inscriptions at campfire anvils, and flow hybrid finishers.
 */
UCLASS()
class ASHENOATH_API UAshenRunicForgeConvergenceSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenRunicForgeConvergenceSubsystem();

	/** Ascends Oathbringer to a higher tier */
	UFUNCTION(BlueprintCallable, Category = "Ashen|RunicForge")
	void AscendBladeTier(EOathbringerAscensionTier NewTier);

	/** Inscribes a sigil into a specific guard socket */
	UFUNCTION(BlueprintCallable, Category = "Ashen|RunicForge")
	void InscribeSigil(EGuardSigilSocket Socket, ESigilResonanceEffect Sigil);

	/** Executes flow resonance hybrid strike between previous and current guard */
	UFUNCTION(BlueprintCallable, Category = "Ashen|RunicForge")
	FFlowResonanceResult TriggerFlowResonance(EGuardSigilSocket GuardFrom, EGuardSigilSocket GuardTo);

	UFUNCTION(BlueprintPure, Category = "Ashen|RunicForge")
	EOathbringerAscensionTier GetAscensionTier() const { return EvolutionState.AscensionTier; }

	UFUNCTION(BlueprintPure, Category = "Ashen|RunicForge")
	ESigilResonanceEffect GetInscribedSigil(EGuardSigilSocket Socket) const;

	UFUNCTION(BlueprintPure, Category = "Ashen|RunicForge")
	float GetBaseDamageMultiplier() const { return EvolutionState.BaseDamageMultiplier; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|RunicForge")
	FOnOathbringerTierAscended OnOathbringerTierAscended;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|RunicForge")
	FOnGuardSigilInscribed OnGuardSigilInscribed;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|RunicForge")
	FOnFlowResonanceFinisherExecuted OnFlowResonanceFinisherExecuted;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|RunicForge")
	FOnRunicSeamGlyphsUpdated OnRunicSeamGlyphsUpdated;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|RunicForge")
	FOathbringerEvolutionState EvolutionState;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|RunicForge")
	TMap<EGuardSigilSocket, FGuardSigilSocketData> GuardSockets;

private:
	void UpdateTierMultipliers();
};
