// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone640SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone640SynthesisOrchestrator
 *
 * Master Milestone 640 Production Synthesis Orchestrator.
 * Validates Builds 636–640 across PRSGenesisGraphSubsystem, CANAnchorRegistrySubsystem, DualLayerSchemaContractAuditor, SemanticMentionCompletenessValidator, and Milestone 640 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone640SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone640")
	void RunMilestone640SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone640")
	int32 TotalBuildsCovered = 5;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone640")
	bool bSynthesisPassComplete = false;
};
