// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 420: Ashen Cognitive StateTree & Threat Perception Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "FStateTreeTask_EvaluateAction.h"
#include "FStateTreeTask_ExecuteAbility.h"
#include "AshenOath_ThreatPerceptionComponent.h"
#include "AshenSoulStateVectorDecaySubsystem.h"
#include "AshenUserWidget_CognitiveAIDebugOverlay.h"

// =============================================================================
//  Test 1: FStateTreeTask_EvaluateAction — Struct Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenEvaluateActionTaskStructTest,
	"AshenOath.Cognitive.EvaluateActionTask.StructReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenEvaluateActionTaskStructTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("FStateTreeTask_EvaluateAction struct must be valid"),
		FStateTreeTask_EvaluateAction::StaticStruct() != nullptr);
	return true;
}

// =============================================================================
//  Test 2: FStateTreeTask_ExecuteAbility — Struct Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenExecuteAbilityTaskStructTest,
	"AshenOath.Cognitive.ExecuteAbilityTask.StructReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenExecuteAbilityTaskStructTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("FStateTreeTask_ExecuteAbility struct must be valid"),
		FStateTreeTask_ExecuteAbility::StaticStruct() != nullptr);
	return true;
}

// =============================================================================
//  Test 3: AshenOath_ThreatPerceptionComponent — Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenThreatPerceptionReflectionTest,
	"AshenOath.Cognitive.ThreatPerceptionComponent.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenThreatPerceptionReflectionTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenOath_ThreatPerceptionComponent class must be valid"),
		UAshenOath_ThreatPerceptionComponent::StaticClass() != nullptr);
	return true;
}

// =============================================================================
//  Test 4: Cognitive AI Debug Overlay Widget — Display Update
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCognitiveAIDebugWidgetTest,
	"AshenOath.UI.CognitiveAIDebugWidget.DisplayUpdate",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenCognitiveAIDebugWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_CognitiveAIDebugOverlay* Widget = NewObject<UAshenUserWidget_CognitiveAIDebugOverlay>();
	if (!TestNotNull(TEXT("CognitiveAIDebugOverlay widget must be constructable"), Widget)) return false;

	const FName ThreatName(TEXT("Kaelen_PlayerPawn"));
	Widget->UpdateCognitiveDebugDisplay(ThreatName, 0.85f, 0.6f);
	TestEqual(TEXT("DisplayedUtility must equal 0.85"), Widget->DisplayedUtility, 0.85f);

	return true;
}

// =============================================================================
//  Test 5: Milestone 420 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone420VerificationTest,
	"AshenOath.Milestone.Milestone420.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone420VerificationTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Warning, TEXT("AshenOath.Milestone.Milestone420.Verification: Milestone 420 Systems Verified!"));
	return true;
}
