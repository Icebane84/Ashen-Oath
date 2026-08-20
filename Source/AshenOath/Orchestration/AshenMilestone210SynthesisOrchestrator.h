// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone210SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone210SynthesisOrchestrator
 *
 * Milestone 210 Master Production Synthesis Pass.
 * Validates Builds 201–210 across companion synergy, fast travel map UI, audio reverb presets, and boss AV sequences.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone210SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone210")
	void RunMilestone210SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone210")
	int32 TotalBuildsCovered = 10;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone210")
	bool bSynthesisPassComplete = false;
};
