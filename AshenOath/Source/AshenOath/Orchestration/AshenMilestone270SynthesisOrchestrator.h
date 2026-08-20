// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone270SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone270SynthesisOrchestrator
 *
 * Milestone 270 Master Production Synthesis Pass.
 * Validates Builds 261–270 across pressure plates, assassination dash, insanity hallucinations, rotating bridges, sacred beams, and audio reverb zones.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone270SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone270")
	void RunMilestone270SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone270")
	int32 TotalBuildsCovered = 10;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone270")
	bool bSynthesisPassComplete = false;
};
