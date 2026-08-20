// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone390SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone390SynthesisOrchestrator
 *
 * Milestone 390 Production Synthesis Orchestrator.
 * Validates Builds 381–386 across SoulRemnantsAbsorbCrafting, DynamicWorldEvents, TSCTargeting, CompanionDivergenceResolution, and TacticalTargeting UI.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone390SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone390")
	void RunMilestone390SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone390")
	int32 TotalBuildsCovered = 6;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone390")
	bool bSynthesisPassComplete = false;
};
