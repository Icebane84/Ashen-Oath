// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario9Types.h"
#include "AshenTelekineticBridgeDirectorComponent.generated.h"

/**
 * UAshenTelekineticBridgeDirectorComponent
 * 
 * Manages telekinetic bridge manifestation, stability decay over 10 seconds, and resonant harmonic frequency maintenance.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTelekineticBridgeDirectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTelekineticBridgeDirectorComponent();

	/** Manifests a telekinetic bridge spanning a chasm */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Scenario9|Bridge")
	void ManifestBridge(float DurationSeconds);

	/** Ticks bridge decay and returns remaining stability [0.0 to 1.0] */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Scenario9|Bridge")
	float DecayBridge(float DeltaSeconds);

	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario9|Bridge")
	float GetStability01() const { return CurrentStability01; }

	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario9|Bridge")
	bool IsBridgeActive() const { return CurrentStability01 > 0.0f; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario9|Bridge")
	float CurrentStability01 = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario9|Bridge")
	float TotalLifespanSeconds = 10.0f;
};
