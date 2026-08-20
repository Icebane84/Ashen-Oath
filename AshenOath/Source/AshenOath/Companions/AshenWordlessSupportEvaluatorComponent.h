// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenSomaticSilenceTypes.h"
#include "AshenWordlessSupportEvaluatorComponent.generated.h"

/**
 * UAshenWordlessSupportEvaluatorComponent
 * 
 * Evaluates whether high trust allows companions to execute proactive
 * actions before Kaelen even reaches the target location.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWordlessSupportEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenWordlessSupportEvaluatorComponent();

	/** Evaluates support command based on proximity to obstacles and trust */
	UFUNCTION(BlueprintPure, Category = "Ashen|Silence")
	FWordlessSupportCommand EvaluateSupportAction(
		FName CompanionName,
		float CompanionTrust,
		const FVector& KaelenLocation,
		const FVector& NearestObstacleLocation) const;
};
