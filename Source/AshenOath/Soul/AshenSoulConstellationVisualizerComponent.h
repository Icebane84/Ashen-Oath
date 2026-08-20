// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSoulConstellationVisualizerComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnConstellationVisualsUpdatedSignature, int32, ActiveNodeCount, float, TotalGlowIntensity);

/**
 * UAshenSoulConstellationVisualizerComponent
 *
 * Drives ambient 3D particle links and node glow intensities in the Mindscape Soul Constellation space.
 * Updates glow weight and star connection beams based on unlocked perk count.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSoulConstellationVisualizerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSoulConstellationVisualizerComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|ConstellationVisualizer")
	void RefreshVisuals(int32 UnlockedNodesCount, float BaseGlowIntensity = 1.0f);

	UFUNCTION(BlueprintPure, Category = "AshenOath|ConstellationVisualizer")
	float GetTotalGlowIntensity() const { return TotalGlowIntensity; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|ConstellationVisualizer")
	float NodeGlowMultiplier = 0.15f;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ConstellationVisualizer|Events")
	FOnConstellationVisualsUpdatedSignature OnVisualsUpdated;

private:
	int32 ActiveNodeCount = 0;
	float TotalGlowIntensity = 1.0f;
};
