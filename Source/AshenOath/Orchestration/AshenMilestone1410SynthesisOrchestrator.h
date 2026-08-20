// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1410SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1410SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1410 Soul Rehabilitation core systems verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1410SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1410Synthesis();
private:
	bool bMilestone1410Validated = false;
};
