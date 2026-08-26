// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "World/AshenDynamicRubbleTypes.h"
#include "AshenDynamicRubblePhysicsSubsystem.generated.h"

/**
 * UAshenDynamicRubblePhysicsSubsystem
 * 
 * Central world subsystem managing Chaos physical fracture events, collapsing masonry telegraphs, and rubble clearing.
 */
UCLASS()
class ASHENOATH_API UAshenDynamicRubblePhysicsSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenDynamicRubblePhysicsSubsystem();

	/** Applies structural strain damage to overhead masonry */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Rubble")
	void ApplyStructuralStrain(float StrainDelta);

	/** Clears rubble using a demolition tool */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Rubble")
	void DemolishRubble(EDemolitionToolType ToolType, float AppliedForce);

	UFUNCTION(BlueprintPure, Category = "Ashen|Rubble")
	FMasonryHazardVector GetHazardState() const { return CurrentHazard; }

	UFUNCTION(BlueprintPure, Category = "Ashen|Rubble")
	FRubblePhysicsClusterVector GetClusterState() const { return CurrentCluster; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Rubble")
	FOnMasonryCollapseStateChanged OnMasonryCollapseStateChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Rubble")
	FOnRubbleDemolished OnRubbleDemolished;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Rubble")
	FOnFallingHazardTelegraphed OnFallingHazardTelegraphed;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Rubble")
	FOnRubbleNavmeshUpdated OnRubbleNavmeshUpdated;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Rubble")
	FMasonryHazardVector CurrentHazard;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Rubble")
	FRubblePhysicsClusterVector CurrentCluster;
};
