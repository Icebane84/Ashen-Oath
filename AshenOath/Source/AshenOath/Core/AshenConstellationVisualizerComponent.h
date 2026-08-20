// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenConstellationVisualizerComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnConstellationVisualsRefreshedSignature, int32, ActiveNodeCount);

/**
 * UAshenConstellationVisualizerComponent
 *
 * Calculates 3D/2D visual rendering parameters for Soul Constellation identity tree nodes and connecting light lines.
 * Adjusts node emissive glow intensities based on unlocked perk states.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenConstellationVisualizerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenConstellationVisualizerComponent();

protected:
	virtual void BeginPlay() override;

public:
	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Constellation")
	float CalculateConstellationGlow(FName NodeID);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Constellation")
	void RefreshConstellationVisuals();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Constellation")
	int32 ActiveNodeCount = 0;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Constellation|Events")
	FOnConstellationVisualsRefreshedSignature OnVisualsRefreshed;
};
