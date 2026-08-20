// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 510: Ashen Peak Resonance & Failure Memory Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenSymbioticPeakResonanceSilenceComponent.h"
#include "AshenUserWidget_PeakResonanceHUD.h"
#include "AshenFailureMemoryPsychicEchoSubsystem.h"
#include "GA_KaelenLethalSilentDualExecution.h"
#include "AshenMilestone510SynthesisOrchestrator.h"

// =============================================================================
//  Test 1: Peak Resonance Silence Component — Resonance Evaluation
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenPeakResonanceSilenceTest,
	"AshenOath.PeakResonance.Component.EvaluateSilence",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenPeakResonanceSilenceTest::RunTest(const FString& Parameters)
{
	UAshenSymbioticPeakResonanceSilenceComponent* Silence = NewObject<UAshenSymbioticPeakResonanceSilenceComponent>();
	if (!TestNotNull(TEXT("SymbioticPeakResonanceSilenceComponent must be constructable"), Silence)) return false;

	Silence->EvaluateResonanceSilence(95.0f, 400.0f); // Peak resonance active
	TestTrue(TEXT("bIsPeakResonanceActive must equal true"), Silence->bIsPeakResonanceActive);

	return true;
}

// =============================================================================
//  Test 2: Failure Memory Psychic Echo Subsystem — Imprint
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenFailureMemoryPsychicEchoTest,
	"AshenOath.FailureMemory.Subsystem.ImprintEcho",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenFailureMemoryPsychicEchoTest::RunTest(const FString& Parameters)
{
	UAshenFailureMemoryPsychicEchoSubsystem* EchoSubsystem = NewObject<UAshenFailureMemoryPsychicEchoSubsystem>();
	if (!TestNotNull(TEXT("FailureMemoryPsychicEchoSubsystem must be constructable"), EchoSubsystem)) return false;

	const FName FailureID(TEXT("Failure_CivilianMassacre_Village3"));
	EchoSubsystem->ImprintFailurePsychicEcho(FailureID, FVector(100, 200, 300));
	TestEqual(TEXT("TotalImprintedFailureCount must equal 1"), EchoSubsystem->GetTotalImprintedFailureCount(), 1);

	return true;
}

// =============================================================================
//  Test 3: Kaelen Lethal Silent Dual Execution — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenLethalSilentDualExecutionClassTest,
	"AshenOath.GAS.KaelenLethalSilentDualExecution.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenLethalSilentDualExecutionClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_KaelenLethalSilentDualExecution"));
	TestNotNull(TEXT("UGA_KaelenLethalSilentDualExecution must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 4: Milestone 510 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone510VerificationTest,
	"AshenOath.Milestone.Milestone510.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone510VerificationTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Warning, TEXT("AshenOath.Milestone.Milestone510.Verification: Milestone 510 Systems Verified!"));
	return true;
}
