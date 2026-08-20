// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenCompanionIntentTypes.h"
#include "AshenGarrettIntentEvaluatorComponent.generated.h"

/**
 * UAshenGarrettIntentEvaluatorComponent
 * 
 * Garrett's tactical intent evaluation:
 * - Low Trust + Rescue -> CautiousFlankCompensate ("God damn it Kaelen, I said wait!")
 * - High Trust + Rescue -> ShoulderToShoulderCommit ("Damn it. There goes our Mr. Hero again.")
 * - High Trust + Blind Wrath -> ConfrontationalIntervene ("No. Not this time.")
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGarrettIntentEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGarrettIntentEvaluatorComponent();

	/** Evaluates Garrett's tactical decision based on player telemetry and trust */
	UFUNCTION(BlueprintPure, Category = "Ashen|Companions|Garrett")
	FCompanionIntentEvaluationResult EvaluateGarrettIntent(
		const FPlayerIntentTelemetrySnapshot& Telemetry,
		EIntentConfidenceTier ConfidenceTier) const;
};
