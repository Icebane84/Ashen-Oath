// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Companions/AshenTripartiteCognitiveLoopTypes.h"
#include "Companions/AshenTripartiteCognitiveLoopSubsystem.h"
#include "Companions/AshenTripartiteEQSSpatialDirector.h"
#include "Companions/AshenSomaticAttunementEvaluator.h"
#include "Companions/AshenCompanionSilenceTransitionHandler.h"
#include "Scenarios/AshenTripartiteHapticBridge.h"
#include "Core/AshenTripartiteSaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch134AutomationTest,
	"AshenOath.Companions.MasterBatch134_TripartiteCognitiveLoop",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch134AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST TRIPARTITE ATTUNEMENT & FINISHER DAMAGE SCALING
	// -----------------------------------------------------------------------------------
	{
		UAshenSomaticAttunementEvaluator* AttunementEvaluator = NewObject<UAshenSomaticAttunementEvaluator>();

		// Low Attunement (0.10) -> Multiplier = 1.0 + 0.20 = 1.20x; Phase = FracturedDivergence
		TestNearlyEqual(TEXT("Low attunement multiplier is 1.20x"), AttunementEvaluator->EvaluateFinisherDamageMultiplier(0.10f), 1.20f, 0.01f);
		TestTrue(TEXT("Phase is FracturedDivergence"), AttunementEvaluator->ClassifyAttunementPhase(0.10f) == ECompanionAttunementPhase::FracturedDivergence);

		// High Attunement (1.00) -> Multiplier = 1.0 + 2.0 = 3.00x; Phase = UnifiedResonance
		TestNearlyEqual(TEXT("Max attunement multiplier is 3.00x"), AttunementEvaluator->EvaluateFinisherDamageMultiplier(1.00f), 3.00f, 0.01f);
		TestTrue(TEXT("Phase is UnifiedResonance"), AttunementEvaluator->ClassifyAttunementPhase(1.00f) == ECompanionAttunementPhase::UnifiedResonance);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST EQS SPATIAL FLANK DIRECTOR
	// -----------------------------------------------------------------------------------
	{
		UAshenTripartiteEQSSpatialDirector* EQSDirector = NewObject<UAshenTripartiteEQSSpatialDirector>();
		const FVector KaelenLoc(0.0f, 0.0f, 0.0f);
		const FVector KaelenFwd(1.0f, 0.0f, 0.0f);

		// Garrett 90 degree flank at 400 uu
		const FVector GarrettPos = EQSDirector->ComputeGarrettTargetLocation(KaelenLoc, KaelenFwd, 90.0f, 400.0f);
		TestNearlyEqual(TEXT("Garrett Y coordinate is 400 uu"), static_cast<float>(GarrettPos.Y), 400.0f, 0.1f);
		TestNearlyEqual(TEXT("Garrett X coordinate is 0 uu"), static_cast<float>(GarrettPos.X), 0.0f, 0.1f);

		// Serafina rear quadrant at 500 uu
		const FVector SerafinaPos = EQSDirector->ComputeSerafinaTargetLocation(KaelenLoc, KaelenFwd, 500.0f);
		TestTrue(TEXT("Serafina is positioned behind Kaelen (X < 0)"), SerafinaPos.X < 0.0f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST SOMATIC SILENCE TRANSITION HANDLER
	// -----------------------------------------------------------------------------------
	{
		UAshenCompanionSilenceTransitionHandler* SilenceHandler = NewObject<UAshenCompanionSilenceTransitionHandler>();

		// Low debt (0.20), no companion downed -> Contemplative Silence
		const ETripartiteBehaviorMode Mode1 = SilenceHandler->ResolvePostCombatSilenceMode(0.20f, false);
		TestTrue(TEXT("Low debt enters Contemplative Silence"), Mode1 == ETripartiteBehaviorMode::ContemplativeSilence);

		// High debt (0.80) -> Trauma Aftermath
		const ETripartiteBehaviorMode Mode2 = SilenceHandler->ResolvePostCombatSilenceMode(0.80f, false);
		TestTrue(TEXT("High debt enters Trauma Aftermath"), Mode2 == ETripartiteBehaviorMode::TraumaAftermath);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST DUALSENSE HAPTICS & SAVEGAME PERSISTENCE
	// -----------------------------------------------------------------------------------
	{
		UAshenTripartiteHapticBridge* HapticBridge = NewObject<UAshenTripartiteHapticBridge>();
		float GarrettTick = 0.0f;
		float SerafinaHum = 0.0f;
		float TriggerLock = 0.0f;

		// Combat mode at 0.85 attunement
		HapticBridge->EvaluateTripartiteHaptics(ETripartiteBehaviorMode::CombatEngagement, 0.85f, GarrettTick, SerafinaHum, TriggerLock);
		TestNearlyEqual(TEXT("Garrett left tick is active"), GarrettTick, 0.74f, 0.02f);
		TestNearlyEqual(TEXT("Sync trigger lock is strong (0.85)"), TriggerLock, 0.85f, 0.01f);

		// SaveGame Adapter
		UAshenTripartiteSaveGameAdapter* SaveAdapter = NewObject<UAshenTripartiteSaveGameAdapter>();
		SaveAdapter->PackageTripartiteState(0.82f, ETripartiteBehaviorMode::ContemplativeSilence, true);
		TestTrue(TEXT("HasSavedData is true"), SaveAdapter->HasSavedData());

		float RestoredScore = 0.0f;
		ETripartiteBehaviorMode RestoredMode;
		bool bRestoredSilence = false;
		const bool bSuccess = SaveAdapter->RestoreTripartiteState(RestoredScore, RestoredMode, bRestoredSilence);

		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestNearlyEqual(TEXT("Restored score is 0.82"), RestoredScore, 0.82f, 0.01f);
		TestTrue(TEXT("Restored mode is Contemplative Silence"), RestoredMode == ETripartiteBehaviorMode::ContemplativeSilence);
		TestTrue(TEXT("Restored silence contract is true"), bRestoredSilence);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
