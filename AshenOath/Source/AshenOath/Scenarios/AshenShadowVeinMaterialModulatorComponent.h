// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario1CauterizedHeartTypes.h"
#include "AshenShadowVeinMaterialModulatorComponent.generated.h"

/**
 * UAshenShadowVeinMaterialModulatorComponent
 * 
 * Computes dynamic shadow-vein opacity and camera trauma jitter frequency based on proximity and debt.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenShadowVeinMaterialModulatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenShadowVeinMaterialModulatorComponent();

	/** Evaluates shadow vein material scalar on gauntlets */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario1|VFX")
	float EvaluateShadowVeinOpacity(float IntegrationDebt, float Corruption) const;

	/** Evaluates camera trauma jitter frequency */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario1|VFX")
	float EvaluateTraumaJitterFrequency(float BossProximityCentimeters, float MaxProximity) const;
};
