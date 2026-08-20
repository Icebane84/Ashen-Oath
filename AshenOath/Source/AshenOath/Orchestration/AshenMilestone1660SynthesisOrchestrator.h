// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1660SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1660SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1660 Living Oath tooling verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1660SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1660Synthesis();
private:
	bool bMilestone1660Validated = false;
};
