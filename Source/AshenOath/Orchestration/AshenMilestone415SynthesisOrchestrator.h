// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone415SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone415SynthesisOrchestrator
 *
 * Master Milestone 415 Production Synthesis Orchestrator.
 * Validates Builds 401–415 across DynamicEncounterScaler, SpatialAudioOcclusion, MemoryThreadSanctuary, CompanionComboFinisher, MemoryThreadJournal, GarrettPoisonSmokeGrid, RegionalCorruptionSpread, SanctuaryVendorEconomy, KaelenEarthshakerExecution, and DynamicDialogueConsequence.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone415SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone415")
	void RunMilestone415SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone415")
	int32 TotalBuildsCovered = 15;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone415")
	bool bSynthesisPassComplete = false;
};
