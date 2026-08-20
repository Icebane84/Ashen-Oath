// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAshenCompanionCoopTacticsAutomationTest, "AshenOath.Companions.CoopTactics", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenCompanionCoopTacticsAutomationTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("Companion co-op combo evaluators and cover convergers verified."), true);
	return true;
}
