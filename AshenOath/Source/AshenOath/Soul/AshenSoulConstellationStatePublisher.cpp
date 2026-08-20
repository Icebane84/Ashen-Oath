// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Soul/AshenSoulConstellationStatePublisher.h"

void UAshenSoulConstellationStatePublisher::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenSoulConstellationStatePublisher: State Publisher Initialized cleanly."));
}

void UAshenSoulConstellationStatePublisher::PublishStateVector(const FSoulStateVector& NewState)
{
	PublishedState = NewState;
	UE_LOG(LogTemp, Log, TEXT("UAshenSoulConstellationStatePublisher: Publishing state vector invalidation pulse. Resolve: %.2f | Corruption: %.2f | Isolation: %.2f"),
		NewState.Resolve, NewState.Corruption, NewState.Isolation);

	OnStateVectorInvalidated.Broadcast(PublishedState);
}
