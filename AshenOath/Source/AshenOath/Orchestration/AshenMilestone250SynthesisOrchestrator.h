// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone250SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone250SynthesisOrchestrator
 *
 * MILESTONE 250 MASTER PRODUCTION SYNTHESIS ORCHESTRATOR.
 * Synthesizes and verifies ALL 250 C++ BUILDS across combat abilities, companion AI, GAS attributes, UI overlays, audio subsystems, and world mechanics.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone250SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone250")
	void RunMilestone250SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone250")
	int32 TotalBuildsCovered = 250;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone250")
	bool bMasterSynthesisComplete = false;
};
