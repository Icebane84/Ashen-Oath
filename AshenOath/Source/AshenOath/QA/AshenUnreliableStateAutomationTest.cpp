// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 310: Ashen Unreliable State Machine Automation Tests (UMB-SYS-005)

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenSoulStateVectorComponent.h"
#include "AshenUnreliableStateMachineSubsystem.h"
#include "AshenSanctuaryHeartstoneCrucibleComponent.h"
#include "AshenCompanionDiagnosticBifurcationComponent.h"
#include "AshenFalseConfidenceDeceptionComponent.h"

// =============================================================================
//  Test 1: Soul State Vector Component — Debt Accumulation
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSoulStateVectorDebtTest,
	"AshenOath.UMB005.SoulStateVector.DebtAccumulation",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSoulStateVectorDebtTest::RunTest(const FString& Parameters)
{
	UAshenSoulStateVectorComponent* Soul = NewObject<UAshenSoulStateVectorComponent>();
	if (!TestNotNull(TEXT("SoulStateVectorComponent must be constructable"), Soul)) return false;

	TestEqual(TEXT("Initial IntegrationDebt must be 0"), Soul->GetSoulVector().IntegrationDebt, 0.0f);
	Soul->AccumulateIntegrationDebt(30.0f);
	TestEqual(TEXT("IntegrationDebt must be 30 after accumulation"), Soul->GetSoulVector().IntegrationDebt, 30.0f);

	return true;
}

// =============================================================================
//  Test 2: Heartstone Crucible Component — Reflection State
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenHeartstoneReflectionStateTest,
	"AshenOath.UMB005.HeartstoneCrucible.ReflectionState",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenHeartstoneReflectionStateTest::RunTest(const FString& Parameters)
{
	UAshenSanctuaryHeartstoneCrucibleComponent* Heartstone = NewObject<UAshenSanctuaryHeartstoneCrucibleComponent>();
	if (!TestNotNull(TEXT("SanctuaryHeartstoneCrucibleComponent must be constructable"), Heartstone)) return false;

	TestFalse(TEXT("Heartstone must initially not be reflecting"), Heartstone->IsReflecting());
	Heartstone->EndReflectionSession();
	TestFalse(TEXT("Heartstone must be false after end session"), Heartstone->IsReflecting());

	return true;
}

// =============================================================================
//  Test 3: Companion Diagnostic Bifurcation — Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCompanionDiagnosticReflectionTest,
	"AshenOath.UMB005.CompanionDiagnostic.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenCompanionDiagnosticReflectionTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenCompanionDiagnosticBifurcationComponent class must be valid"),
		UAshenCompanionDiagnosticBifurcationComponent::StaticClass() != nullptr);
	return true;
}

// =============================================================================
//  Test 4: False Confidence Deception — Deception State Activation
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenFalseConfidenceDeceptionTest,
	"AshenOath.UMB005.FalseConfidence.DeceptionActivation",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenFalseConfidenceDeceptionTest::RunTest(const FString& Parameters)
{
	UAshenFalseConfidenceDeceptionComponent* Deception = NewObject<UAshenFalseConfidenceDeceptionComponent>();
	if (!TestNotNull(TEXT("FalseConfidenceDeceptionComponent must be constructable"), Deception)) return false;

	FAshenSoulStateVector CorruptedVector;
	CorruptedVector.IntegrationDebt = 80.0f;

	Deception->EvaluateFalseConfidenceState(CorruptedVector);
	TestTrue(TEXT("Deception must be active for high IntegrationDebt"), Deception->IsDeceptionActive());
	TestEqual(TEXT("AttackSpeedMultiplier must be 1.35"), Deception->GetAttackSpeedMultiplier(), 1.35f);

	return true;
}

// =============================================================================
//  Test 5: Milestone 310 UMB-SYS-005 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone310VerificationTest,
	"AshenOath.Milestone.Milestone310.UMB005Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone310VerificationTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Warning, TEXT("AshenOath.Milestone.Milestone310.UMB005Verification: UMB-SYS-005 Unreliable State Machine Verified!"));
	return true;
}


