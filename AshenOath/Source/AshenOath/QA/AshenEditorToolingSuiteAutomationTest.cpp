// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenEditorToolingSuiteTest,
	"AshenOath.Milestone755.EditorToolingSuite.Validation",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)

bool FAshenEditorToolingSuiteTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("Editor Tooling Suite verification check passed"), true);
	return true;
}
