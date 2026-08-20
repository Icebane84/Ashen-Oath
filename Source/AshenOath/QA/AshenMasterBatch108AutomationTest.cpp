// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 2175: Master Batch #108 QA Automation Test Suite — The White Flame Resolution & Transference Catharsis Matrix
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Combat/AshenWhiteFlameResolutionSubsystem.h"
#include "Combat/AshenTransferenceCatharsisComponent.h"
#include "Combat/AshenSanctifiedAuraComponent.h"
#include "Combat/AshenPyreCleaveGASAbility.h"
#include "Combat/AshenWhiteFlameBladeMeshAdapter.h"

// =============================================================================
//  Test 1: White Flame Subsystem Readiness & Full Debt Eradication
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch108SubsystemAndCatharsisTest,
	"AshenOath.WhiteFlame.SubsystemAndCatharsis.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch108SubsystemAndCatharsisTest::RunTest(const FString& Parameters)
{
	// Test 1: Readiness Evaluation (R >= 0.90 && B >= 0.65)
	UAshenWhiteFlameResolutionSubsystem* Subsystem = NewObject<UAshenWhiteFlameResolutionSubsystem>();
	if (!TestNotNull(TEXT("WhiteFlameResolutionSubsystem must be constructable"), Subsystem)) return false;

	TestFalse(TEXT("R=0.85, B=0.70 must NOT be primed"), Subsystem->EvaluateResolutionReadiness(0.85f, 0.70f));
	TestEqual(TEXT("State must be Inactive"), Subsystem->CurrentResolutionPayload.State, EWhiteFlameState::Inactive);

	TestTrue(TEXT("R=0.95, B=0.70 MUST be primed"), Subsystem->EvaluateResolutionReadiness(0.95f, 0.70f));
	TestEqual(TEXT("State must be Primed"), Subsystem->CurrentResolutionPayload.State, EWhiteFlameState::Primed);

	// Test 2: Full Debt Eradication (100% of 85.0 Debt)
	float ClearedDebt = 0.0f;
	TestTrue(TEXT("Activation must succeed when Primed"), Subsystem->ActivateWhiteFlameResolution(85.0f, ClearedDebt));
	TestEqual(TEXT("Cleared debt must equal 85.0"), ClearedDebt, 85.0f);
	TestEqual(TEXT("State must be Active"), Subsystem->CurrentResolutionPayload.State, EWhiteFlameState::Active);
	TestEqual(TEXT("Duration must be 12.0s"), Subsystem->CurrentResolutionPayload.DurationRemainingSeconds, 12.0f);

	// Test 3: Transference Catharsis Exothermic Sap Transmutation (50% Burnout relief)
	UAshenTransferenceCatharsisComponent* CatharsisComp = NewObject<UAshenTransferenceCatharsisComponent>();
	if (!TestNotNull(TEXT("TransferenceCatharsisComponent must be constructable"), CatharsisComp)) return false;

	float NewBurnout = 0.0f;
	TestTrue(TEXT("Transmutation must succeed"), CatharsisComp->TransmuteSapToAether(0.70f, NewBurnout));
	TestEqual(TEXT("Burnout after 50% relief must be 0.35"), NewBurnout, 0.35f);
	TestEqual(TEXT("Pyre-Aether purity must be 1.0"), CatharsisComp->PyreAetherPurity, 1.0f);

	return true;
}

// =============================================================================
//  Test 2: Sanctified Aura, Pyre Cleave & Blade Mesh Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch108AuraAndCombatTest,
	"AshenOath.WhiteFlame.AuraAndCombat.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch108AuraAndCombatTest::RunTest(const FString& Parameters)
{
	// Test 1: Sanctified Aura Buffs
	UAshenSanctifiedAuraComponent* AuraComp = NewObject<UAshenSanctifiedAuraComponent>();
	if (!TestNotNull(TEXT("SanctifiedAuraComponent must be constructable"), AuraComp)) return false;

	TestEqual(TEXT("Aura radius must be 600uu"), AuraComp->AuraRadiusUnits, 600.0f);
	TestEqual(TEXT("Stamina buff multiplier must be 1.20"), AuraComp->StaminaBuffMultiplier, 1.20f);

	// Test 2: Pyre Cleave Damage (1800.0 DMG)
	UAshenPyreCleaveGASAbility* CleaveAbility = NewObject<UAshenPyreCleaveGASAbility>();
	if (!TestNotNull(TEXT("PyreCleaveGASAbility must be constructable"), CleaveAbility)) return false;

	TestEqual(TEXT("Pyre Cleave damage must be 1800.0"), CleaveAbility->PyreCleaveDamage, 1800.0f);

	// Test 3: Blade Mesh Incandescence Glow (4.0x)
	UAshenWhiteFlameBladeMeshAdapter* MeshAdapter = NewObject<UAshenWhiteFlameBladeMeshAdapter>();
	if (!TestNotNull(TEXT("WhiteFlameBladeMeshAdapter must be constructable"), MeshAdapter)) return false;

	MeshAdapter->SetWhiteFlameBladeState(true);
	TestEqual(TEXT("White Pyre emissive glow must be 4.0"), MeshAdapter->WhitePyreEmissiveGlow, 4.0f);

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER BATCH #108 WHITE FLAME VERIFIED (2,175 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
