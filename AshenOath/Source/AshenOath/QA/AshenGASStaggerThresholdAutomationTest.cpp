// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Combat/AshenGASEffectStaggerThresholdModulatorComponent.h"
#include "Soul/AshenSoulStateVector.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAshenGASStaggerThresholdAutomationTest, "AshenOath.Combat.GASStaggerThresholdModulatorTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenGASStaggerThresholdAutomationTest::RunTest(const FString& Parameters)
{
	UAshenGASEffectStaggerThresholdModulatorComponent* Modulator = NewObject<UAshenGASEffectStaggerThresholdModulatorComponent>();
	TestNotNull(TEXT("Modulator created"), Modulator);

	FSoulStateVector TestState;
	TestState.Corruption = 0.8f;
	Modulator->OnSoulStateInvalidated(TestState);

	TestEqual(TEXT("Stagger poise multiplier updated"), Modulator->GetStaggerPoiseMultiplier(), 0.6f);
	return true;
}
