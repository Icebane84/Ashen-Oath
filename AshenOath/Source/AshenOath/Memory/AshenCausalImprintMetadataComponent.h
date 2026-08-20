// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenOath_ImprintBufferComponent.h"
#include "AshenCausalImprintMetadataComponent.generated.h"

/**
 * UAshenCausalImprintMetadataComponent
 *
 * Enriches FPsychologicalImprint records with causality metadata.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCausalImprintMetadataComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCausalImprintMetadataComponent();

	/** Enriches an imprint with causal location and involved entity names */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Memory")
	FPsychologicalImprint EnrichImprintWithCausality(const FPsychologicalImprint& BaseImprint, FName EntityInvolved, const FString& LocationTag);
};
