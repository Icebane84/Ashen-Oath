// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "World/AshenSomaticPhenotypeIntegratorComponent.h"
#include "World/AshenVeinCreepFacialPhenotypeIntegrator.h"
#include "World/AshenGenerativeWorldPhenotypeIntegrator.h"
#include "World/AshenNPCReactivityPhenotypeIntegrator.h"
#include "Companions/AshenGarrettAIFormationPhenotypeAdapter.h"
#include "Combat/AshenOathbringerWeaponEmissiveIntegrator.h"
#include "Soul/AshenSoulStateVector.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterComponentPhenotypeTest,
	"AshenOath.Milestone735.ComponentPhenotype.Integration",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)

bool FAshenMasterComponentPhenotypeTest::RunTest(const FString& Parameters)
{
	FSoulStateVector State;
	State.Resolve = 0.4f;
	State.Corruption = 0.7f;
	State.Isolation = 0.5f;

	// 1. Test Somatic Integrator
	UAshenSomaticPhenotypeIntegratorComponent* SomaticComp = NewObject<UAshenSomaticPhenotypeIntegratorComponent>();
	SomaticComp->OnSoulStateInvalidated(State);
	TestEqual(TEXT("Eye emissive scales 5x corruption"), SomaticComp->GetEyeEmissiveScalar(), 3.5f);

	// 2. Test Vein Creep Integrator
	UAshenVeinCreepFacialPhenotypeIntegrator* VeinComp = NewObject<UAshenVeinCreepFacialPhenotypeIntegrator>();
	VeinComp->OnSoulStateInvalidated(State);
	TestEqual(TEXT("Vein creep matches corruption"), VeinComp->GetVeinCreepScalar(), 0.7f);

	// 3. Test World Integrator
	UAshenGenerativeWorldPhenotypeIntegrator* WorldComp = NewObject<UAshenGenerativeWorldPhenotypeIntegrator>();
	WorldComp->OnSoulStateInvalidated(State);
	TestTrue(TEXT("Weather tension is scaled for high corruption"), WorldComp->GetWeatherTension() > 0.6f);

	// 4. Test Oathbringer Weapon Emissive Integrator
	UAshenOathbringerWeaponEmissiveIntegrator* WeaponComp = NewObject<UAshenOathbringerWeaponEmissiveIntegrator>();
	WeaponComp->OnSoulStateInvalidated(State);
	TestEqual(TEXT("Oathbringer emissive scales 4x corruption"), WeaponComp->GetOathbringerEmissiveScalar(), 2.8f);

	return true;
}
