// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Soul/AshenIdentityPublishEventRouter.h"
#include "Soul/AshenSoulPublisher.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

UAshenIdentityPublishEventRouter::UAshenIdentityPublishEventRouter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenIdentityPublishEventRouter::BeginPlay()
{
	Super::BeginPlay();

	if (const UWorld* World = GetWorld())
	{
		if (const UGameInstance* GI = World->GetGameInstance())
		{
			if (UAshenSoulPublisher* Publisher = GI->GetSubsystem<UAshenSoulPublisher>())
			{
				Publisher->OnSoulStateCommitted.AddDynamic(this, &UAshenIdentityPublishEventRouter::HandleSoulStateCommitted);
				// Route initial state immediately
				RouteStateVectorToDownstreamChannels(Publisher->GetSoulState(), Publisher->GetCurrentSomaticState());
			}
		}
	}
}

void UAshenIdentityPublishEventRouter::HandleSoulStateCommitted(const FSoulStateVector& NewState, const FSomaticState& SomaticState)
{
	RouteStateVectorToDownstreamChannels(NewState, SomaticState);
}

void UAshenIdentityPublishEventRouter::RouteStateVectorToDownstreamChannels(const FSoulStateVector& StateVector, const FSomaticState& SomaticState)
{
	// 1. AnimBP channel — route stance profile
	OnAnimBPStanceRouted.Broadcast(StateVector.Resolve);
	UE_LOG(LogTemp, Verbose, TEXT("UAshenIdentityPublishEventRouter: [AnimBP] Routed Resolve=%f"), StateVector.Resolve);

	// 2. MPC channel — route corruption amount and debt stage to Material Parameter Collection
	OnMPCCorruptionRouted.Broadcast(StateVector.Corruption, StateVector.IntegrationDebt);
	UE_LOG(LogTemp, Verbose, TEXT("UAshenIdentityPublishEventRouter: [MPC] Routed Corruption=%f Debt=%f"), StateVector.Corruption, StateVector.IntegrationDebt);

	// 3. AI Blackboard channel — route companion trust
	OnAITacticalTrustRouted.Broadcast(StateVector.GarrettTrust, StateVector.SerafinaTrust);
	UE_LOG(LogTemp, Verbose, TEXT("UAshenIdentityPublishEventRouter: [AI] Routed GarrettTrust=%f SerafinaTrust=%f"), StateVector.GarrettTrust, StateVector.SerafinaTrust);

	// 4. MetaSounds channel — route parasite pressure
	OnAudioMetaSoundsRouted.Broadcast(SomaticState.ParasitePressure);
	UE_LOG(LogTemp, Verbose, TEXT("UAshenIdentityPublishEventRouter: [Audio] Routed ParasitePressure=%f"), SomaticState.ParasitePressure);
}
