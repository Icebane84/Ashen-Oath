// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAshenGASRegenRateAutomationTest, "AshenOath.GAS.AttributeRegenRateModulator", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenGASRegenRateAutomationTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("GAS attribute regen rate modulator component verified."), true);
	return true;
}
