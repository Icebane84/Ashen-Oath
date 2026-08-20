// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Companions/AshenGarrettCoverInterceptionAdapterComponent.h"
#include "Companions/AshenSerafinaAuraBuffScaleModulatorComponent.h"
#include "Companions/AshenRelationalTrustAtrophyCalculator.h"
#include "Soul/AshenSoulStateVector.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterRelationalPhenotypeTest,
	"AshenOath.Milestone775.MasterRelationalPhenotype.Validation",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)

bool FAshenMasterRelationalPhenotypeTest::RunTest(const FString& Parameters)
{
	FSoulStateVector State;
	State.GarrettTrust = 0.8f;
	State.SerafinaTrust = 0.7f;

	// 1. Test Garrett Cover Interception
	UAshenGarrettCoverInterceptionAdapterComponent* GarrettComp = NewObject<UAshenGarrettCoverInterceptionAdapterComponent>();
	GarrettComp->OnSoulStateInvalidated(State);
	TestEqual(TEXT("Garrett interception threshold matches trust"), GarrettComp->GetInterceptionThreshold(), 0.8f);

	// 2. Test Trust Atrophy Calculator
	float NewTrust = UAshenRelationalTrustAtrophyCalculator::CalculateTrustAtrophy(0.8f, 3);
	TestEqual(TEXT("Trust decay calculated correctly for 3 ignored barks"), NewTrust, 0.65f);

	return true;
}
