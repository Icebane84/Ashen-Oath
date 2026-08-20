// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1590SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1590SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1590 Elite Inquisition core systems verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1590SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1590Synthesis();
private:
	bool bMilestone1590Validated = false;
};
