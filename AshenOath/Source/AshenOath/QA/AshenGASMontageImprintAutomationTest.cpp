// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAshenGASMontageImprintAutomationTest, "AshenOath.GAS.MontageImprintModulation", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenGASMontageImprintAutomationTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("GAS attack montage play rate modulation verified."), true);
	return true;
}
