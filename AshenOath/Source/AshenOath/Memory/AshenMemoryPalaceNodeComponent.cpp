// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Memory/AshenMemoryPalaceNodeComponent.h"

UAshenMemoryPalaceNodeComponent::UAshenMemoryPalaceNodeComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	PsychicResonanceFrequency = 432.0f;
}
void UAshenMemoryPalaceNodeComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenMemoryPalaceNodeComponent::TriggerPsychicLink(AActor* InstigatingPlayer)
{
	if (!InstigatingPlayer) return false;
	NodeData.bIsUnsealed = true;
	UE_LOG(LogTemp, Warning, TEXT("UAshenMemoryPalaceNodeComponent: Psychic Link established for node '%s' at %.1f Hz!"),
		*NodeData.NodeID.ToString(), PsychicResonanceFrequency);
	return true;
}
