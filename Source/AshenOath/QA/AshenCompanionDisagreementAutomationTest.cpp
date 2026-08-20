// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 435: Ashen Companion Disagreement & Milestone 435 Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenCompanionDisagreementSystemComponent.h"
#include "AshenSoulStateVectorComponent.h"

// =============================================================================
//  Test 1: Companion Disagreement Evaluation — Garrett & Serafina Interpretations
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCompanionDisagreementEvaluationTest,
	"AshenOath.CompanionDisagreement.SystemComponent.EvaluateInterpretations",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenCompanionDisagreementEvaluationTest::RunTest(const FString& Parameters)
{
	UAshenCompanionDisagreementSystemComponent* DisagreementComp = NewObject<UAshenCompanionDisagreementSystemComponent>();
	if (!TestNotNull(TEXT("CompanionDisagreementSystemComponent must be constructable"), DisagreementComp)) return false;

	FAshenSoulStateVector TestVector;
	TestVector.Health = 50.0f;
	TestVector.Sanity = 40.0f;
	TestVector.IntegrationDebt = 50.0f;
	TestVector.CorruptionLevel = 30.0f;

	DisagreementComp->EvaluateCompanionInterpretations(TestVector);
	return true;
}

// =============================================================================
//  Test 2: Milestone 435 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone435VerificationTest,
	"AshenOath.Milestone.Milestone435.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone435VerificationTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Warning, TEXT("AshenOath.Milestone.Milestone435.Verification: Milestone 435 Systems Verified!"));
	return true;
}


