// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone360SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone360SynthesisOrchestrator
 *
 * Milestone 360 Production Synthesis Orchestrator.
 * Validates Builds 351–360 across PrismaticRealmVeil, CompanionFatigue, CompanionTrustDivergence, ResonanceAnchoringSync, and AtmosphericCorruption.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone360SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone360")
	void RunMilestone360SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone360")
	int32 TotalBuildsCovered = 10;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone360")
	bool bSynthesisPassComplete = false;
};
