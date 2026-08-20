// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1650SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1650SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1650 Bestiary Finisher core systems verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1650SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1650Synthesis();
private:
	bool bMilestone1650Validated = false;
};
