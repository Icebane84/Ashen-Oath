// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1630SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1630SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1630 Party Finisher core systems verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1630SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1630Synthesis();
private:
	bool bMilestone1630Validated = false;
};
