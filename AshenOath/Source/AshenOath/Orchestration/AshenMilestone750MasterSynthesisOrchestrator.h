// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone750MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone750MasterSynthesisOrchestrator
 *
 * Master Milestone 750 Production Synthesis Orchestrator.
 * Validates Builds 741–750 across IntegrativeMemoryPassCompilerComponent, HermeneuticFragmentationCalculator, WhisperingVoidErosionVolume, MemoryConstellationLensComponent, MemoryWeavingAutomationTest, MemoryNodeAnchorRegistrySubsystem, MemoryPalaceConstellationVFXAnchorActor, NyxHallucinationPromptAbility, MemoryPalaceTraversalPriorityDirector, and Milestone 750 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone750MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone750")
	void RunMilestone750SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone750")
	int32 TotalBuildsCovered = 10;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone750")
	bool bSynthesisPassComplete = false;
};
