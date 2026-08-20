// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1580SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1580SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1580 Elite Inquisition tooling verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1580SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1580Synthesis();
private:
	bool bMilestone1580Validated = false;
};
