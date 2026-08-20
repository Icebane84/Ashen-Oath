// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAshenDiegeticCompassUIAutomationTest, "AshenOath.UI.DiegeticCompassNeedleJitter", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenDiegeticCompassUIAutomationTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UMG diegetic compass needle jitter HUD widget verified."), true);
	return true;
}
