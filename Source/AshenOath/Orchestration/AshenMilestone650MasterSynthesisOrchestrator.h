// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone650MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone650MasterSynthesisOrchestrator
 *
 * Master Milestone 650 Production Synthesis Orchestrator.
 * Validates Builds 641–650 across CANFaithVsDoubtEvaluatorComponent, CANTriageBurdenEvaluatorComponent, CANGlassShieldProtocolComponent, CANEmpathicBurnoutComponent, CanonicalStatusDeprecationProtocol, SELTEventLogExporter, GraphUpdateConsistencyAuditor, UniversalMechanicBridgeAdapter, and Milestone 650 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone650MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone650")
	void RunMilestone650SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone650")
	int32 TotalBuildsCovered = 10;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone650")
	bool bSynthesisPassComplete = false;
};
