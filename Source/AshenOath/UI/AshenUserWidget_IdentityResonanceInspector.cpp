// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenUserWidget_IdentityResonanceInspector.h"

void UAshenUserWidget_IdentityResonanceInspector::RefreshIdentityFragmentDisplay(int32 FragmentCount)
{
	ActiveIdentityFragmentCount = FragmentCount;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_IdentityResonanceInspector: Refreshed identity fragment display (%d active fragments)."), ActiveIdentityFragmentCount);
}
