// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "World/AshenDiegeticScarsCreepComponent.h"
#include "World/AshenDiegeticArmorScuffModulatorComponent.h"
#include "World/AshenDiegeticFootstepAudioResonanceComponent.h"
#include "Soul/AshenSoulStateVector.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenDiegeticPhenotypeExpansionTest,
	"AshenOath.Milestone755.DiegeticPhenotypeExpansion.Validation",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)

bool FAshenDiegeticPhenotypeExpansionTest::RunTest(const FString& Parameters)
{
	FSoulStateVector State;
	State.Resolve = 0.3f;
	State.Corruption = 0.8f;
	State.Isolation = 0.6f;

	// 1. Test Scars Creep Component
	UAshenDiegeticScarsCreepComponent* ScarComp = NewObject<UAshenDiegeticScarsCreepComponent>();
	ScarComp->OnSoulStateInvalidated(State);
	TestTrue(TEXT("Scar emissive intensity scaled for corruption"), ScarComp->GetScarEmissiveIntensity() > 3.0f);

	// 2. Test Armor Scuff Component
	UAshenDiegeticArmorScuffModulatorComponent* ArmorComp = NewObject<UAshenDiegeticArmorScuffModulatorComponent>();
	ArmorComp->OnSoulStateInvalidated(State);
	TestEqual(TEXT("Armor scuff matches isolation"), ArmorComp->GetArmorScuffScalar(), 0.54f);

	// 3. Test Footstep Audio Component
	UAshenDiegeticFootstepAudioResonanceComponent* AudioComp = NewObject<UAshenDiegeticFootstepAudioResonanceComponent>();
	AudioComp->OnSoulStateInvalidated(State);
	TestTrue(TEXT("Footstep audio weight is heavy for low resolve"), AudioComp->GetFootstepWeightScalar() > 1.2f);

	return true;
}
