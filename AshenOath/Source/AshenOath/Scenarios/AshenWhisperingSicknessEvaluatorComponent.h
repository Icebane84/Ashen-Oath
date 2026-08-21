// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario2SentinelsGambitTypes.h"
#include "AshenWhisperingSicknessEvaluatorComponent.generated.h"

/**
 * UAshenWhisperingSicknessEvaluatorComponent
 * 
 * Modulates post-process sickness desaturation and White Flame silhouette contrast.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWhisperingSicknessEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenWhisperingSicknessEvaluatorComponent();

	/** Evaluates Whispering Sickness post-process overlay weight */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario2|VFX")
	float EvaluateSicknessOverlayWeight(float VaultContaminationPercent) const;
};
