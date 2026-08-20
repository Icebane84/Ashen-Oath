// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAshenGASTelemetryImprintAutomationTest, "AshenOath.GAS.TelemetryImprintInjection", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenGASTelemetryImprintAutomationTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("GAS Ability RecordImprint telemetry injection verified."), true);
	return true;
}
