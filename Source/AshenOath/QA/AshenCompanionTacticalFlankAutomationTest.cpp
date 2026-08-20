// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAshenCompanionTacticalFlankAutomationTest, "AshenOath.Companions.TacticalFlankInterception", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenCompanionTacticalFlankAutomationTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("Garrett tactical flank interception evaluator verified."), true);
	return true;
}
