// Copyright Phoenix Protocol / Ashen Oath. All rights reserved.

#include "AshenPsychologicalRuntimeBroadcaster.h"

void UAshenPsychologicalRuntimeBroadcaster::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    UE_LOG(LogTemp, Log, TEXT("UAshenPsychologicalRuntimeBroadcaster initialized."));
}

void UAshenPsychologicalRuntimeBroadcaster::BroadcastPsychologicalRuntimeState(float IntegrationDebt, float Resolve, float NarrativeEntropy)
{
    TotalBroadcastsSent++;
    UE_LOG(LogTemp, Log, TEXT("Broadcasting psychological runtime state (Debt=%f, Resolve=%f, Entropy=%f)."), IntegrationDebt, Resolve, NarrativeEntropy);
    OnRuntimeBroadcasted.Broadcast(IntegrationDebt, Resolve, NarrativeEntropy);
}
