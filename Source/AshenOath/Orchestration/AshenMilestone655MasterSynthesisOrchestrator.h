// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone655MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone655MasterSynthesisOrchestrator
 *
 * Master Milestone 655 Production Synthesis Orchestrator.
 * Validates Builds 636–655 across PRSGenesisGraphSubsystem, CANAnchorRegistrySubsystem, DualLayerSchemaContractAuditor, SemanticMentionCompletenessValidator, Milestone640SynthesisOrchestrator, CANFaithVsDoubtEvaluatorComponent, CANTriageBurdenEvaluatorComponent, CANGlassShieldProtocolComponent, CANEmpathicBurnoutComponent, CANAnchorsAutomationTest, CanonicalStatusDeprecationProtocol, SELTEventLogExporter, GraphUpdateConsistencyAuditor, UniversalMechanicBridgeAdapter, Milestone650MasterSynthesisOrchestrator, PRSNodeVisualizerAnchorActor, CanonicalAnchorLocusActor, FederatedLoreResolverSubsystem, AspectOrientedPatchController, and Milestone 655 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone655MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone655")
	void RunMilestone655SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone655")
	int32 TotalBuildsCovered = 20;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone655")
	bool bSynthesisPassComplete = false;
};
