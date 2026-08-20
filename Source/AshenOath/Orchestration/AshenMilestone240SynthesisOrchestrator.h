// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone240SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone240SynthesisOrchestrator
 *
 * Milestone 240 Master Production Synthesis Pass.
 * Validates Builds 231–240 across dungeon trapdoors, flash powder, spatial voice barks, boss phase banners, paranoia attribute sets, Shroud-Knight boss logic, and companion trust accumulation.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone240SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone240")
	void RunMilestone240SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone240")
	int32 TotalBuildsCovered = 10;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone240")
	bool bSynthesisPassComplete = false;
};
