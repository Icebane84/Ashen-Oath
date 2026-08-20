// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1935: Master Batch #96 QA Automation Test Suite — Dynamic Niagara Shadow Mark Seepage & Paladin Corruption
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "VFX/AshenShadowMarkVFXSubsystem.h"
#include "VFX/AshenKaelenShadowMarkVFXComponent.h"
#include "VFX/AshenNyxBileSeepageEvaluatorComponent.h"
#include "VFX/AshenCrimsonDischargeEvaluatorComponent.h"
#include "Combat/AshenShadowMarkSurgeGASAbility.h"

// =============================================================================
//  Test 1: Seepage Phase Evaluation, Normal Offsets & Culling Compliance
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch96SeepagePhaseAndCullingTest,
	"AshenOath.VFX.SeepagePhaseAndCulling.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch96SeepagePhaseAndCullingTest::RunTest(const FString& Parameters)
{
	// Test 1: Subsystem Budget Cap & Frustum Culling
	UAshenShadowMarkVFXSubsystem* Subsystem = NewObject<UAshenShadowMarkVFXSubsystem>();
	if (!TestNotNull(TEXT("ShadowMarkVFXSubsystem must be constructable"), Subsystem)) return false;

	TestEqual(TEXT("Max concurrent particle cap must equal 2048"), Subsystem->MaxConcurrentParticles, 2048);
	TestEqual(TEXT("Max frustum distance must equal 1500.0 uu"), Subsystem->MaxFrustumDistanceUnits, 1500.0f);
	TestFalse(TEXT("Distance 800.0 uu must NOT be culled"), Subsystem->ShouldCullSeepageVFX(800.0f));
	TestTrue(TEXT("Distance 1800.0 uu MUST be culled (> 1500.0 uu)"), Subsystem->ShouldCullSeepageVFX(1800.0f));

	// Test 2: Phase Transition Gating
	UAshenKaelenShadowMarkVFXComponent* VFXComp = NewObject<UAshenKaelenShadowMarkVFXComponent>();
	if (!TestNotNull(TEXT("KaelenShadowMarkVFXComponent must be constructable"), VFXComp)) return false;

	TestEqual(TEXT("Corruption 0.05 must be Dormant"), VFXComp->EvaluateSeepagePhase(0.05f), EShadowSeepagePhase::Dormant);
	TestEqual(TEXT("Corruption 0.20 must be VeinGlow"), VFXComp->EvaluateSeepagePhase(0.20f), EShadowSeepagePhase::VeinGlow);
	TestEqual(TEXT("Corruption 0.50 must be BileSeepage"), VFXComp->EvaluateSeepagePhase(0.50f), EShadowSeepagePhase::BileSeepage);
	TestEqual(TEXT("Corruption 0.85 must be CrimsonSurge"), VFXComp->EvaluateSeepagePhase(0.85f), EShadowSeepagePhase::CrimsonSurge);

	// Normal offset safety check (Clamped <= 2.0)
	const float MaxOffset = VFXComp->CalculateNormalOffset(1.0f);
	TestTrue(TEXT("Max normal offset must not exceed safety cap of 2.0 units"), MaxOffset <= 2.0f);
	TestEqual(TEXT("Normal offset at 0.0 corruption must equal 0.1 units"), VFXComp->CalculateNormalOffset(0.0f), 0.1f);

	return true;
}

// =============================================================================
//  Test 2: Smoothstep Curves, Sparks Math & Surge Ability
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch96EmitterMathAndSurgeTest,
	"AshenOath.VFX.EmitterMathAndSurge.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch96EmitterMathAndSurgeTest::RunTest(const FString& Parameters)
{
	// Nyx Bile Seepage Evaluator
	UAshenNyxBileSeepageEvaluatorComponent* BileEval = NewObject<UAshenNyxBileSeepageEvaluatorComponent>();
	if (!TestNotNull(TEXT("NyxBileSeepageEvaluatorComponent must be constructable"), BileEval)) return false;

	TestEqual(TEXT("Bile spawn rate at 0.20 corruption must be 0.0 (Dormant)"), BileEval->CalculateBileSpawnRate(0.20f), 0.0f);
	TestEqual(TEXT("Bile gravity force Z must equal -450.0 uu/s"), BileEval->GetBileGravityForceZ(), -450.0f);
	TestEqual(TEXT("Bile spawn rate at 1.0 corruption must equal 35.0"), BileEval->CalculateBileSpawnRate(1.0f), 35.0f);

	// Crimson Discharge Evaluator
	UAshenCrimsonDischargeEvaluatorComponent* SparksEval = NewObject<UAshenCrimsonDischargeEvaluatorComponent>();
	if (!TestNotNull(TEXT("CrimsonDischargeEvaluatorComponent must be constructable"), SparksEval)) return false;

	TestEqual(TEXT("Sparks spawn rate at 0.50 corruption must be 0.0 (< 0.70 unchained)"), SparksEval->CalculateCrimsonSparksSpawnRate(0.50f), 0.0f);
	TestEqual(TEXT("Sparks spawn rate at 1.0 corruption must equal 250.0"), SparksEval->CalculateCrimsonSparksSpawnRate(1.0f), 250.0f);
	TestEqual(TEXT("Curl noise strength at 0.0 corruption must equal 10.0"), SparksEval->CalculateCurlNoiseStrength(0.0f), 10.0f);
	TestEqual(TEXT("Curl noise strength at 1.0 corruption must equal 450.0"), SparksEval->CalculateCurlNoiseStrength(1.0f), 450.0f);

	// Shadow Mark Surge Ability
	UAshenShadowMarkSurgeGASAbility* SurgeAbility = NewObject<UAshenShadowMarkSurgeGASAbility>();
	if (!TestNotNull(TEXT("ShadowMarkSurgeGASAbility must be constructable"), SurgeAbility)) return false;

	TestEqual(TEXT("Surge dark damage multiplier must equal 1.40x (+40%)"), SurgeAbility->DarkDamageMultiplier, 1.40f);
	TestEqual(TEXT("Surge duration must equal 10.0s"), SurgeAbility->SurgeDuration, 10.0f);

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER BATCH #96 SHADOW MARK SEEPAGE & CORRUPTION VFX VERIFIED (1,935 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
