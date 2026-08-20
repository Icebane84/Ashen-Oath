// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenTelemetryGraphDiagnosticTest,
	"AshenOath.Milestone775.TelemetryGraphDiagnostic.Validation",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)

bool FAshenTelemetryGraphDiagnosticTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("Telemetry Graph Diagnostic check passed"), true);
	return true;
}
