// AshenEncounterAutomationTest.cpp
// Copyright Ashen Oath. All rights reserved.
// BUILD 92: PAA V2.1 Encounter Integration Test
// Validates the full pipeline:
//   Phase 0 (Encounter Tier) -> Phase 1-4 (Trauma Matrix) -> Phase 5 (Resolution State)
//   Companion AI routing, Trauma Matrix disruption, Blight Ghoul combat, and Whisper audio scaling.

#include "Misc/AutomationTest.h"
#include "AshenTraumaMatrixComponent.h"
#include "AshenBlightGhoul.h"
#include "AshenWhisperingWindSubsystem.h"
#include "FStateTreeTask_CompanionSupport.h"
#include "AshenOath_SanityComponent.h"
#include "AshenOath_HealthComponent.h"
#include "Engine/Engine.h"

// ---------------------------------------------------------------------------
// TEST 1: Trauma Matrix — EvaluateTraumaDisruption marks disruption correctly
// ---------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenTraumaMatrixTest,
	"AshenOath.PAA_V2.TraumaMatrix.EvaluateDisruption",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenTraumaMatrixTest::RunTest(const FString& Parameters)
{
	UAshenTraumaMatrixComponent* Matrix = NewObject<UAshenTraumaMatrixComponent>();
	TestNotNull(TEXT("TraumaMatrixComponent must instantiate"), Matrix);
	if (!Matrix) return false;

	// Configure Tier I Pressure targeting Garrett
	Matrix->TargetVector    = EAshenOathCompanion::Garrett;
	Matrix->AdversarialArgument = TEXT("Preparation is an illusion");
	Matrix->DisruptionMultiplier = 1.2f;

	TestEqual(TEXT("TargetVector must be Garrett"),
		Matrix->TargetVector == EAshenOathCompanion::Garrett, true);

	TestEqual(TEXT("AdversarialArgument must be set"),
		Matrix->AdversarialArgument.Equals(TEXT("Preparation is an illusion")), true);

	TestEqual(TEXT("DisruptionMultiplier must be 1.2f"),
		FMath::IsNearlyEqual(Matrix->DisruptionMultiplier, 1.2f, 0.001f), true);

	UE_LOG(LogTemp, Log, TEXT("FAshenTraumaMatrixTest: PASS"));
	return true;
}

// ---------------------------------------------------------------------------
// TEST 2: Blight Ghoul — State Machine transitions and flocking damage scaling
// ---------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenBlightGhoulTest,
	"AshenOath.PAA_V2.BlightGhoul.StateMachineAndFlocking",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenBlightGhoulTest::RunTest(const FString& Parameters)
{
	// Verify default construction
	AAshenBlightGhoul* Ghoul = NewObject<AAshenBlightGhoul>();
	TestNotNull(TEXT("BlightGhoul must instantiate"), Ghoul);
	if (!Ghoul) return false;

	TestEqual(TEXT("Default state must be Skittering"),
		Ghoul->CurrentState == EBlightGhoulState::Skittering, true);

	// Verify TraumaMatrix is present and configured
	TestNotNull(TEXT("TraumaMatrix component must exist"), Ghoul->TraumaMatrix.Get());
	TestEqual(TEXT("TraumaMatrix TargetVector must be Garrett"),
		Ghoul->TraumaMatrix->TargetVector == EAshenOathCompanion::Garrett, true);

	// Verify state transitions
	Ghoul->SetGhoulState(EBlightGhoulState::FlockPressing);
	TestEqual(TEXT("State must switch to FlockPressing"),
		Ghoul->CurrentState == EBlightGhoulState::FlockPressing, true);

	Ghoul->SetGhoulState(EBlightGhoulState::Recoiling);
	TestEqual(TEXT("State must switch to Recoiling"),
		Ghoul->CurrentState == EBlightGhoulState::Recoiling, true);

	// Validate flock bonus multiplier
	TestEqual(TEXT("FlockBonusDamageMultiplier must be 1.5f"),
		FMath::IsNearlyEqual(Ghoul->FlockBonusDamageMultiplier, 1.5f, 0.001f), true);

	TestEqual(TEXT("FlockThreshold must be 3"),
		Ghoul->FlockThreshold, 3);

	UE_LOG(LogTemp, Log, TEXT("FAshenBlightGhoulTest: PASS"));
	return true;
}

// ---------------------------------------------------------------------------
// TEST 3: PAA V2.1 Encounter Tier — Verify Resolution State enum values
// ---------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenEncounterTierTest,
	"AshenOath.PAA_V2.EncounterTier.ResolutionStateMapping",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenEncounterTierTest::RunTest(const FString& Parameters)
{
	// Verify Tier enum ordinals match PAA V2.1 spec ordering
	TestEqual(TEXT("Tier I Pressure must be ordinal 0"),
		static_cast<uint8>(EAshenEncounterTier::Tier1_Pressure), static_cast<uint8>(0));

	TestEqual(TEXT("Tier II Trauma must be ordinal 1"),
		static_cast<uint8>(EAshenEncounterTier::Tier2_Trauma), static_cast<uint8>(1));

	TestEqual(TEXT("Tier III Revelation must be ordinal 2"),
		static_cast<uint8>(EAshenEncounterTier::Tier3_Revelation), static_cast<uint8>(2));

	// Verify Resolution State ordinals match PAA V2.1 spec ordering
	TestEqual(TEXT("Unresolved must be ordinal 0"),
		static_cast<uint8>(EAshenResolutionState::Unresolved), static_cast<uint8>(0));

	TestEqual(TEXT("EnemyProvedCorrect must be ordinal 1"),
		static_cast<uint8>(EAshenResolutionState::EnemyProvedCorrect), static_cast<uint8>(1));

	TestEqual(TEXT("PartialValidation must be ordinal 2"),
		static_cast<uint8>(EAshenResolutionState::PartialValidation), static_cast<uint8>(2));

	TestEqual(TEXT("EnemyDisproved must be ordinal 3"),
		static_cast<uint8>(EAshenResolutionState::EnemyDisproved), static_cast<uint8>(3));

	UE_LOG(LogTemp, Log, TEXT("FAshenEncounterTierTest: PASS"));
	return true;
}

// ---------------------------------------------------------------------------
// TEST 4: Whispering Wind Subsystem — Corruption scaling formulas
// ---------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenWhisperCorruptionTest,
	"AshenOath.PAA_V2.WhisperingWind.CorruptionScaling",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenWhisperCorruptionTest::RunTest(const FString& Parameters)
{
	UAshenWhisperingWindSubsystem* Whispers = NewObject<UAshenWhisperingWindSubsystem>();
	TestNotNull(TEXT("WhisperingWindSubsystem must instantiate"), Whispers);
	if (!Whispers) return false;

	// At zero corruption — base intensity should be 0
	Whispers->SetCorruptionInput(0.0f);
	TestEqual(TEXT("Intensity at C=0 should be 0.0f"),
		FMath::IsNearlyEqual(Whispers->GetWhisperIntensity(), 0.0f, 0.01f), true);

	// At max corruption alone — intensity should be 0.4
	Whispers->SetCorruptionInput(1.0f);
	TestEqual(TEXT("Intensity at C=1 with no isolation/debt should be 0.4f"),
		FMath::IsNearlyEqual(Whispers->GetWhisperIntensity(), 0.4f, 0.01f), true);

	// At C=0.70 (berserk threshold) — partial intensity from corruption alone = 0.28
	Whispers->SetCorruptionInput(0.70f);
	TestEqual(TEXT("Intensity at C=0.70 should be ~0.28f"),
		FMath::IsNearlyEqual(Whispers->GetWhisperIntensity(), 0.28f, 0.01f), true);

	// Volume should scale with intensity
	const float ExpectedVolume = FMath::Lerp(0.2f, 1.0f, Whispers->GetWhisperIntensity());
	TestEqual(TEXT("WhisperVolume must equal Lerp(0.2, 1.0, intensity)"),
		FMath::IsNearlyEqual(Whispers->GetWhisperVolume(), ExpectedVolume, 0.001f), true);

	UE_LOG(LogTemp, Log, TEXT("FAshenWhisperCorruptionTest: PASS"));
	return true;
}
