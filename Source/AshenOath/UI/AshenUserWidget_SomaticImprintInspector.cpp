// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenUserWidget_SomaticImprintInspector.h"

void UAshenUserWidget_SomaticImprintInspector::RefreshSomaticImprintsDisplay(int32 ImprintCount)
{
	ActiveImprintCount = ImprintCount;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_SomaticImprintInspector: Displaying %d active somatic scar imprints."), ActiveImprintCount);
}
