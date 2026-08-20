// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Companions/AshenGarrettTripleComboFlankAdapterComponent.h"
#include "Companions/UAshenRelationalTripleSynergyDamageCalculator.h"
#include "Soul/AshenSoulStateVector.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAshenGarrettTripleComboAutomationTest, "AshenOath.Companions.GarrettTripleComboAutomationTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenGarrettTripleComboAutomationTest::RunTest(const FString& Parameters)
{
	UAshenGarrettTripleComboFlankAdapterComponent* Comp = NewObject<UAshenGarrettTripleComboFlankAdapterComponent>();
	TestNotNull(TEXT("Component must be valid"), Comp);

	FSoulStateVector TestState;
	TestState.GarrettTrust = 0.8f;
	Comp->OnSoulStateInvalidated(TestState);

	float Mult = UAshenRelationalTripleSynergyDamageCalculator::CalculateTripleSynergyMultiplier(0.8f, 0.8f, 0.5f);
	TestTrue(TEXT("Triple synergy multiplier should be > 2.0"), Mult > 2.0f);
	return true;
}
