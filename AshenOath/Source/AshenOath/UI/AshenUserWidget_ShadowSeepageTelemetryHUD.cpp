// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_ShadowSeepageTelemetryHUD.h"

void UAshenUserWidget_ShadowSeepageTelemetryHUD::UpdateTelemetryHUD(EShadowSeepagePhase InPhase, float InNormalOffset, float InSparksRate)
{
	DisplayedPhase = InPhase;
	DisplayedNormalOffset = InNormalOffset;
	DisplayedSparksSpawnRate = InSparksRate;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_ShadowSeepageTelemetryHUD: Telemetry HUD -> Phase: %d, Offset: %.2f, Sparks Rate: %.1f"),
		static_cast<int32>(DisplayedPhase), DisplayedNormalOffset, DisplayedSparksSpawnRate);
}
