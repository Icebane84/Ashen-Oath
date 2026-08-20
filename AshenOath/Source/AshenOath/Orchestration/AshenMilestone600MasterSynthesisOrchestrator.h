// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone600MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone600MasterSynthesisOrchestrator
 *
 * Master Milestone 600 Production Synthesis Orchestrator.
 * Validates Builds 596–600 across DiegeticJournalSubsystem, DiegeticFieldJournalWidget, EquipmentInspectionWidget, CampBehaviorInspectorWidget, and Milestone 600 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone600MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone600")
	void RunMilestone600SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone600")
	int32 TotalBuildsCovered = 5;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone600")
	bool bSynthesisPassComplete = false;
};
