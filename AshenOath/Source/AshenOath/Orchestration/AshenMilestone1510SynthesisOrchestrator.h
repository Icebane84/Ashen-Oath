// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1510SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1510SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1510 Advanced Combat core systems verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1510SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1510Synthesis();
private:
	bool bMilestone1510Validated = false;
};
