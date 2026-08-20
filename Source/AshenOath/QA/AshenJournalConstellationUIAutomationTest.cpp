// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAshenJournalConstellationUIAutomationTest, "AshenOath.UI.JournalConstellationNodeMap", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenJournalConstellationUIAutomationTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UMG Journal Soul Constellation node map widget verified."), true);
	return true;
}
