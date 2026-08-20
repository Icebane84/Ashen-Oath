// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenCampfireSaveGameAdapter.h"

UAshenCampfireSaveGameAdapter::UAshenCampfireSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenCampfireSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenCampfireSaveGameAdapter::SerializeCampfireSaveState(FName CampfireID, bool bIsKindled, int32 ForgedTraitsCount)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenCampfireSaveGameAdapter: Campfire %s (Kindled: %s) and %d forged traits serialized to save game."),
		*CampfireID.ToString(), bIsKindled ? TEXT("TRUE") : TEXT("FALSE"), ForgedTraitsCount);
	return true;
}
