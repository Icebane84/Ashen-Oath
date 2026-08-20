// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenCompanionIntentTypes.h"
#include "AshenSerafinaEmpathicIntentEvaluatorComponent.generated.h"

/**
 * UAshenSerafinaEmpathicIntentEvaluatorComponent
 * 
 * Serafina's empathic intent evaluation:
 * - High Grace -> Casts Golden Tether Sanctuary alongside Kaelen
 * - High Dysregulation -> Channels Empathic Transference to ground his soul
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaEmpathicIntentEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSerafinaEmpathicIntentEvaluatorComponent();

	/** Evaluates Serafina's empathic decision */
	UFUNCTION(BlueprintPure, Category = "Ashen|Companions|Serafina")
	FCompanionIntentEvaluationResult EvaluateSerafinaIntent(
		const FPlayerIntentTelemetrySnapshot& Telemetry,
		EIntentConfidenceTier ConfidenceTier) const;
};
