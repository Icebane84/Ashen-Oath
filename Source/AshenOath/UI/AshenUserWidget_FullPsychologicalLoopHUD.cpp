// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 433: Ashen Full Psychological Loop HUD UMG Widget

#include "AshenUserWidget_FullPsychologicalLoopHUD.h"

void UAshenUserWidget_FullPsychologicalLoopHUD::UpdateLoopTelemetry(int32 StageMask, float SoulDebt, float TrustScore, float CorruptionLevel)
{
	ActiveStageMask = StageMask;
	TelemetrySoulDebt = SoulDebt;
	TelemetryTrustScore = TrustScore;
	TelemetryCorruptionLevel = CorruptionLevel;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_FullPsychologicalLoopHUD: Telemetry updated — Mask: 0x%02X (Soul Debt: %.1f, Trust: %.1f, Corruption: %.1f)."),
		StageMask, SoulDebt, TrustScore, CorruptionLevel);
}
