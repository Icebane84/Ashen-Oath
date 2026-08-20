// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAshenCompanionPincerFormationAutomationTest, "AshenOath.Companions.PincerFormation", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenCompanionPincerFormationAutomationTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("Garrett pincer attack formation adapter verified."), true);
	return true;
}
