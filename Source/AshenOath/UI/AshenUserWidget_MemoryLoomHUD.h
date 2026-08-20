// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Combat/AshenMemoryWeavingTypes.h"
#include "AshenUserWidget_MemoryLoomHUD.generated.h"

/**
 * UAshenUserWidget_MemoryLoomHUD
 * Diegetic HUD displaying active filament thread counts, tension meters, and live transference conversion telemetry.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_MemoryLoomHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	FWeavingThreadPayload DisplayPayload;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateLoomTelemetry(const FWeavingThreadPayload& InPayload);
};
