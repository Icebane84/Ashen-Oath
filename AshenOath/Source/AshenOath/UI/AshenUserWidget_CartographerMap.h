// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/AshenCartographerMapViewModel.h"
#include "AshenUserWidget_CartographerMap.generated.h"

/**
 * UAshenUserWidget_CartographerMap
 * Master UMG Widget executing 60 FPS Slate render pass drawing for geography, travel spines, memory nodes, and companion marginalia.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_CartographerMap : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Map UI")
	UAshenCartographerMapViewModel* MapViewModel = nullptr;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Map UI")
	void InitializeMapWidget(UAshenCartographerMapViewModel* InViewModel);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Map UI")
	void Execute60FPSSlateRenderPass();
};
