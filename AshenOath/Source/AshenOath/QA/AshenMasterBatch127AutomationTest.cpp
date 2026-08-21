// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Scenarios/AshenScenario1CauterizedHeartTypes.h"
#include "Scenarios/AshenScenario1MissionSubsystem.h"
#include "Scenarios/AshenMalakorEncounterComponent.h"
#include "Scenarios/AshenReluctantKnifeEvaluatorComponent.h"
#include "Scenarios/AshenRitualClarityOfHeartSubsystem.h"
#include "Scenarios/AshenShadowVeinMaterialModulatorComponent.h"
#include "Scenarios/AshenScenario1HapticBridge.h"
#include "Core/AshenScenario1SaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch127AutomationTest,
	"AshenOath.Scenarios.MasterBatch127_Scenario1CauterizedHeart",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch127AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST MALAKOR BOSS PHASE EVALUATION & VOID SMASH DAMAGE
	// -----------------------------------------------------------------------------------
	{
		UAshenMalakorEncounterComponent* MalakorComp = NewObject<UAshenMalakorEncounterComponent>();

		// Health 1.0 -> Phase 1
		TestEqual(TEXT("Phase at 1.0 health is Phase 1"), MalakorComp->EvaluatePhase(1.0f), EMalakorBossPhase::Phase1_InquisitorSmash);

		// Health 0.50 -> Phase 2
		TestEqual(TEXT("Phase at 0.50 health is Phase 2"), MalakorComp->EvaluatePhase(0.50f), EMalakorBossPhase::Phase2_PuristZealot);

		// Health 0.20 -> Phase 3
		TestEqual(TEXT("Phase at 0.20 health is Phase 3"), MalakorComp->EvaluatePhase(0.20f), EMalakorBossPhase::Phase3_AbominationCascade);

		// Void Smash Scaling (Base 180)
		const float Phase1Dmg = MalakorComp->EvaluateVoidSmashDamage(EMalakorBossPhase::Phase1_InquisitorSmash, 180.0f);
		TestNearlyEqual(TEXT("Phase 1 smash damage is 180.0"), Phase1Dmg, 180.0f, 0.01f);

		const float Phase3Dmg = MalakorComp->EvaluateVoidSmashDamage(EMalakorBossPhase::Phase3_AbominationCascade, 180.0f);
		TestNearlyEqual(TEXT("Phase 3 smash damage is 396.0 (2.20x)"), Phase3Dmg, 396.0f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST RITUAL DISRUPTION & INTEGRATION DEBT SPIKE
	// -----------------------------------------------------------------------------------
	{
		UAshenRitualClarityOfHeartSubsystem* RitualSubsystem = NewObject<UAshenRitualClarityOfHeartSubsystem>();

		// Initial progress
		TestNearlyEqual(TEXT("Initial ritual progress is 0.0"), RitualSubsystem->GetRitualProgress(), 0.0f, 0.01f);

		// Advance 50%
		const bool bComplete = RitualSubsystem->AdvanceRitual(0.50f);
		TestFalse(TEXT("Ritual at 50% is not complete"), bComplete);
		TestNearlyEqual(TEXT("Ritual progress is 0.50"), RitualSubsystem->GetRitualProgress(), 0.50f, 0.01f);

		// Interruption at 50%: 0.15 + (0.50 * 0.30) = 0.30 debt spike
		const float SpikeAt50 = RitualSubsystem->EvaluateDebtSpikeOnInterruption(0.50f);
		TestNearlyEqual(TEXT("Debt spike at 50% is 0.30"), SpikeAt50, 0.30f, 0.01f);

		// Interruption near climax at 90%: 0.15 + (0.90 * 0.30) = 0.42 debt spike
		const float SpikeAt90 = RitualSubsystem->EvaluateDebtSpikeOnInterruption(0.90f);
		TestNearlyEqual(TEXT("Debt spike at 90% is 0.42"), SpikeAt90, 0.42f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST PRINCIPLE OF THE RELUCTANT KNIFE DIALOGUE
	// -----------------------------------------------------------------------------------
	{
		UAshenReluctantKnifeEvaluatorComponent* ReluctantKnife = NewObject<UAshenReluctantKnifeEvaluatorComponent>();

		// Battle just started
		const EReluctantKnifeEthos EarlyEthos = ReluctantKnife->EvaluateValeriusStance(10.0f, 0.0f);
		TestEqual(TEXT("Early battle ethos is ControlledMitigation"), EarlyEthos, EReluctantKnifeEthos::ControlledMitigation);

		// Prolonged battle with heavy ritual damage
		const EReluctantKnifeEthos LateEthos = ReluctantKnife->EvaluateValeriusStance(130.0f, 0.60f);
		TestEqual(TEXT("Late battle ethos is HardenedResignation"), LateEthos, EReluctantKnifeEthos::HardenedResignation);

		const FText Bark = ReluctantKnife->EvaluateValeriusDialogueBark(LateEthos);
		TestTrue(TEXT("Valerius hardened bark mentions vessel cracking"), Bark.ToString().Contains(TEXT("vessel cracks")));
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST DUALSENSE HAPTIC RESISTANCE SCALING
	// -----------------------------------------------------------------------------------
	{
		UAshenScenario1HapticBridge* HapticBridge = NewObject<UAshenScenario1HapticBridge>();

		const float RestTension = HapticBridge->EvaluateTitansStandTriggerResistance(false, EMalakorBossPhase::Phase1_InquisitorSmash);
		TestNearlyEqual(TEXT("Rest tension is 10.0"), RestTension, 10.0f, 0.01f);

		const float Phase1Parry = HapticBridge->EvaluateTitansStandTriggerResistance(true, EMalakorBossPhase::Phase1_InquisitorSmash);
		TestNearlyEqual(TEXT("Phase 1 parry resistance is 70.0"), Phase1Parry, 70.0f, 0.01f);

		const float Phase3Parry = HapticBridge->EvaluateTitansStandTriggerResistance(true, EMalakorBossPhase::Phase3_AbominationCascade);
		TestNearlyEqual(TEXT("Phase 3 parry resistance is 100.0 (Max hard stop)"), Phase3Parry, 100.0f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST SAVEGAME PERSISTENCE
	// -----------------------------------------------------------------------------------
	{
		UAshenScenario1SaveGameAdapter* SaveAdapter = NewObject<UAshenScenario1SaveGameAdapter>();

		SaveAdapter->PackageScenario1State(true, 0.40f, 0.65f);
		TestTrue(TEXT("HasSavedData is true"), SaveAdapter->HasSavedData());

		bool bCleared = false;
		float RestoredIso = 0.0f;
		float RestoredDebt = 0.0f;
		const bool bSuccess = SaveAdapter->RestoreScenario1State(bCleared, RestoredIso, RestoredDebt);

		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestTrue(TEXT("bCleared is true"), bCleared);
		TestNearlyEqual(TEXT("Restored isolation is 0.40"), RestoredIso, 0.40f, 0.01f);
		TestNearlyEqual(TEXT("Restored debt is 0.65"), RestoredDebt, 0.65f, 0.01f);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
