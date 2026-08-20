// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Soul/AshenInnerVoiceCompilerTypes.h"
#include "AshenCognitiveFirewallValidator.generated.h"

/**
 * UAshenCognitiveFirewallValidator
 * 
 * Implements the 4-Stage Zero-Entropy C++ Firewall Protocol:
 * 1. Schema Validation (monologue_text not empty, compilation_id valid)
 * 2. Provenance Audit (cited_memory_id is present in authorized imprints)
 * 3. Tag Registry Check (AudioMotifTag & UIDistortionTag valid)
 * 4. Float Clamp (DistortionIntensity clamped strictly to [0.0, 1.0])
 */
UCLASS()
class ASHENOATH_API UAshenCognitiveFirewallValidator : public UObject
{
	GENERATED_BODY()

public:
	UAshenCognitiveFirewallValidator();

	/** Validates raw payload against the 4 firewall stages */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Soul|Firewall")
	EFirewallValidationResult ValidatePayload(
		const FAshenInnerVoicePayload& InRawPayload,
		const TArray<FString>& AuthorizedImprints,
		FAshenInnerVoicePayload& OutSanitizedPayload) const;
};
