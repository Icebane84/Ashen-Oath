// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_GarrettTrapOverlay.generated.h"

/**
 * UAshenUserWidget_GarrettTrapOverlay
 * UMG overlay tracking active trap network status and gadget cooldowns.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_GarrettTrapOverlay : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	int32 ActiveTrapsCount = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	bool bGrappleReady = true;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateTrapTelemetry(int32 Traps, bool bReady);
};
