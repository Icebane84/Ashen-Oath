// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Combat/AshenStanceBlendTreePhenotypeModulator.h"
#include "Combat/AshenParryWindowPerceptionDistortionComponent.h"
#include "Combat/AshenStaminaPulseAudioResonanceComponent.h"
#include "Soul/AshenSoulStateVector.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCombatStancePhenotypeTest,
	"AshenOath.Milestone775.CombatStancePhenotype.Validation",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)

bool FAshenCombatStancePhenotypeTest::RunTest(const FString& Parameters)
{
	FSoulStateVector State;
	State.Resolve = 0.5f;
	State.Corruption = 0.8f;
	State.Isolation = 0.6f;

	// 1. Test Stance Blend Tree
	UAshenStanceBlendTreePhenotypeModulator* StanceComp = NewObject<UAshenStanceBlendTreePhenotypeModulator>();
	StanceComp->OnSoulStateInvalidated(State);
	TestEqual(TEXT("Stance blend weight matches corruption/resolve ratio"), StanceComp->GetStanceBlendWeight(), 0.65f);

	// 2. Test Parry Window Perception Offset
	UAshenParryWindowPerceptionDistortionComponent* ParryComp = NewObject<UAshenParryWindowPerceptionDistortionComponent>();
	ParryComp->OnSoulStateInvalidated(State);
	TestEqual(TEXT("Parry visual offset matches isolation ratio"), ParryComp->GetParryVisualOffset(), 0.09f);

	// 3. Test Stamina Panting Pitch
	UAshenStaminaPulseAudioResonanceComponent* StaminaComp = NewObject<UAshenStaminaPulseAudioResonanceComponent>();
	StaminaComp->OnSoulStateInvalidated(State);
	TestEqual(TEXT("Stamina panting pitch matches breathing rate"), StaminaComp->GetStaminaPantingPitch(), 1.22f);

	return true;
}
