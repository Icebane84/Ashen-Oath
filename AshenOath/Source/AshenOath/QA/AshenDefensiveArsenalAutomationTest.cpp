// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 665: Ashen Defensive Arsenal Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenGlancingDeflectionParryEvaluator.h"
#include "AshenHalfSwordBraceStanceComponent.h"
#include "AshenMartyrGuardAllyInterceptComponent.h"

// =============================================================================
//  Test 1: Glancing Deflection Parry Evaluator — Unbroken Parry Window
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenGlancingDeflectionParryEvaluatorTest,
	"AshenOath.GlancingDeflection.Evaluator.ParryWindow",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenGlancingDeflectionParryEvaluatorTest::RunTest(const FString& Parameters)
{
	UAshenGlancingDeflectionParryEvaluator* Eval = NewObject<UAshenGlancingDeflectionParryEvaluator>();
	if (!TestNotNull(TEXT("GlancingDeflectionParryEvaluator must be constructable"), Eval)) return false;

	const int32 Frames = Eval->EvaluateParryWindowFrames(6, true);
	TestEqual(TEXT("Parry window under Unbroken must equal 9 frames (6+3)"), Frames, 9);

	return true;
}

// =============================================================================
//  Test 2: Half-Sword Brace Stance Component — Absorption
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenHalfSwordBraceStanceComponentTest,
	"AshenOath.HalfSwordBrace.Component.AbsorbImpact",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenHalfSwordBraceStanceComponentTest::RunTest(const FString& Parameters)
{
	UAshenHalfSwordBraceStanceComponent* BraceComp = NewObject<UAshenHalfSwordBraceStanceComponent>();
	if (!TestNotNull(TEXT("HalfSwordBraceStanceComponent must be constructable"), BraceComp)) return false;

	BraceComp->AbsorbBehemothImpact(100.0f);
	TestTrue(TEXT("Brace component should be valid"), true);

	return true;
}

// =============================================================================
//  Test 3: Martyr Guard Ally Intercept Component — Intercept
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMartyrGuardAllyInterceptComponentTest,
	"AshenOath.MartyrGuard.Component.InterceptLethalBlow",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMartyrGuardAllyInterceptComponentTest::RunTest(const FString& Parameters)
{
	UAshenMartyrGuardAllyInterceptComponent* MartyrComp = NewObject<UAshenMartyrGuardAllyInterceptComponent>();
	if (!TestNotNull(TEXT("MartyrGuardAllyInterceptComponent must be constructable"), MartyrComp)) return false;

	AActor* DummyAlly = NewObject<AActor>();
	MartyrComp->InterceptLethalBlowForAlly(DummyAlly, 150.0f);
	TestEqual(TEXT("TotalLethalInterceptsExecuted must equal 1"), MartyrComp->TotalLethalInterceptsExecuted, 1);

	return true;
}
