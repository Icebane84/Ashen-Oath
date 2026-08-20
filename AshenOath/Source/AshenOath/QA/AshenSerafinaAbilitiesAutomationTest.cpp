// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 725: Ashen Serafina Abilities & Sanctuary Zone Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenSerafinaDivineJudgmentAbility.h"
#include "AshenSerafinaEmpathicResonanceBuffComponent.h"
#include "AshenSacredGroundSanctuaryZoneActor.h"

// =============================================================================
//  Test 1: Serafina Divine Judgment Ability — Execute Ability
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSerafinaDivineJudgmentAbilityTest,
	"AshenOath.SerafinaAbilities.Ability.DivineJudgment",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSerafinaDivineJudgmentAbilityTest::RunTest(const FString& Parameters)
{
	UAshenSerafinaDivineJudgmentAbility* Ability = NewObject<UAshenSerafinaDivineJudgmentAbility>();
	if (!TestNotNull(TEXT("SerafinaDivineJudgmentAbility must be constructable"), Ability)) return false;

	Ability->ExecuteDivineJudgment(nullptr, 300.0f); // Null target safety test
	return true;
}

// =============================================================================
//  Test 2: Serafina Empathic Resonance Buff Component — Evaluate Buff
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSerafinaEmpathicResonanceBuffComponentTest,
	"AshenOath.SerafinaBuff.Component.EvaluateBuff",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSerafinaEmpathicResonanceBuffComponentTest::RunTest(const FString& Parameters)
{
	UAshenSerafinaEmpathicResonanceBuffComponent* BuffComp = NewObject<UAshenSerafinaEmpathicResonanceBuffComponent>();
	if (!TestNotNull(TEXT("SerafinaEmpathicResonanceBuffComponent must be constructable"), BuffComp)) return false;

	const float Bonus = BuffComp->EvaluateEmpathicResonanceBuff(90.0f);
	TestEqual(TEXT("Uninjured Serafina posture bonus must equal 25.0%"), Bonus, 25.0f);

	return true;
}

// =============================================================================
//  Test 3: Sacred Ground Sanctuary Zone Actor — Trigger Pulse
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSacredGroundSanctuaryZoneActorTest,
	"AshenOath.SacredGround.Actor.TriggerPulse",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSacredGroundSanctuaryZoneActorTest::RunTest(const FString& Parameters)
{
	AAshenSacredGroundSanctuaryZoneActor* Zone = NewObject<AAshenSacredGroundSanctuaryZoneActor>();
	if (!TestNotNull(TEXT("SacredGroundSanctuaryZoneActor must be constructable"), Zone)) return false;

	Zone->TriggerSanctuaryPulse(30.0f);
	TestTrue(TEXT("bIsZoneActive must equal true"), Zone->bIsZoneActive);

	return true;
}
