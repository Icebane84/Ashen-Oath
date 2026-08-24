// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario10Types.h"
#include "AshenSoulUnificationDirectorComponent.generated.h"

/**
 * UAshenSoulUnificationDirectorComponent
 * 
 * Coordinates the tripartite apotheosis buildup across 3 stages, triggering the consequence blast wave at 100% resonance.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSoulUnificationDirectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSoulUnificationDirectorComponent();

	/** Accumulates apotheosis resonance from party synchronized strikes */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Scenario10|Apotheosis")
	float AddResonance(float Amount01);

	/** Resets resonance */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Scenario10|Apotheosis")
	void ResetResonance();

	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario10|Apotheosis")
	float GetCurrentResonance01() const { return CurrentResonance01; }

	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario10|Apotheosis")
	bool IsApotheosisReady() const { return CurrentResonance01 >= 1.0f; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario10|Apotheosis")
	float CurrentResonance01 = 0.0f;
};
