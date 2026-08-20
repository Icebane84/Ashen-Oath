// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone795MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone795MasterSynthesisOrchestrator
 * Master GameInstance Orchestrator auditing builds 1 to 795 across all 20 vertical slice domains.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone795MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Orchestration")
	bool ValidateMilestone795Integrity() const;
};
