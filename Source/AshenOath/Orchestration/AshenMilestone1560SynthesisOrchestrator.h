// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1560SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1560SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1560 Campfire Rest tooling verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1560SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1560Synthesis();
private:
	bool bMilestone1560Validated = false;
};
