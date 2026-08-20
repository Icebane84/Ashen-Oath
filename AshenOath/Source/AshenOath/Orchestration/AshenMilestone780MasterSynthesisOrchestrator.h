// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone780MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone780MasterSynthesisOrchestrator
 *
 * Master Milestone 780 Production Synthesis Orchestrator.
 * Validates Builds 776–780 across OathbringerGreatswordScuffComponent, OathbringerResonanceWaveAbility, OathbringerEdgeSharpeningCalculator, OathbringerWeaponRackWorldActor, and Milestone 780 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone780MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone780")
	void RunMilestone780SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone780")
	int32 TotalBuildsCovered = 5;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone780")
	bool bSynthesisPassComplete = false;
};
