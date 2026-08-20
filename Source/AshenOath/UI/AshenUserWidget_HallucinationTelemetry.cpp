// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_HallucinationTelemetry.h"

void UAshenUserWidget_HallucinationTelemetry::UpdateHallucinationTelemetry(int32 StateEnum, int32 Phantoms)
{
	ActiveHallucinationStateEnum = StateEnum;
	ActivePhantomCount = Phantoms;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_HallucinationTelemetry: Hallucination State: %d | Phantom Foes: %d"),
		ActiveHallucinationStateEnum, ActivePhantomCount);
}
