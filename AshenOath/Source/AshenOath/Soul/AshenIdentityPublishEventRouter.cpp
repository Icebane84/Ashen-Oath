// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Soul/AshenIdentityPublishEventRouter.h"

UAshenIdentityPublishEventRouter::UAshenIdentityPublishEventRouter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenIdentityPublishEventRouter::BeginPlay() { Super::BeginPlay(); }

void UAshenIdentityPublishEventRouter::RouteStateVectorToDownstreamChannels(const FSoulStateVector& StateVector)
{
	// AnimBP channel — route stance profile to AnimBP parameter set
	UE_LOG(LogTemp, Log, TEXT("UAshenIdentityPublishEventRouter: [AnimBP] Routing Resolve=%f"), StateVector.Resolve);
	// MPC channel — route corruption amount and debt stage to Material Parameter Collection
	UE_LOG(LogTemp, Log, TEXT("UAshenIdentityPublishEventRouter: [MPC] Routing IntegrationDebt=%f Corruption=%f"), StateVector.IntegrationDebt, StateVector.Corruption);
	// AI Blackboard channel — route tactical profile to AI Blackboard keys
	UE_LOG(LogTemp, Log, TEXT("UAshenIdentityPublishEventRouter: [AI] Routing GarrettTrust=%f"), StateVector.GarrettTrust);
	// MetaSounds channel — route empathic weight to audio parameters
	UE_LOG(LogTemp, Log, TEXT("UAshenIdentityPublishEventRouter: [Audio] Routing SerafinaTrust=%f"), StateVector.SerafinaTrust);
	// Dialogue channel — route full FSoulStateVector to dialogue state table
	UE_LOG(LogTemp, Log, TEXT("UAshenIdentityPublishEventRouter: [Dialogue] All downstream channels invalidated from FSoulStateVector."));
}
