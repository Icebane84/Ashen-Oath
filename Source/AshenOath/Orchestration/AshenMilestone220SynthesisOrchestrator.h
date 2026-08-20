// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone220SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone220SynthesisOrchestrator
 *
 * Milestone 220 Master Production Synthesis Pass.
 * Validates Builds 211–220 across sanctuary beacons, ground shatter strike, sanity corrupted audio, soul perk nodes, and radiant burst abilities.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone220SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone220")
	void RunMilestone220SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone220")
	int32 TotalBuildsCovered = 10;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone220")
	bool bSynthesisPassComplete = false;
};
