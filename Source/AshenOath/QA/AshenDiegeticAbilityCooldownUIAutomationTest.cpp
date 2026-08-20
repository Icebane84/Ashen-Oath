// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "UI/AshenUserWidget_DiegeticAbilityCooldownHUD.h"
#include "Soul/AshenSoulStateVector.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAshenDiegeticAbilityCooldownUIAutomationTest, "AshenOath.UI.DiegeticAbilityCooldownHUDTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenDiegeticAbilityCooldownUIAutomationTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_DiegeticAbilityCooldownHUD* Widget = NewObject<UAshenUserWidget_DiegeticAbilityCooldownHUD>();
	TestNotNull(TEXT("Widget must be valid"), Widget);

	FSoulStateVector TestState;
	TestState.Resolve = 1.0f;
	Widget->OnSoulStateInvalidated(TestState);

	TestEqual(TEXT("Opacity should be 1.0 at maximum resolve"), Widget->GetCooldownPulseOpacity(), 1.0f);
	return true;
}
