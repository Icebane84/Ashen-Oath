// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone855MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone855MasterSynthesisOrchestrator
 * Master GameInstance Orchestrator auditing builds 1 to 855 across all 20 vertical slice domains.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone855MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Orchestration")
	bool ValidateMilestone855Integrity() const;
};
