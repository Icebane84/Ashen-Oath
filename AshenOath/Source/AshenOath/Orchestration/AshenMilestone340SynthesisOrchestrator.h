// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone340SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone340SynthesisOrchestrator
 *
 * Milestone 340 Production Synthesis Orchestrator.
 * Validates Builds 336–340 across ShatteredVirtues, InnerDemons, ScarsOfCorruption, and PenitentsPath rituals.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone340SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone340")
	void RunMilestone340SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone340")
	int32 TotalBuildsCovered = 5;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone340")
	bool bSynthesisPassComplete = false;
};
