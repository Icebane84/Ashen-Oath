// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenUserWidget_CartographersJournalMap.h"

void UAshenUserWidget_CartographersJournalMap::UpdateMapRenderData(const FAshenMapRenderData& RenderData)
{
	ActiveSootAlpha = RenderData.ParchmentSootAlpha;
	ActiveInkBleed = RenderData.InkBleedIntensity;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_CartographersJournalMap: Updated map render data. Soot=%.2f, InkBleed=%.2f"), ActiveSootAlpha, ActiveInkBleed);
}
