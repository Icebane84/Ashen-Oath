// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_MemoryLoomHUD.h"

void UAshenUserWidget_MemoryLoomHUD::UpdateLoomTelemetry(const FWeavingThreadPayload& InPayload)
{
	DisplayPayload = InPayload;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_MemoryLoomHUD: Loom HUD -> Threads: %d | Tension: %.2f | State: %d"),
		DisplayPayload.ActiveThreadCount, DisplayPayload.TensionScalar, static_cast<int32>(DisplayPayload.TensionState));
}
