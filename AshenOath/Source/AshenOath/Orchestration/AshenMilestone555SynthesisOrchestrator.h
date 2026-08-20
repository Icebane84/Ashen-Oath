// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone555SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone555SynthesisOrchestrator
 *
 * Milestone 555 Production Synthesis Orchestrator.
 * Validates Builds 551–555 across LorekeeperMemoryWeaverComponent, NarrativeWeaponHistorySubsystem, TrustAccumulationComponent, PAAMasterOrchestrator, and Milestone 555 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone555SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone555")
	void RunMilestone555SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone555")
	int32 TotalBuildsCovered = 5;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone555")
	bool bSynthesisPassComplete = false;
};
