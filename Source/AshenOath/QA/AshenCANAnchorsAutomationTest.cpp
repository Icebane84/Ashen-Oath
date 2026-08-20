// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 645: Ashen CAN Anchors Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenCANFaithVsDoubtEvaluatorComponent.h"
#include "AshenCANTriageBurdenEvaluatorComponent.h"
#include "AshenCANGlassShieldProtocolComponent.h"

// =============================================================================
//  Test 1: CAN Faith Vs Doubt Evaluator Component — Evaluation
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCANFaithVsDoubtEvaluatorComponentTest,
	"AshenOath.CANAnchors.FaithVsDoubt.Evaluate",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenCANFaithVsDoubtEvaluatorComponentTest::RunTest(const FString& Parameters)
{
	UAshenCANFaithVsDoubtEvaluatorComponent* FaithComp = NewObject<UAshenCANFaithVsDoubtEvaluatorComponent>();
	if (!TestNotNull(TEXT("CANFaithVsDoubtEvaluatorComponent must be constructable"), FaithComp)) return false;

	FaithComp->EvaluateFaithVsDoubt(0.2f, 0.1f);
	TestEqual(TEXT("ActiveFaithLevel must equal 0.7"), FaithComp->ActiveFaithLevel, 0.7f);

	return true;
}

// =============================================================================
//  Test 2: CAN Triage Burden Evaluator Component — Burden
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCANTriageBurdenEvaluatorComponentTest,
	"AshenOath.CANAnchors.TriageBurden.Evaluate",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenCANTriageBurdenEvaluatorComponentTest::RunTest(const FString& Parameters)
{
	UAshenCANTriageBurdenEvaluatorComponent* TriageComp = NewObject<UAshenCANTriageBurdenEvaluatorComponent>();
	if (!TestNotNull(TEXT("CANTriageBurdenEvaluatorComponent must be constructable"), TriageComp)) return false;

	TriageComp->EvaluateTriageBurden(40.0f);
	TestEqual(TEXT("ActiveTriageWeight must equal 40.0"), TriageComp->ActiveTriageWeight, 40.0f);

	return true;
}

// =============================================================================
//  Test 3: CAN Glass Shield Protocol Component — Deploy
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCANGlassShieldProtocolComponentTest,
	"AshenOath.CANAnchors.GlassShieldProtocol.Deploy",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenCANGlassShieldProtocolComponentTest::RunTest(const FString& Parameters)
{
	UAshenCANGlassShieldProtocolComponent* ShieldComp = NewObject<UAshenCANGlassShieldProtocolComponent>();
	if (!TestNotNull(TEXT("CANGlassShieldProtocolComponent must be constructable"), ShieldComp)) return false;

	ShieldComp->DeployGlassShield(300.0f);
	TestEqual(TEXT("ActiveGlassShieldHealth must equal 300.0"), ShieldComp->ActiveGlassShieldHealth, 300.0f);

	return true;
}
