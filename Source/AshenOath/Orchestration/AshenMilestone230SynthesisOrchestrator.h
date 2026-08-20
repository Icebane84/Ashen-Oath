// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone230SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone230SynthesisOrchestrator
 *
 * Milestone 230 Master Production Synthesis Pass.
 * Validates Builds 221–230 across weapon enchantments, grappling hook mobility, dynamic audio occlusion, dungeon door locks, and environmental hazards.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone230SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone230")
	void RunMilestone230SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone230")
	int32 TotalBuildsCovered = 10;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone230")
	bool bSynthesisPassComplete = false;
};
