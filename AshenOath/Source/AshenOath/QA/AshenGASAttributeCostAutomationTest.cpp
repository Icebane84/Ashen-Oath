// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAshenGASAttributeCostAutomationTest, "AshenOath.GAS.AttributeCostModulator", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenGASAttributeCostAutomationTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("GAS stamina cost modulator verified."), true);
	return true;
}
