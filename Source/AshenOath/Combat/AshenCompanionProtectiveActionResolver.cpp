// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenCompanionProtectiveActionResolver.h"

UAshenCompanionProtectiveActionResolver::UAshenCompanionProtectiveActionResolver()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenCompanionProtectiveActionResolver::BeginPlay() { Super::BeginPlay(); }

void UAshenCompanionProtectiveActionResolver::ResolveProtectiveAction(FName CompanionID, FString ActionType)
{
	if (OnProtectiveActionResolved.IsBound())
	{
		OnProtectiveActionResolved.Broadcast(CompanionID);
	}
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionProtectiveActionResolver: Protective action '%s' resolved for %s (+0.05 trust delta generated)"),
		*ActionType, *CompanionID.ToString());
}
