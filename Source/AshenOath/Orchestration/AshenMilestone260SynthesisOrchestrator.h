// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone260SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone260SynthesisOrchestrator
 *
 * Milestone 260 Master Production Synthesis Pass.
 * Validates Builds 251–260 across boss loot chests, Serafina holy light rays, dynamic weather audio, dungeon lever switches, whirlwind executions, and boss phase particle effects.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone260SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone260")
	void RunMilestone260SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone260")
	int32 TotalBuildsCovered = 10;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone260")
	bool bSynthesisPassComplete = false;
};
