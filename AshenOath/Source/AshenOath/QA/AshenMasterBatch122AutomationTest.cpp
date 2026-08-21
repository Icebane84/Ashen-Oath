// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Combat/AshenBossArenaTypes.h"
#include "Combat/AshenBossPhaseEvaluatorComponent.h"
#include "Combat/AshenArenaDestructionCoordinatorComponent.h"
#include "Combat/AshenCompanionCrisisResolverComponent.h"
#include "Core/AshenBossEncounterSaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch122AutomationTest,
	"AshenOath.Combat.MasterBatch122_BossEncounter",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch122AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST 3-PHASE BOSS PROGRESSION
	// -----------------------------------------------------------------------------------
	{
		UAshenBossPhaseEvaluatorComponent* PhaseEvaluator = NewObject<UAshenBossPhaseEvaluatorComponent>();

		// Phase 1 (100% HP)
		EBossEncounterPhase PhaseOut = EBossEncounterPhase::Phase1_Guardian;
		PhaseEvaluator->EvaluateHealth(1.0f, PhaseOut);
		TestEqual(TEXT("100% HP is Phase 1"), PhaseOut, EBossEncounterPhase::Phase1_Guardian);

		// Phase 2 (50% HP)
		PhaseEvaluator->EvaluateHealth(0.50f, PhaseOut);
		TestEqual(TEXT("50% HP is Phase 2 Nightsteel Titan"), PhaseOut, EBossEncounterPhase::Phase2_NightsteelTitan);

		// Phase 3 (20% HP)
		PhaseEvaluator->EvaluateHealth(0.20f, PhaseOut);
		TestEqual(TEXT("20% HP is Phase 3 Umbral Meltdown"), PhaseOut, EBossEncounterPhase::Phase3_UmbralMeltdown);

		// Defeated (0% HP)
		PhaseEvaluator->EvaluateHealth(0.0f, PhaseOut);
		TestEqual(TEXT("0% HP is Defeated"), PhaseOut, EBossEncounterPhase::Defeated);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST ARENA PILLAR DESTRUCTION
	// -----------------------------------------------------------------------------------
	{
		UAshenArenaDestructionCoordinatorComponent* DestructComp = NewObject<UAshenArenaDestructionCoordinatorComponent>();

		TestEqual(TEXT("Initial intact pillars is 4"), DestructComp->GetIntactPillarsCount(), 4);
		TestNearlyEqual(TEXT("Initial obstruction is 0.0"), DestructComp->GetObstructionScalar(), 0.0f, 0.01f);

		// Sunder 2 pillars
		DestructComp->SunderPillar(0);
		const float Obs2 = DestructComp->SunderPillar(1);

		TestEqual(TEXT("Remaining intact pillars is 2"), DestructComp->GetIntactPillarsCount(), 2);
		TestNearlyEqual(TEXT("Obstruction is 0.50 (50%)"), Obs2, 0.50f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST COMPANION PINNING CRISIS & TRANSFERENCE RESCUE
	// -----------------------------------------------------------------------------------
	{
		UAshenCompanionCrisisResolverComponent* CrisisComp = NewObject<UAshenCompanionCrisisResolverComponent>();

		const FCompanionCrisisContext Ctx = CrisisComp->OpenCrisisWindow(TEXT("Garrett"), 3.0f);
		TestEqual(TEXT("Crisis state is PinnedInExecution"), Ctx.CrisisState, ECompanionCrisisState::PinnedInExecution);
		TestEqual(TEXT("Pinned companion is Garrett"), Ctx.PinnedCompanionName, FName(TEXT("Garrett")));

		// Intervene via Transference
		ECompanionCrisisState Outcome = ECompanionCrisisState::None;
		float TrustDelta = 0.0f;
		const bool bSuccess = CrisisComp->ResolveCrisis(true, Outcome, TrustDelta);

		TestTrue(TEXT("Crisis resolved"), bSuccess);
		TestEqual(TEXT("Outcome is RescuedByTransference"), Outcome, ECompanionCrisisState::RescuedByTransference);
		TestNearlyEqual(TEXT("Trust gained is +0.20"), TrustDelta, 0.20f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST BOSS ENCOUNTER SAVEGAME ADAPTER
	// -----------------------------------------------------------------------------------
	{
		UAshenBossEncounterSaveGameAdapter* SaveAdapter = NewObject<UAshenBossEncounterSaveGameAdapter>();

		SaveAdapter->PackageBossData(true, 3, 2);
		TestTrue(TEXT("HasSavedData is true"), SaveAdapter->HasSavedData());

		bool bRestoredDefeated = false;
		int32 RestoredPillars = 0;
		int32 RestoredRescues = 0;
		const bool bSuccess = SaveAdapter->RestoreBossData(bRestoredDefeated, RestoredPillars, RestoredRescues);

		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestTrue(TEXT("Defeated restored"), bRestoredDefeated);
		TestEqual(TEXT("Pillars sundered restored"), RestoredPillars, 3);
		TestEqual(TEXT("Rescues performed restored"), RestoredRescues, 2);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
