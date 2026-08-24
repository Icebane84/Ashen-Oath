// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "World/AshenChaosNavmeshTypes.h"
#include "AshenChaosNavmeshSubsystem.generated.h"

/**
 * UAshenChaosNavmeshSubsystem
 * 
 * Central world subsystem managing dynamic Chaos fracture debris clusters, dynamic navmesh cutting, and acoustic impact impulses.
 */
UCLASS()
class ASHENOATH_API UAshenChaosNavmeshSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenChaosNavmeshSubsystem();

	/** Registers a new structural fracture event and updates navmesh blocking */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Chaos")
	void RegisterFractureEvent(
		EChaosFractureSeverity Severity,
		EStructuralMaterialType Material,
		const FVector& Location,
		float ImpactJoules,
		float DebrisMassKg);

	/** Clears or pulverizes a debris cluster at given location */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Chaos")
	void ClearDebrisCluster(const FVector& Location);

	UFUNCTION(BlueprintPure, Category = "Ashen|Chaos")
	FChaosDebrisClusterVector GetLatestDebrisCluster() const { return LatestCluster; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Chaos")
	FOnChaosPillarFractured OnChaosPillarFractured;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Chaos")
	FOnNavmeshObstructionChanged OnNavmeshObstructionChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Chaos")
	FOnChaosSpatialAudioImpulse OnChaosSpatialAudioImpulse;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Chaos")
	FOnDebrisClusterCleared OnDebrisClusterCleared;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Chaos")
	FChaosDebrisClusterVector LatestCluster;
};
