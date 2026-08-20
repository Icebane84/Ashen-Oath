// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone200SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone200SynthesisOrchestrator
 *
 * Milestone 200 Master Production Synthesis Pass.
 * Validates the complete 200-build C++ architecture across all subsystems,
 * companion AI components, GAS abilities, UMG widgets, and QA automation suites.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone200SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone200")
	void RunMilestone200MasterSynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone200")
	int32 TotalBuildsCovered = 200;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone200")
	bool bMasterSynthesisPassComplete = false;
};
