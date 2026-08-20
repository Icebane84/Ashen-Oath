// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/AshenMapViewModel.h"
#include "AshenUserWidget_CartographersJournalMap.generated.h"

UCLASS(Abstract)
class ASHENOATH_API UAshenUserWidget_CartographersJournalMap : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateMapRenderData(const FAshenMapRenderData& RenderData);

	UFUNCTION(BlueprintPure, Category = "Ashen Oath | UI")
	float GetActiveSootAlpha() const { return ActiveSootAlpha; }

	UFUNCTION(BlueprintPure, Category = "Ashen Oath | UI")
	float GetActiveInkBleed() const { return ActiveInkBleed; }

private:
	float ActiveSootAlpha = 0.0f;
	float ActiveInkBleed = 0.0f;
};
