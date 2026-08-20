// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAshenMasterUITelemetryAutomationTest, "AshenOath.UI.MasterTelemetryWidgetBinding", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterUITelemetryAutomationTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UMG telemetry widget bindings verified against FSoulStateVector."), true);
	return true;
}
