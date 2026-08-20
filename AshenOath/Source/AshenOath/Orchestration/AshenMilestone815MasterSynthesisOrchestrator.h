// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone815MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone815MasterSynthesisOrchestrator
 * Master GameInstance Orchestrator auditing builds 1 to 815 across all 20 vertical slice domains.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone815MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Orchestration")
	bool ValidateMilestone815Integrity() const;
};
