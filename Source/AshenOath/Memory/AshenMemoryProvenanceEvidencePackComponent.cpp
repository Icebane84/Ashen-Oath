// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Memory/AshenMemoryProvenanceEvidencePackComponent.h"

UAshenMemoryProvenanceEvidencePackComponent::UAshenMemoryProvenanceEvidencePackComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenMemoryProvenanceEvidencePackComponent::BeginPlay()
{
	Super::BeginPlay();
}

FText UAshenMemoryProvenanceEvidencePackComponent::FormatMemoryProvenanceEvidencePack(FName MemoryImprintID)
{
	FString Provenance = FString::Printf(TEXT("Memory Imprint %s Provenance: Referenced in %d dialogue threads | Generated %d combat whispers."), *MemoryImprintID.ToString(), DialogueThreadReferences, CombatWhispersGenerated);
	UE_LOG(LogTemp, Log, TEXT("UAshenMemoryProvenanceEvidencePackComponent: Formatted provenance evidence pack for %s"), *MemoryImprintID.ToString());
	return FText::FromString(Provenance);
}
