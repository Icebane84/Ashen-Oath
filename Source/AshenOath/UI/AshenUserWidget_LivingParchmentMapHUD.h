// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Narrative/AshenCartographicTypes.h"
#include "AshenUserWidget_LivingParchmentMapHUD.generated.h"

/**
 * UAshenUserWidget_LivingParchmentMapHUD
 * Diegetic full-screen parchment map widget displaying ink washes, golden thread sanctuary connections, and interactive memory pins.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_LivingParchmentMapHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	TArray<FJournalMapPin> RenderedPins;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void RefreshMapPins(const TArray<FJournalMapPin>& InPins);
};
