// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Soul/AshenSoulStateVector.h"
#include "Soul/AshenBehavioralProfileDerivationEngine.h"
#include "Soul/AshenSoulIdentityTriadCalculator.h"
#include "Soul/AshenSoulStateVectorLegacyBridge.h"
#include "World/AshenSomaticPostureControllerComponent.h"
#include "World/AshenSomaticEyeResonanceModulatorComponent.h"
#include "Companions/AshenGarrettRelationalPhenotypeAdapter.h"
#include "World/AshenGenerativeWorldPhenotypeAdapter.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterPsychologicalPhenotypeTest,
	"AshenOath.Milestone695.PsychologicalPhenotype.Unification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)

bool FAshenMasterPsychologicalPhenotypeTest::RunTest(const FString& Parameters)
{
	// 1. Test FSoulStateVector Normalization
	FSoulStateVector RawState;
	RawState.Resolve = 1.5f;
	RawState.Corruption = -0.5f;

	FSoulStateVector CleanState = UAshenSoulIdentityTriadCalculator::NormalizeSoulStateVector(RawState);
	TestEqual(TEXT("Resolve must be clamped to 1.0"), CleanState.Resolve, 1.0f);
	TestEqual(TEXT("Corruption must be clamped to 0.0"), CleanState.Corruption, 0.0f);

	// 2. Test Behavioral Profile Derivation
	FBehavioralProfile Profile = UAshenBehavioralProfileDerivationEngine::DeriveBehavioralProfile(CleanState);
	TestTrue(TEXT("Upright grounded stance derived for clean state"), Profile.Stance == EStanceProfile::Upright_Grounded);

	// 3. Test Somatic Posture Modulator
	UAshenSomaticPostureControllerComponent* PostureComp = NewObject<UAshenSomaticPostureControllerComponent>();
	PostureComp->UpdatePostureWeight(Profile.Stance);
	TestEqual(TEXT("Upright stance produces 0.0 blend weight"), PostureComp->GetPostureBlendWeight(), 0.0f);

	// 4. Test Eye Emissive Modulator
	UAshenSomaticEyeResonanceModulatorComponent* EyeComp = NewObject<UAshenSomaticEyeResonanceModulatorComponent>();
	EyeComp->UpdateEyeEmissive(0.8f);
	TestEqual(TEXT("Eye emissive scalar must be 4.0 for 0.8 corruption"), EyeComp->GetEyeEmissiveIntensity(), 4.0f);

	// 5. Test Legacy Bridge Conversion
	FSoulStateVector BridgeVector = UAshenSoulStateVectorLegacyBridge::ConvertLegacyMetersToCanonicalVector(75.0f, 25.0f, 50.0f);
	TestEqual(TEXT("Bridge resolve must be 0.75"), BridgeVector.Resolve, 0.75f);
	TestEqual(TEXT("Bridge corruption must be 0.25"), BridgeVector.Corruption, 0.25f);

	return true;
}
