// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Narrative/AshenLivingJournalConsequenceTypes.h"
#include "AshenUserWidget_MemoryConstellationMapHUD.generated.h"

/**
 * UAshenUserWidget_MemoryConstellationMapHUD
 * 3D Cartographer's map widget dissolving from geographical topography into the glowing Tripartite Constellation graph upon maximum zoom-out.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_MemoryConstellationMapHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float MapZoomLevel = 1.0f; // 0.0 (Topography) to 1.0 (Constellation)

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	int32 ActiveGoldLeyConduits = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	int32 ActiveObsidianFractures = 0;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateConstellationMap(float Zoom, int32 GoldConduits, int32 ObsidianFractures);
};
