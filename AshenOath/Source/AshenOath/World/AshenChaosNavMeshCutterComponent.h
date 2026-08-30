// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenChaosNavMeshCutterComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnChaosObstacleCreated, const FVector&, Location, float, Radius, bool, bRequiresParabolicVault);

/**
 * UAshenChaosNavMeshCutterComponent
 *
 * Captures Chaos fracture events, cuts dynamic NavMesh obstacle areas,
 * feeds ImmediateThreat into the normalized somatic manifolds, and
 * flags rubble volumes requiring +120uu parabolic vault trajectories.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenChaosNavMeshCutterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenChaosNavMeshCutterComponent();

	virtual void BeginPlay() override;

	/** Manually or via Chaos break event registers a dynamic rubble collapse */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|Destruction")
	void RegisterFractureRubbleCollapse(const FVector& ImpactLocation, float RubbleRadius, float RubbleHeight);

	/** Queries whether a target location is obstructed by dynamic rubble */
	UFUNCTION(BlueprintPure, Category = "Ashen Oath|Destruction")
	bool IsLocationObstructed(const FVector& QueryLocation, float ClearanceRadius = 50.0f) const;

	/** Queries whether a vault across this obstacle requires a parabolic elevation arc (+120uu) */
	UFUNCTION(BlueprintPure, Category = "Ashen Oath|Destruction")
	bool RequiresParabolicVault(const FVector& StartLoc, const FVector& TargetLoc) const;

	UFUNCTION(BlueprintPure, Category = "Ashen Oath|Destruction")
	float GetCurrentImmediateThreat() const { return CurrentImmediateThreat; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath|Destruction")
	FOnChaosObstacleCreated OnChaosObstacleCreated;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Destruction", meta = (ClampMin = "50.0", ClampMax = "2000.0"))
	float DefaultObstacleRadius = 250.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Destruction", meta = (ClampMin = "0.0", ClampMax = "1000.0"))
	float ParabolicElevationThreshold = 80.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath|Destruction")
	float CurrentImmediateThreat = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath|Destruction")
	TArray<FVector> ActiveRubbleLocations;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath|Destruction")
	TArray<float> ActiveRubbleRadii;
};
