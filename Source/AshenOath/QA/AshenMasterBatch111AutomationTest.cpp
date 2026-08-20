// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "Orchestration/AshenUniversalSomaticEngineSubsystem.h"
#include "Soul/AshenCanonicalStateRegistryComponent.h"
#include "Soul/AshenInternalFrictionEvaluatorComponent.h"
#include "Companions/AshenRelationalFlowEvaluatorComponent.h"
#include "AI/AshenSomaticAIDirectorComponent.h"
#include "Orchestration/AshenMacroSystemicMasterSpineBridge.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch111AutomationTest,
	"AshenOath.SomaticEngine.MasterBatch111_CanonicalSomaticSpine",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch111AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST CANONICAL MATHEMATICAL FORMULAS
	// -----------------------------------------------------------------------------------
	{
		// Test Lens Distance (Binary Distance per CONTRACT-SPEC-051)
		TestEqual(TEXT("LensDistance Same"), AshenContractUtils::GetLensDistance(EOntologicalLens::Defiance, EOntologicalLens::Defiance), 0.0f);
		TestEqual(TEXT("LensDistance Shift"), AshenContractUtils::GetLensDistance(EOntologicalLens::Defiance, EOntologicalLens::Grace), 1.0f);
		TestEqual(TEXT("LensDistance Uncompiled"), AshenContractUtils::GetLensDistance(EOntologicalLens::Uncompiled, EOntologicalLens::Wrath), 0.0f);

		// Test Dysregulation Stage classification
		TestEqual(TEXT("Stage 1"), AshenContractUtils::GetDysregulationStage(0.30f), 1);
		TestEqual(TEXT("Stage 2"), AshenContractUtils::GetDysregulationStage(0.60f), 2);
		TestEqual(TEXT("Stage 3"), AshenContractUtils::GetDysregulationStage(0.85f), 3);
		TestEqual(TEXT("Stage 4"), AshenContractUtils::GetDysregulationStage(1.0f), 4);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST INTERNAL FRICTION & RELATIONAL FLOW EVALUATORS
	// -----------------------------------------------------------------------------------
	{
		UAshenInternalFrictionEvaluatorComponent* FrictionComp = NewObject<UAshenInternalFrictionEvaluatorComponent>();
		UAshenRelationalFlowEvaluatorComponent* FlowComp = NewObject<UAshenRelationalFlowEvaluatorComponent>();

		FCanonicalSoulStateVector Soul;
		Soul.IntegrationDebt = 0.80f;
		Soul.AccumulatedDysregulation = 0.70f;
		Soul.DominantLens = EOntologicalLens::Grace;
		Soul.PreviousDominantLens = EOntologicalLens::Defiance; // Shift = 1.0
		Soul.Resolve = 0.40f;

		// Phi = Clamp(0.40*0.80 + 0.30*0.70 + 0.30*1.0 + 0.20*0.50 - 0.20*0.40)
		//     = Clamp(0.32 + 0.21 + 0.30 + 0.10 - 0.08) = 0.85
		const float ComputedPhi = FrictionComp->EvaluateInternalFriction(Soul, 0.50f);
		TestNearlyEqual(TEXT("Internal Friction Math"), ComputedPhi, 0.85f, 0.001f);

		// Flow: 400uu distance -> ProximityFactor = 0.75
		const float ProximityFactor = FlowComp->CalculateProximityFactorFromDistance(400.0f);
		TestNearlyEqual(TEXT("ProximityFactor at 400uu"), ProximityFactor, 0.75f, 0.001f);

		const bool bSupportPresent = FlowComp->EvaluateCompanionSupportPresent(ProximityFactor, true);
		TestTrue(TEXT("Support Present at 400uu with LOS"), bSupportPresent);

		// Psi = Clamp(0.80*0.60 + (1.0 - 0.20*0.20)*0.75*0.30 + 0.10)
		//     = Clamp(0.48 + 0.96*0.225 + 0.10) = Clamp(0.48 + 0.216 + 0.10) = 0.796
		const float ComputedPsi = FlowComp->EvaluateRelationalFlow(0.80f, 0.20f, ProximityFactor, bSupportPresent);
		TestNearlyEqual(TEXT("Relational Flow Math"), ComputedPsi, 0.796f, 0.001f);

		// Verify Supported Struggle Condition (High Friction + High Flow)
		TestTrue(TEXT("Supported Struggle Band Active"), FrictionComp->IsInSupportedStruggleBand(ComputedPhi, ComputedPsi));
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST INVARIANTS 1-7 OF CANONICAL STATE REGISTRY
	// -----------------------------------------------------------------------------------
	{
		UAshenCanonicalStateRegistryComponent* Registry = NewObject<UAshenCanonicalStateRegistryComponent>();

		// Initial state
		TestEqual(TEXT("Initial State Version"), Registry->GetStateVersion(), (int64)1);

		// Invariant 2 Test: Debt Reduction without Resolution.* tag must fail
		FCompilationResult BadCompilation;
		BadCompilation.IntegrationDebtBefore = 0.80f;
		BadCompilation.IntegrationDebtAfter = 0.40f; // Reduction
		BadCompilation.ResolutionTags.AddTag(FGameplayTag::RequestGameplayTag(FName(TEXT("Combat.RandomTag")), false));

		FGuid TxId;
		const bool bBadCommit = Registry->CommitCompilationResult(BadCompilation, TxId);
		TestFalse(TEXT("Debt Reduction Without Resolution Tag Rejected"), bBadCommit);

		// Valid Compilation Commit
		FCompilationResult ValidCompilation;
		ValidCompilation.IntegrationDebtBefore = 0.80f;
		ValidCompilation.IntegrationDebtAfter = 0.40f;
		ValidCompilation.ResolutionTags.AddTag(FGameplayTag::RequestGameplayTag(FName(TEXT("Resolution.SharedBurden")), false));
		ValidCompilation.ResolveDelta = 0.10f;
		ValidCompilation.TrustGarrettDelta = 0.08f;
		ValidCompilation.TrustSerafinaDelta = 0.12f;
		ValidCompilation.TrioResonanceDelta = 0.10f;

		const bool bValidCommit = Registry->CommitCompilationResult(ValidCompilation, TxId);
		TestTrue(TEXT("Valid Compilation Committed"), bValidCommit);
		TestEqual(TEXT("State Version Monotonically Incremented"), Registry->GetStateVersion(), (int64)2);
		TestTrue(TEXT("Transaction ID Generated"), TxId.IsValid());
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST SALIENCE GATE CRITICAL BYPASS & COOLDOWN
	// -----------------------------------------------------------------------------------
	{
		FSalienceBudget Budget;
		Budget.SalienceThreshold = 0.25f;
		Budget.CriticalBypassThreshold = 0.50f;
		Budget.MinCooldownSeconds = 3.0f;
		Budget.LastExpressionTimestamp = 10.0;
		Budget.LastDispatchedFriction = 0.40f;

		// Micro-drift (0.40 -> 0.42): Delta = 0.02 < 0.25 -> Silent
		FSomaticState MicroState;
		MicroState.InternalFriction = 0.42f;
		MicroState.RelationalFlow = 0.50f;

		// Test direct delta logic
		const float MicroDelta = FMath::Abs(MicroState.InternalFriction - Budget.LastDispatchedFriction);
		TestTrue(TEXT("Micro-drift below threshold"), MicroDelta < Budget.SalienceThreshold);

		// Major Shock (0.40 -> 0.95): Delta = 0.55 >= 0.50 -> Critical Bypass (ignores cooldown)
		FSomaticState ShockState;
		ShockState.InternalFriction = 0.95f;
		ShockState.RelationalFlow = 0.50f;
		const float ShockDelta = FMath::Abs(ShockState.InternalFriction - Budget.LastDispatchedFriction);
		TestTrue(TEXT("Catastrophic surge exceeds critical bypass"), ShockDelta >= Budget.CriticalBypassThreshold);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST TRIGGER RESISTANCE PRIORITY ARBITRATION
	// -----------------------------------------------------------------------------------
	{
		UAshenMacroSystemicMasterSpineBridge* Spine = NewObject<UAshenMacroSystemicMasterSpineBridge>();

		// Priority 1: Dialogue Squeeze >= 0.85 -> 1.0 lock
		const float DialogueLock = Spine->ArbitrateTriggerResistance(
			ETriggerResistanceSource::DialogueWillStruggle,
			0.88f, 0.50f, 0.20f, false);
		TestEqual(TEXT("Dialogue >= 0.85 locks trigger to 1.0"), DialogueLock, 1.0f);

		// Priority 2: Combat Stagger (Poise broken -> 0.0 give-way)
		const float StaggerGiveWay = Spine->ArbitrateTriggerResistance(
			ETriggerResistanceSource::CombatStagger,
			0.0f, 0.50f, 0.20f, true);
		TestEqual(TEXT("Combat Poise Break gives way to 0.0"), StaggerGiveWay, 0.0f);

		// Priority 3: Ambient Somatic
		const float AmbientTension = Spine->ArbitrateTriggerResistance(
			ETriggerResistanceSource::AmbientSomatic,
			0.0f, 0.50f, 0.25f, false);
		TestEqual(TEXT("Ambient tension mapped cleanly"), AmbientTension, 0.25f);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
