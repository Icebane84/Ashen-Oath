// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone875MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone875MasterSynthesisOrchestrator
 * Master GameInstance Orchestrator auditing builds 1 to 875.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone875MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Orchestration")
	bool ValidateMilestone875Integrity() const;
};
