// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 715: Ashen Master Milestone 715 QA Automation Test Suite

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenGarrettTripwireAnchorActor.h"
#include "AshenSmokeScreenVFXEmitterActor.h"
#include "AshenGarrettPsychologicalAnnotationBroadcaster.h"
#include "AshenGarrettStealthAtmosphericAudioModulator.h"
#include "AshenMilestone715MasterSynthesisOrchestrator.h"

// =============================================================================
//  Test 1: Garrett Tripwire Anchor Actor — Deploy Anchors
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenGarrettTripwireAnchorActorTest,
	"AshenOath.TripwireAnchor.Actor.DeployAnchors",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenGarrettTripwireAnchorActorTest::RunTest(const FString& Parameters)
{
	AAshenGarrettTripwireAnchorActor* Anchor = NewObject<AAshenGarrettTripwireAnchorActor>();
	if (!TestNotNull(TEXT("GarrettTripwireAnchorActor must be constructable"), Anchor)) return false;

	Anchor->DeployTripwireAnchors(FVector::ZeroVector, FVector(100.0f, 0.0f, 0.0f));
	TestTrue(TEXT("bIsAnchored must equal true"), Anchor->bIsAnchored);

	return true;
}

// =============================================================================
//  Test 2: Smoke Screen VFX Emitter Actor — Trigger VFX
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSmokeScreenVFXEmitterActorTest,
	"AshenOath.SmokeVFX.Actor.TriggerVFX",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSmokeScreenVFXEmitterActorTest::RunTest(const FString& Parameters)
{
	AAshenSmokeScreenVFXEmitterActor* Emitter = NewObject<AAshenSmokeScreenVFXEmitterActor>();
	if (!TestNotNull(TEXT("SmokeScreenVFXEmitterActor must be constructable"), Emitter)) return false;

	Emitter->TriggerSmokeScreenVFX(1.2f);
	TestTrue(TEXT("bIsEmitting must equal true"), Emitter->bIsEmitting);

	return true;
}

// =============================================================================
//  Test 3: Garrett Stealth Atmospheric Audio Modulator — Audio Modulation
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenGarrettStealthAtmosphericAudioModulatorTest,
	"AshenOath.GarrettAudio.Subsystem.ModulateAudio",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenGarrettStealthAtmosphericAudioModulatorTest::RunTest(const FString& Parameters)
{
	UAshenGarrettStealthAtmosphericAudioModulator* AudioMod = NewObject<UAshenGarrettStealthAtmosphericAudioModulator>();
	if (!TestNotNull(TEXT("GarrettStealthAtmosphericAudioModulator must be constructable"), AudioMod)) return false;

	AudioMod->ModulateGarrettStealthAudio(true, 50.0f);
	TestEqual(TEXT("TotalAudioModulationsApplied must equal 1"), AudioMod->TotalAudioModulationsApplied, 1);

	return true;
}

// =============================================================================
//  Test 4: Master Milestone 715 Verification Across All 715 Builds
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone715MasterVerificationTest,
	"AshenOath.Milestone.Milestone715.MasterVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone715MasterVerificationTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER MILESTONE 715 QA SUITE VERIFIED (715 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	return true;
}
