// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Soul/AshenInnerVoiceCompilerSubsystem.h"
#include "Soul/AshenCognitiveFirewallValidator.h"
#include "Soul/AshenDeterministicVoiceFallbackProvider.h"

UAshenInnerVoiceCompilerSubsystem::UAshenInnerVoiceCompilerSubsystem()
{
	bInFlight = false;
}

void UAshenInnerVoiceCompilerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	FirewallValidator = NewObject<UAshenCognitiveFirewallValidator>(this);
	FallbackProvider = NewObject<UAshenDeterministicVoiceFallbackProvider>(this);
}

void UAshenInnerVoiceCompilerSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

bool UAshenInnerVoiceCompilerSubsystem::RequestVoiceCompilation(
	ESalienceTriggerClass TriggerClass,
	const FCanonicalSoulStateVector& CurrentSoulState,
	const FGameplayTag& ActiveStanceTag,
	const FString& ActiveEchoId,
	const TArray<FString>& AuthorizedImprints)
{
	if (bInFlight)
	{
		return false;
	}

	bInFlight = true;
	CachedSoulState = CurrentSoulState;

	OnSalienceGateTriggered.Broadcast(TriggerClass, ActiveEchoId);

	// Generate ingest packet
	FAshenVoiceIngestPacket IngestPacket;
	IngestPacket.CompilationId = FGuid::NewGuid().ToString();
	IngestPacket.SalienceTrigger = TriggerClass;
	IngestPacket.SoulStateSnapshot = CurrentSoulState;
	IngestPacket.ActiveStanceTag = ActiveStanceTag;
	IngestPacket.ActiveMemoryEchoId = ActiveEchoId;
	IngestPacket.AuthorizedImprintIds = AuthorizedImprints;

	// In offline/deterministic mode, resolve via FallbackProvider
	FAshenInnerVoicePayload ResolvedPayload = FallbackProvider ? 
		FallbackProvider->GetFallbackPayload(CurrentSoulState.DominantLens, CurrentSoulState.IntegrationDebt, ActiveEchoId) :
		FAshenInnerVoicePayload();

	ResolvedPayload.CompilationId = IngestPacket.CompilationId;

	return ProcessCompilerOutput(ResolvedPayload, AuthorizedImprints);
}

bool UAshenInnerVoiceCompilerSubsystem::ProcessCompilerOutput(
	const FAshenInnerVoicePayload& RawPayload,
	const TArray<FString>& AuthorizedImprints)
{
	FAshenInnerVoicePayload SanitizedPayload = RawPayload;
	EFirewallValidationResult ValidationResult = EFirewallValidationResult::Success;

	if (FirewallValidator)
	{
		ValidationResult = FirewallValidator->ValidatePayload(RawPayload, AuthorizedImprints, SanitizedPayload);
	}

	if (ValidationResult != EFirewallValidationResult::Success && ValidationResult != EFirewallValidationResult::FailedNumericalBoundsClamped)
	{
		OnFirewallValidationFailed.Broadcast(RawPayload.CompilationId, ValidationResult);

		// Fallback to deterministic line
		if (FallbackProvider)
		{
			SanitizedPayload = FallbackProvider->GetFallbackPayload(
				CachedSoulState.DominantLens,
				CachedSoulState.IntegrationDebt,
				RawPayload.CitedMemoryId);
			SanitizedPayload.CompilationId = RawPayload.CompilationId;
			SanitizedPayload.ValidationResult = EFirewallValidationResult::Success;
		}
	}

	bInFlight = false;
	OnInnerVoiceCompilationCompleted.Broadcast(SanitizedPayload);
	OnMonologueAudioDispatched.Broadcast(SanitizedPayload.Channel, SanitizedPayload.AudioMotifTag);

	return true;
}
