// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenInnerVoiceCompilerTypes.generated.h"

// -----------------------------------------------------------------------------------
// INNER VOICE COMPILER ENUMERATIONS (VOICE-SPEC-054 / IVC-001)
// -----------------------------------------------------------------------------------

UENUM(BlueprintType)
enum class EVoiceChannel : uint8
{
	ShadowSelf   UMETA(DisplayName = "The Shadow Self (Parasite whispers / controller speaker)"),
	Eldrin       UMETA(DisplayName = "Eldrin (Sealed scholar / sorrowful echo)"),
	KaelenReflex UMETA(DisplayName = "Kaelen Reflex (Subconscious survival instinct)"),
	WhiteFlame   UMETA(DisplayName = "The White Flame (Ancestral clarity / light resonance)")
};

UENUM(BlueprintType)
enum class EFirewallValidationResult : uint8
{
	Success                     UMETA(DisplayName = "Passed all 4 firewall audit stages"),
	FailedSchemaValidation      UMETA(DisplayName = "Malformed JSON or missing required fields"),
	FailedProvenanceAudit       UMETA(DisplayName = "Cited memory ID not found in active ImprintBuffer"),
	FailedTagRegistryCheck      UMETA(DisplayName = "GameplayTag not found in native dictionary"),
	FailedNumericalBoundsClamped UMETA(DisplayName = "Float bounds clamped to [0.0, 1.0]")
};

UENUM(BlueprintType)
enum class ESalienceTriggerClass : uint8
{
	DebtStageEscalation  UMETA(DisplayName = "Debt threshold crossed (0.50, 0.75, 1.0)"),
	RelationalRupture    UMETA(DisplayName = "Companion trust delta >= 0.15"),
	CampfireReflection   UMETA(DisplayName = "Heartstone sanctuary communion"),
	LensTransmutation    UMETA(DisplayName = "Primary lens shift (Defiance / Grace / Wrath)")
};

// -----------------------------------------------------------------------------------
// INNER VOICE COMPILER STRUCTS
// -----------------------------------------------------------------------------------

/**
 * Ingest Packet Payload (Engine to Compiler)
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FAshenVoiceIngestPacket
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Voice")
	FString CompilationId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Voice")
	ESalienceTriggerClass SalienceTrigger = ESalienceTriggerClass::DebtStageEscalation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Voice")
	FCanonicalSoulStateVector SoulStateSnapshot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Voice")
	FGameplayTag ActiveStanceTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Voice")
	FString ActiveMemoryEchoId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Voice")
	TArray<FString> AuthorizedImprintIds;
};

/**
 * Compiler Output Payload (Validated and Sanitized)
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FAshenInnerVoicePayload
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Voice")
	FString CompilationId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Voice")
	FString CitedMemoryId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Voice")
	float ConfidenceScore = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Voice")
	EVoiceChannel Channel = EVoiceChannel::ShadowSelf;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Voice")
	FString MonologueText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Voice")
	FGameplayTag AudioMotifTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Voice")
	FGameplayTag UIDistortionTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Voice")
	float DistortionIntensity = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Voice")
	FGameplayTag JournalToneTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Voice")
	EFirewallValidationResult ValidationResult = EFirewallValidationResult::Success;
};

/**
 * Companion Marginalia Annotation Payload
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FAshenCompanionMarginaliaPayload
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Voice")
	FGameplayTag GarrettAnnotationTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Voice")
	FGameplayTag SerafinaAnnotationTag;
};

// -----------------------------------------------------------------------------------
// MASTER INNER VOICE MULTICAST DELEGATES
// -----------------------------------------------------------------------------------

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInnerVoiceCompilationCompleted, const FAshenInnerVoicePayload&, ValidatedPayload);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFirewallValidationFailed, const FString&, CompilationId, EFirewallValidationResult, ErrorReason);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSalienceGateTriggered, ESalienceTriggerClass, TriggerClass, const FString&, ContextEchoId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMonologueAudioDispatched, EVoiceChannel, Channel, const FGameplayTag&, AudioMotifTag);
