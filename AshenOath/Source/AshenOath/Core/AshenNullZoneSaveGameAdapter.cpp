// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenNullZoneSaveGameAdapter.h"

UAshenNullZoneSaveGameAdapter::UAshenNullZoneSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenNullZoneSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenNullZoneSaveGameAdapter::SaveFragmentState(FName FragmentID, bool bConsumed)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenNullZoneSaveGameAdapter: Saved Fragment '%s' (Consumed: %s)."),
		*FragmentID.ToString(), bConsumed ? TEXT("TRUE") : TEXT("FALSE"));
	return true;
}

bool UAshenNullZoneSaveGameAdapter::SaveAnchorState(FName AnchorID, bool bConsecrated)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenNullZoneSaveGameAdapter: Saved Anchor '%s' (Consecrated: %s)."),
		*AnchorID.ToString(), bConsecrated ? TEXT("TRUE") : TEXT("FALSE"));
	return true;
}
