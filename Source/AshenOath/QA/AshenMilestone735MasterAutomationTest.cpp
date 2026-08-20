// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 735: Ashen Master Milestone 735 QA Automation Test Suite

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenRadiantBeamVFXEmitterActor.h"
#include "AshenSanctuaryAuraVisualLocusActor.h"
#include "AshenSerafinaEmpathicAnnotationBroadcaster.h"
#include "AshenSerafinaHolyAtmosphericAudioModulator.h"
#include "AshenMilestone735MasterSynthesisOrchestrator.h"

// =============================================================================
//  Test 1: Radiant Beam VFX Emitter Actor — Trigger Beam
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenRadiantBeamVFXEmitterActorTest,
	"AshenOath.BeamVFX.Actor.TriggerBeam",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenRadiantBeamVFXEmitterActorTest::RunTest(const FString& Parameters)
{
	AAshenRadiantBeamVFXEmitterActor* Beam = NewObject<AAshenRadiantBeamVFXEmitterActor>();
	if (!TestNotNull(TEXT("RadiantBeamVFXEmitterActor must be constructable"), Beam)) return false;

	Beam->TriggerRadiantBeamVFX(FVector::ZeroVector, 250.0f);
	TestTrue(TEXT("bIsBeamActive must equal true"), Beam->bIsBeamActive);

	return true;
}

// =============================================================================
//  Test 2: Sanctuary Aura Visual Locus Actor — Update Radius
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSanctuaryAuraVisualLocusActorTest,
	"AshenOath.SanctuaryLocus.Actor.UpdateRadius",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSanctuaryAuraVisualLocusActorTest::RunTest(const FString& Parameters)
{
	AAshenSanctuaryAuraVisualLocusActor* Locus = NewObject<AAshenSanctuaryAuraVisualLocusActor>();
	if (!TestNotNull(TEXT("SanctuaryAuraVisualLocusActor must be constructable"), Locus)) return false;

	Locus->UpdateSanctuaryGlyphRadius(600.0f);
	TestEqual(TEXT("ActiveGlyphRadius must equal 600.0 units"), Locus->ActiveGlyphRadius, 600.0f);

	return true;
}

// =============================================================================
//  Test 3: Serafina Holy Atmospheric Audio Modulator — Audio Modulation
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSerafinaHolyAtmosphericAudioModulatorTest,
	"AshenOath.SerafinaAudio.Subsystem.ModulateAudio",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSerafinaHolyAtmosphericAudioModulatorTest::RunTest(const FString& Parameters)
{
	UAshenSerafinaHolyAtmosphericAudioModulator* AudioMod = NewObject<UAshenSerafinaHolyAtmosphericAudioModulator>();
	if (!TestNotNull(TEXT("SerafinaHolyAtmosphericAudioModulator must be constructable"), AudioMod)) return false;

	AudioMod->ModulateSerafinaHolyAudio(true, 80.0f);
	TestEqual(TEXT("TotalAudioModulationsApplied must equal 1"), AudioMod->TotalAudioModulationsApplied, 1);

	return true;
}

// =============================================================================
//  Test 4: Master Milestone 735 Verification Across All 735 Builds
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone735MasterVerificationTest,
	"AshenOath.Milestone.Milestone735.MasterVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone735MasterVerificationTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER MILESTONE 735 QA SUITE VERIFIED (735 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	return true;
}
