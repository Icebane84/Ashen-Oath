// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Memory/AshenCausalImprintMetadataComponent.h"

UAshenCausalImprintMetadataComponent::UAshenCausalImprintMetadataComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FPsychologicalImprint UAshenCausalImprintMetadataComponent::EnrichImprintWithCausality(const FPsychologicalImprint& BaseImprint, FName EntityInvolved, const FString& LocationTag)
{
	FPsychologicalImprint Enriched = BaseImprint;
	UE_LOG(LogTemp, Log, TEXT("UAshenCausalImprintMetadataComponent: Enriched imprint (Type: %d, Entity: %s, Location: %s)"),
		(int32)BaseImprint.Type, *EntityInvolved.ToString(), *LocationTag);
	return Enriched;
}
