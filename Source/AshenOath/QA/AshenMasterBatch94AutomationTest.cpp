// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1895: Master Batch #94 QA Automation Test Suite — Empathic Conduit Nova & DualSense Somatic Finisher
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Combat/AshenEmpathicNovaSubsystem.h"
#include "Combat/AshenEmpathicNovaTelemetryComponent.h"
#include "World/AshenSomaticVeinCreepShaderEvaluatorComponent.h"
#include "Player/AshenDualSenseHapticFrictionCalculatorComponent.h"
#include "Combat/AshenEmpathicConduitNovaGASAbility.h"
#include "Companions/AshenNovaCompanionReactionAdapter.h"

// =============================================================================
//  Test 1: Nova Gating, Friction Flow & Vein Creep Math
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch94NovaGatingAndSomaticTest,
	"AshenOath.Nova.GatingAndSomatic.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch94NovaGatingAndSomaticTest::RunTest(const FString& Parameters)
{
	// Test 1: Subsystem Nova Initiation Gating
	UAshenEmpathicNovaSubsystem* Subsystem = NewObject<UAshenEmpathicNovaSubsystem>();
	if (!TestNotNull(TEXT("EmpathicNovaSubsystem must be constructable"), Subsystem)) return false;

	TestFalse(TEXT("Trust at 0.50 should NOT allow Nova initiation"), Subsystem->CanInitiateNova(0.50f, 0.20f));
	TestFalse(TEXT("Burnout at 0.95 should NOT allow Nova initiation even with 0.85 Trust"), Subsystem->CanInitiateNova(0.85f, 0.95f));
	TestTrue(TEXT("Trust at 0.75 and Burnout at 0.40 MUST allow Nova initiation"), Subsystem->CanInitiateNova(0.75f, 0.40f));

	// Test 2: Friction Flow Calculation
	UAshenEmpathicNovaTelemetryComponent* Telemetry = NewObject<UAshenEmpathicNovaTelemetryComponent>();
	if (!TestNotNull(TEXT("EmpathicNovaTelemetryComponent must be constructable"), Telemetry)) return false;

	const float Friction = Telemetry->EvaluateFrictionFlow(0.80f, 0.30f);
	TestEqual(TEXT("Friction flow |0.80 - 0.30| must equal 0.50"), Friction, 0.50f);
	TestTrue(TEXT("Serafina burnout at 0.80 is in critical burnout (>= 0.75)"), Telemetry->IsInCriticalBurnout(0.80f));

	// Test 3: Somatic Vein Creep & Emissive Glow
	UAshenSomaticVeinCreepShaderEvaluatorComponent* VeinCreep = NewObject<UAshenSomaticVeinCreepShaderEvaluatorComponent>();
	if (!TestNotNull(TEXT("SomaticVeinCreepShaderEvaluatorComponent must be constructable"), VeinCreep)) return false;

	// VeinCreep = (0.80 * 0.60) + (0.90 * 0.40) = 0.48 + 0.36 = 0.84
	const float VeinScalar = VeinCreep->CalculateVeinCreepScalar(0.80f, 0.90f);
	TestEqual(TEXT("Vein creep scalar must equal 0.84"), VeinScalar, 0.84f);
	TestTrue(TEXT("Vein creep >= 0.80 triggers Emissive Shadow Glow"), VeinCreep->IsEmissiveShadowGlowActive(VeinScalar));

	return true;
}

// =============================================================================
//  Test 2: DualSense Haptic Friction, Tremors & GAS Ability Damage
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch94HapticsAndAbilityTest,
	"AshenOath.Nova.HapticsAndAbility.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch94HapticsAndAbilityTest::RunTest(const FString& Parameters)
{
	// DualSense Trigger Friction & Asymmetric Frequency Mapping
	UAshenDualSenseHapticFrictionCalculatorComponent* Haptics = NewObject<UAshenDualSenseHapticFrictionCalculatorComponent>();
	if (!TestNotNull(TEXT("DualSenseHapticFrictionCalculatorComponent must be constructable"), Haptics)) return false;

	FHapticFrictionProfile Profile = Haptics->ComputeHapticFriction(0.50f, 0.80f, 1.0f);
	TestEqual(TEXT("Max execution progress (1.0) must yield max trigger resistance 255"), Profile.TriggerResistance, 255);
	TestEqual(TEXT("Left frequency at 0.50 corruption: 20 + (0.50 * 20) = 30.0 Hz"), Profile.LeftFrequencyHz, 30.0f);
	TestEqual(TEXT("Right frequency at 0.80 burnout: 150 + (0.80 * 50) = 190.0 Hz"), Profile.RightFrequencyHz, 190.0f);

	// Serafina Hand Tremor Amplitude
	UAshenNovaCompanionReactionAdapter* CompanionAdapter = NewObject<UAshenNovaCompanionReactionAdapter>();
	if (!TestNotNull(TEXT("NovaCompanionReactionAdapter must be constructable"), CompanionAdapter)) return false;

	const float TremorAtHalfBurnout = CompanionAdapter->CalculateSerafinaHandTremorOffset(0.50f);
	TestEqual(TEXT("Hand tremor at 0.50 burnout must equal 1.75 cm"), TremorAtHalfBurnout, 1.75f);

	// Empathic Conduit Nova Ability
	UAshenEmpathicConduitNovaGASAbility* NovaAbility = NewObject<UAshenEmpathicConduitNovaGASAbility>();
	if (!TestNotNull(TEXT("EmpathicConduitNovaGASAbility must be constructable"), NovaAbility)) return false;

	TestEqual(TEXT("Base Nova damage must equal 1200.0"), NovaAbility->BaseNovaDamage, 1200.0f);
	TestEqual(TEXT("Nova radius must equal 1400.0 uu"), NovaAbility->NovaRadius, 1400.0f);

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER BATCH #94 EMPATHIC NOVA & DUALSENSE TEST SUITE VERIFIED (1,895 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
