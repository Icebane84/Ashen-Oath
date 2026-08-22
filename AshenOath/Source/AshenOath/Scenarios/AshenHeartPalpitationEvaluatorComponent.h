// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario5WeepingMireTypes.h"
#include "AshenHeartPalpitationEvaluatorComponent.generated.h"

/**
 * UAshenHeartPalpitationEvaluatorComponent
 * 
 * Modulates DualSense haptic pulse frequency (BPM) and adaptive trigger resistance during Unchained states.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenHeartPalpitationEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenHeartPalpitationEvaluatorComponent();

	/** Computes heart rate BPM during combat */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario5")
	float EvaluateHeartRateBPM(EUnchainedVesselPhase Phase, float StressPercent) const;
};
