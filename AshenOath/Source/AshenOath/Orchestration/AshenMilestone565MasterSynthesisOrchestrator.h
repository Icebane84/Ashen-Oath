// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone565MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone565MasterSynthesisOrchestrator
 *
 * Master Milestone 565 Production Synthesis Orchestrator.
 * Validates Builds 551–565 across LorekeeperMemoryWeaverComponent, NarrativeWeaponHistorySubsystem, TrustAccumulationComponent, PAAMasterOrchestrator, Milestone555SynthesisOrchestrator, PurifierFlameBladeComponent, SerafinaBurnoutComponent, SerafinaSanctuaryRingComponent, SerafinaTransferenceComponent, UnchainedCameraModifier, UnreliableNarratorClueComponent, UnreliableNarratorCombatComponent, UnreliableNarratorEnvironmentalVolume, and Milestone 565 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone565MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone565")
	void RunMilestone565SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone565")
	int32 TotalBuildsCovered = 15;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone565")
	bool bSynthesisPassComplete = false;
};
