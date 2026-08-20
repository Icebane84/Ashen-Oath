// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 653: Ashen Federated Lore Resolver Subsystem

#include "AshenFederatedLoreResolverSubsystem.h"

void UAshenFederatedLoreResolverSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalLoreQueriesResolved = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenFederatedLoreResolverSubsystem: Initialized — Federated Lore Resolver Subsystem ONLINE."));
}

FString UAshenFederatedLoreResolverSubsystem::ResolveFederatedLore(FName EntityID, bool bIsLoreQuery)
{
	TotalLoreQueriesResolved++;
	const FString Result = bIsLoreQuery
		? FString::Printf(TEXT("PRS-001 Canonical Lore Authority -> Entity '%s'"), *EntityID.ToString())
		: FString::Printf(TEXT("C++ Engine Mechanic Authority -> Entity '%s'"), *EntityID.ToString());

	OnLoreResolved.Broadcast(EntityID, Result, bIsLoreQuery);

	UE_LOG(LogTemp, Warning, TEXT("UAshenFederatedLoreResolverSubsystem: FEDERATED LORE RESOLVED -> '%s' (Authority: %s | Total: %d)."),
		*EntityID.ToString(), bIsLoreQuery ? TEXT("PRS-001 LORE") : TEXT("C++ MECHANIC"), TotalLoreQueriesResolved);

	return Result;
}
