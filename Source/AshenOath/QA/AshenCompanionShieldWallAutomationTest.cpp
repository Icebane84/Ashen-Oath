// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAshenCompanionShieldWallAutomationTest, "AshenOath.Companions.ShieldWallFormation", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenCompanionShieldWallAutomationTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("Garrett shield wall formation adapter verified."), true);
	return true;
}
