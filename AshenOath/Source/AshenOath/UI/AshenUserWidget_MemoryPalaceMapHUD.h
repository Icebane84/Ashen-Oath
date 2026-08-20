// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Memory/AshenMemoryPalaceGraphTypes.h"
#include "AshenUserWidget_MemoryPalaceMapHUD.generated.h"

/**
 * UAshenUserWidget_MemoryPalaceMapHUD
 * Somatic UI widget rendering the interactive 3D/2D node constellation map and unsealed trauma branches.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_MemoryPalaceMapHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	int32 TotalNodesDiscovered = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	int32 TotalBridgesRebuilt = 0;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void RefreshMapDisplay(int32 InNodes, int32 InBridges);
};
