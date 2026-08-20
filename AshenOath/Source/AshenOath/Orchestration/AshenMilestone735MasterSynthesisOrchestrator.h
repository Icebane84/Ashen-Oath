// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone735MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone735MasterSynthesisOrchestrator
 * Master Synthesis Orchestrator for Master Batch #36 (Builds 716-735).
 * Audits pre-existing component connections to FSoulStateVector across somatic, world, companion, combat, and perception domains.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone735MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Orchestration")
	bool AuditMasterBatch735Integrity() const;
};
