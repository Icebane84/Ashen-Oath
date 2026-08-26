// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "World/AshenDynamicRubbleTypes.h"
#include "AshenUserWidget_RubbleHazardHUD.generated.h"

/**
 * UAshenUserWidget_RubbleHazardHUD
 * 
 * UMG widget displaying overhead masonry strain percentages, falling telegraph radius alerts, and rubble demolition interaction prompts.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_RubbleHazardHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_RubbleHazardHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates the displayed hazard telemetry */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Rubble")
	void UpdateHazardHUD(const FMasonryHazardVector& Hazard, const FRubblePhysicsClusterVector& Cluster);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Rubble")
	FMasonryHazardVector DisplayedHazard;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Rubble")
	FRubblePhysicsClusterVector DisplayedCluster;
};
