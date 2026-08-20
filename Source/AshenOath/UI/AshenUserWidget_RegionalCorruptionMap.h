// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_RegionalCorruptionMap.generated.h"

/**
 * UAshenUserWidget_RegionalCorruptionMap
 *
 * UMG backing widget rendering world map corruption heatmaps and zone risk levels.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_RegionalCorruptionMap : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateCorruptionMapDisplay(FName ZoneID, float CorruptionPercentage);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName DisplayedZoneID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DisplayedCorruptionPercentage = 0.0f;
};
