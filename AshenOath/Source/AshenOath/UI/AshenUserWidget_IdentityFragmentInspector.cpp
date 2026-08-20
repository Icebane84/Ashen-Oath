// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenUserWidget_IdentityFragmentInspector.h"

void UAshenUserWidget_IdentityFragmentInspector::RefreshIdentityFragmentList(int32 FragmentCount)
{
	TotalCollectedFragments = FragmentCount;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_IdentityFragmentInspector: Refreshed identity fragment list (%d fragments collected)."), TotalCollectedFragments);
}
