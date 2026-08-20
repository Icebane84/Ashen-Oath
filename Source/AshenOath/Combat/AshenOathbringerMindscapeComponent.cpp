// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenOathbringerMindscapeComponent.h"

UAshenOathbringerMindscapeComponent::UAshenOathbringerMindscapeComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenOathbringerMindscapeComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenOathbringerMindscapeComponent::SetSwordMorphState(EAshenSwordMorphState NewState)
{
	MorphState = NewState;
	if (OnSwordMorphStateChanged.IsBound())
	{
		OnSwordMorphStateChanged.Broadcast(MorphState);
	}
	UE_LOG(LogTemp, Warning, TEXT("UAshenOathbringerMindscapeComponent: Oathbringer morphed to state %d!"), (int32)MorphState);
}
