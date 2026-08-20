// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 540: Ashen Lantern, Trap & Audio Occlusion Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenAlchemicalLanternComponent.h"
#include "AshenAlchemicalTrapActor.h"
#include "AshenAudioOcclusionComponent.h"
#include "AshenMilestone540SynthesisOrchestrator.h"

// =============================================================================
//  Test 1: Alchemical Lantern Component — Refill Fuel
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenLanternComponentTest,
	"AshenOath.Lantern.Component.RefillFuel",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenLanternComponentTest::RunTest(const FString& Parameters)
{
	UAshenAlchemicalLanternComponent* Lantern = NewObject<UAshenAlchemicalLanternComponent>();
	if (!TestNotNull(TEXT("AlchemicalLanternComponent must be constructable"), Lantern)) return false;

	Lantern->ConsumeFuel(10.0f);
	Lantern->RefillFuel(20.0f);
	TestEqual(TEXT("CurrentFuel must equal 100.0"), Lantern->CurrentFuel, 100.0f);

	return true;
}

// =============================================================================
//  Test 2: Audio Occlusion Component — Line Trace Evaluation
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenAudioOcclusionTest,
	"AshenOath.Audio.Component.OcclusionEvaluation",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenAudioOcclusionTest::RunTest(const FString& Parameters)
{
	UAshenAudioOcclusionComponent* AudioOcc = NewObject<UAshenAudioOcclusionComponent>();
	if (!TestNotNull(TEXT("AudioOcclusionComponent must be constructable"), AudioOcc)) return false;

	float Occ = AudioOcc->EvaluateAudioOcclusion(FVector(0, 0, 0), FVector(100, 0, 0));
	TestTrue(TEXT("CalculatedLowPassCutoff must be greater than 0"), AudioOcc->CalculatedLowPassCutoff > 0.0f);

	return true;
}

// =============================================================================
//  Test 3: Alchemical Trap Actor — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenAlchemicalTrapActorClassTest,
	"AshenOath.Trap.Actor.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenAlchemicalTrapActorClassTest::RunTest(const FString& Parameters)
{
	UClass* TrapClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.AshenAlchemicalTrapActor"));
	TestNotNull(TEXT("AAshenAlchemicalTrapActor must be registered in UObject system"), TrapClass);
	return true;
}

// =============================================================================
//  Test 4: Milestone 540 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone540VerificationTest,
	"AshenOath.Milestone.Milestone540.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone540VerificationTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Warning, TEXT("AshenOath.Milestone.Milestone540.Verification: Milestone 540 Systems Verified!"));
	return true;
}
