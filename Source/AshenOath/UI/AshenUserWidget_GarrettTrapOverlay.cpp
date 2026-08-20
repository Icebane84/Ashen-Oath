// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_GarrettTrapOverlay.h"

void UAshenUserWidget_GarrettTrapOverlay::UpdateTrapTelemetry(int32 Traps, bool bReady)
{
	ActiveTrapsCount = Traps;
	bGrappleReady = bReady;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_GarrettTrapOverlay: Active Traps: %d | Grapple Ready: %s"),
		ActiveTrapsCount, bGrappleReady ? TEXT("YES") : TEXT("NO"));
}
