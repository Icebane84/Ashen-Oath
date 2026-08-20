// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone280SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone280SynthesisOrchestrator
 *
 * Milestone 280 Master Production Synthesis Pass.
 * Validates Builds 271–280 across keycards, poison smoke grids, hallucination VFX, destructible walls, ground shatter bursts, and boss health bar controllers.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone280SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone280")
	void RunMilestone280SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone280")
	int32 TotalBuildsCovered = 10;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone280")
	bool bSynthesisPassComplete = false;
};
