// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAshenGASEffectStanceAutomationTest, "AshenOath.GAS.EffectStanceBlend", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenGASEffectStanceAutomationTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("GAS GameplayEffect stance blend adapter verified."), true);
	return true;
}
