// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone290SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone290SynthesisOrchestrator
 *
 * Milestone 290 Master Production Synthesis Pass.
 * Validates Builds 281–290 across vendor shops, sunfall nova, audio footsteps, secret passages, shadow steps, and boss aura pulse controllers.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone290SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone290")
	void RunMilestone290SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone290")
	int32 TotalBuildsCovered = 10;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone290")
	bool bSynthesisPassComplete = false;
};
