// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone550MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone550MasterSynthesisOrchestrator
 *
 * Master Milestone 550 Production Synthesis Orchestrator.
 * Validates Builds 536–550 across AlchemicalLanternComponent, AlchemicalTrapActor, AscensionChamberVolume, AudioOcclusionComponent, Milestone540SynthesisOrchestrator, CharacterStanceComponent, CompanionInterceptionComponent, ConsecratedCircleActor, DialogueSubsystem, EchoingWoundSubsystem, GarrettGrappleComponent, GeopoliticalResonanceSubsystem, InquisitorialAuditSubsystem, and Milestone 550 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone550MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone550")
	void RunMilestone550SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone550")
	int32 TotalBuildsCovered = 15;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone550")
	bool bSynthesisPassComplete = false;
};
