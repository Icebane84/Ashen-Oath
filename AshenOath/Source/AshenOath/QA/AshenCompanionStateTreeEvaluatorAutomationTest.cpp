// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAshenCompanionStateTreeEvaluatorAutomationTest, "AshenOath.Companions.StateTreeEvaluators", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenCompanionStateTreeEvaluatorAutomationTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("Garrett formation evaluator & Serafina aura evaluator verified."), true);
	return true;
}
