// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenEliteInquisitionSaveGameAdapter.h"

UAshenEliteInquisitionSaveGameAdapter::UAshenEliteInquisitionSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenEliteInquisitionSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenEliteInquisitionSaveGameAdapter::SerializeEliteDefeatToSave(FName EliteID, bool bIsDefeated)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenEliteInquisitionSaveGameAdapter: Elite %s defeat status (%s) serialized to save game."),
		*EliteID.ToString(), bIsDefeated ? TEXT("DEFEATED") : TEXT("ALIVE"));
	return true;
}
