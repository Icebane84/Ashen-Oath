// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Soul/AshenInnerVoiceCompilerTypes.h"
#include "Soul/AshenInnerVoiceCompilerSubsystem.h"
#include "Soul/AshenCognitiveFirewallValidator.h"
#include "Soul/AshenDeterministicVoiceFallbackProvider.h"
#include "Soul/AshenSalienceGateTriggerEvaluatorComponent.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch113AutomationTest,
	"AshenOath.Soul.MasterBatch113_InnerVoiceCompiler",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch113AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST 4-STAGE FIREWALL VALIDATION (VALID PAYLOAD)
	// -----------------------------------------------------------------------------------
	{
		UAshenCognitiveFirewallValidator* Validator = NewObject<UAshenCognitiveFirewallValidator>();

		TArray<FString> AuthorizedImprints;
		AuthorizedImprints.Add(TEXT("mem_oakhaven_001"));
		AuthorizedImprints.Add(TEXT("mem_silent_spire_002"));

		FAshenInnerVoicePayload ValidPayload;
		ValidPayload.CompilationId = TEXT("comp_001");
		ValidPayload.CitedMemoryId = TEXT("mem_oakhaven_001");
		ValidPayload.MonologueText = TEXT("The ash still smells of their sacrifice.");
		ValidPayload.DistortionIntensity = 0.50f;

		FAshenInnerVoicePayload SanitizedPayload;
		const EFirewallValidationResult Result = Validator->ValidatePayload(ValidPayload, AuthorizedImprints, SanitizedPayload);

		TestEqual(TEXT("Valid payload passes all 4 firewall stages"), Result, EFirewallValidationResult::Success);
		TestNearlyEqual(TEXT("Distortion intensity is untouched"), SanitizedPayload.DistortionIntensity, 0.50f, 0.001f);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST PROVENANCE AUDIT REJECTION (UNAUTHORIZED MEMORY CITATION)
	// -----------------------------------------------------------------------------------
	{
		UAshenCognitiveFirewallValidator* Validator = NewObject<UAshenCognitiveFirewallValidator>();

		TArray<FString> AuthorizedImprints;
		AuthorizedImprints.Add(TEXT("mem_valid_001"));

		FAshenInnerVoicePayload HallucinatedPayload;
		HallucinatedPayload.CompilationId = TEXT("comp_002");
		HallucinatedPayload.CitedMemoryId = TEXT("mem_hallucinated_unvisited_zone_999");
		HallucinatedPayload.MonologueText = TEXT("I remember the fire in that kingdom.");
		HallucinatedPayload.DistortionIntensity = 0.30f;

		FAshenInnerVoicePayload SanitizedPayload;
		const EFirewallValidationResult Result = Validator->ValidatePayload(HallucinatedPayload, AuthorizedImprints, SanitizedPayload);

		TestEqual(TEXT("Unauthorized memory citation is rejected by Provenance Audit"), Result, EFirewallValidationResult::FailedProvenanceAudit);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST NUMERICAL CLAMPING
	// -----------------------------------------------------------------------------------
	{
		UAshenCognitiveFirewallValidator* Validator = NewObject<UAshenCognitiveFirewallValidator>();

		TArray<FString> AuthorizedImprints;

		FAshenInnerVoicePayload OutOfBoundsPayload;
		OutOfBoundsPayload.CompilationId = TEXT("comp_003");
		OutOfBoundsPayload.MonologueText = TEXT("The screams are deafening.");
		OutOfBoundsPayload.DistortionIntensity = 1.85f; // Greater than 1.0

		FAshenInnerVoicePayload SanitizedPayload;
		const EFirewallValidationResult Result = Validator->ValidatePayload(OutOfBoundsPayload, AuthorizedImprints, SanitizedPayload);

		TestEqual(TEXT("Out of bounds float triggers clamp flag"), Result, EFirewallValidationResult::FailedNumericalBoundsClamped);
		TestNearlyEqual(TEXT("Distortion intensity clamped to 1.0"), SanitizedPayload.DistortionIntensity, 1.0f, 0.001f);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST DETERMINISTIC FALLBACK PROVIDER
	// -----------------------------------------------------------------------------------
	{
		UAshenDeterministicVoiceFallbackProvider* FallbackProvider = NewObject<UAshenDeterministicVoiceFallbackProvider>();

		// Defiance Fallback -> Channel KaelenReflex
		const FAshenInnerVoicePayload DefiancePayload = FallbackProvider->GetFallbackPayload(EOntologicalLens::Defiance, 0.60f, TEXT(""));
		TestEqual(TEXT("Defiance fallback maps to KaelenReflex channel"), DefiancePayload.Channel, EVoiceChannel::KaelenReflex);

		// Grace Fallback -> Channel Eldrin
		const FAshenInnerVoicePayload GracePayload = FallbackProvider->GetFallbackPayload(EOntologicalLens::Grace, 0.20f, TEXT(""));
		TestEqual(TEXT("Grace fallback maps to Eldrin channel"), GracePayload.Channel, EVoiceChannel::Eldrin);

		// Wrath Fallback -> Channel ShadowSelf
		const FAshenInnerVoicePayload WrathPayload = FallbackProvider->GetFallbackPayload(EOntologicalLens::Wrath, 0.90f, TEXT(""));
		TestEqual(TEXT("Wrath fallback maps to ShadowSelf channel"), WrathPayload.Channel, EVoiceChannel::ShadowSelf);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST SALIENCE GATE EVALUATOR
	// -----------------------------------------------------------------------------------
	{
		UAshenSalienceGateTriggerEvaluatorComponent* SalienceComp = NewObject<UAshenSalienceGateTriggerEvaluatorComponent>();

		FCanonicalSoulStateVector OldState;
		OldState.IntegrationDebt = 0.40f;
		OldState.DominantLens = EOntologicalLens::Defiance;

		FCanonicalSoulStateVector NewState = OldState;
		NewState.IntegrationDebt = 0.55f; // Crossed 0.50 threshold

		ESalienceTriggerClass TriggerClass;
		const bool bTriggered = SalienceComp->EvaluateSalienceTrigger(OldState, NewState, TriggerClass);

		TestTrue(TEXT("Debt crossing 0.50 triggers Salience Gate"), bTriggered);
		TestEqual(TEXT("Trigger class is DebtStageEscalation"), TriggerClass, ESalienceTriggerClass::DebtStageEscalation);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
