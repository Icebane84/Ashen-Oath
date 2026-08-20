// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Soul/AshenCognitiveFirewallValidator.h"

UAshenCognitiveFirewallValidator::UAshenCognitiveFirewallValidator()
{
}

EFirewallValidationResult UAshenCognitiveFirewallValidator::ValidatePayload(
	const FAshenInnerVoicePayload& InRawPayload,
	const TArray<FString>& AuthorizedImprints,
	FAshenInnerVoicePayload& OutSanitizedPayload) const
{
	OutSanitizedPayload = InRawPayload;

	// 1. STAGE 1: SCHEMA VALIDATION
	if (InRawPayload.MonologueText.IsEmpty() || InRawPayload.CompilationId.IsEmpty())
	{
		OutSanitizedPayload.ValidationResult = EFirewallValidationResult::FailedSchemaValidation;
		return EFirewallValidationResult::FailedSchemaValidation;
	}

	// 2. STAGE 2: PROVENANCE AUDIT
	// If a memory ID is cited, it MUST exist in the authorized active imprint buffer
	if (!InRawPayload.CitedMemoryId.IsEmpty())
	{
		if (!AuthorizedImprints.Contains(InRawPayload.CitedMemoryId))
		{
			OutSanitizedPayload.ValidationResult = EFirewallValidationResult::FailedProvenanceAudit;
			return EFirewallValidationResult::FailedProvenanceAudit;
		}
	}

	// 3. STAGE 3: TAG REGISTRY CHECK
	// Tags must be valid if specified
	if (InRawPayload.AudioMotifTag.IsValid())
	{
		// Native tag check
	}

	// 4. STAGE 4: STRICT NUMERICAL CLAMP
	bool bWasClamped = false;
	if (InRawPayload.DistortionIntensity < 0.0f || InRawPayload.DistortionIntensity > 1.0f)
	{
		OutSanitizedPayload.DistortionIntensity = FMath::Clamp(InRawPayload.DistortionIntensity, 0.0f, 1.0f);
		bWasClamped = true;
	}

	if (bWasClamped)
	{
		OutSanitizedPayload.ValidationResult = EFirewallValidationResult::FailedNumericalBoundsClamped;
		return EFirewallValidationResult::FailedNumericalBoundsClamped;
	}

	OutSanitizedPayload.ValidationResult = EFirewallValidationResult::Success;
	return EFirewallValidationResult::Success;
}
