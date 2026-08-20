// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Soul/AshenWorldToMindscapeZoomEvaluatorComponent.h"

UAshenWorldToMindscapeZoomEvaluatorComponent::UAshenWorldToMindscapeZoomEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenWorldToMindscapeZoomEvaluatorComponent::UpdateMapZoomLevel(float ZoomScale)
{
	if (ZoomScale >= 2.5f)
	{
		bInMindscapeMode = true;
		ConstellationBlendAlpha = FMath::Clamp((ZoomScale - 2.5f) / 1.5f, 0.0f, 1.0f);
	}
	else
	{
		bInMindscapeMode = false;
		ConstellationBlendAlpha = 0.0f;
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenWorldToMindscapeZoomEvaluatorComponent: ZoomScale=%.2f, MindscapeMode=%s, Alpha=%.2f"),
		ZoomScale, bInMindscapeMode ? TEXT("TRUE") : TEXT("FALSE"), ConstellationBlendAlpha);
}
