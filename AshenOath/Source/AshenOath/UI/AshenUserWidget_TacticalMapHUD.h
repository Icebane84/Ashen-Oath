// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "World/AshenTacticalMapTypes.h"
#include "AshenUserWidget_TacticalMapHUD.generated.h"

/**
 * UAshenUserWidget_TacticalMapHUD
 * 
 * Full-screen interactive cartographic parchment map displaying fog-of-war masks, attuned beacon pins, and fast travel route selectors.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_TacticalMapHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_TacticalMapHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates the displayed map waypoints and selected node */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Map")
	void UpdateMapHUD(const TArray<FTacticalWaypointVector>& Waypoints, const FString& SelectedWaypointId);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Map")
	TArray<FTacticalWaypointVector> DisplayedWaypoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Map")
	FString ActiveSelectedWaypointId = TEXT("Waypoint_Hearth_01");
};
