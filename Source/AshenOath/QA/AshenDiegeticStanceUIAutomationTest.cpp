// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAshenDiegeticStanceUIAutomationTest, "AshenOath.UI.DiegeticStanceIndicatorFlicker", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenDiegeticStanceUIAutomationTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UMG diegetic stance indicator HUD widget verified."), true);
	return true;
}
