// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Narrative/AshenCSEQuestBoardTypes.h"
#include "Narrative/AshenCSESubsystem.h"
#include "Narrative/AshenDissonanceQuestBoardSubsystem.h"
#include "Narrative/AshenCognitiveDissonanceEvaluator.h"
#include "Combat/AshenCSEHapticBridge.h"
#include "Core/AshenCSESaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch151AutomationTest,
	"AshenOath.Narrative.MasterBatch151_CognitiveSynchronizationQuestBoard",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch151AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST COGNITIVE DISSONANCE EVALUATOR & SYNERGY BUFFS
	// -----------------------------------------------------------------------------------
	{
		UAshenCognitiveDissonanceEvaluator* Evaluator = NewObject<UAshenCognitiveDissonanceEvaluator>();

		// 0.0 Dissonance (Pure Harmony): +30% synergy damage, 1.0x stamina, 0.0s assist delay
		TestNearlyEqual(TEXT("Zero dissonance synergy damage bonus is +30%"), Evaluator->EvaluateSynergyDamageBonus(0.0f), 0.30f, 0.01f);
		TestNearlyEqual(TEXT("Zero dissonance tandem stamina multiplier is 1.0x"), Evaluator->EvaluateTandemStaminaMultiplier(0.0f), 1.00f, 0.01f);
		TestNearlyEqual(TEXT("Zero dissonance assist delay is 0.0s"), Evaluator->EvaluateCompanionAssistDelaySeconds(0.0f), 0.0f, 0.01f);

		// 1.0 Dissonance (Max Fracture): 0.0% synergy bonus, 1.20x stamina penalty, 0.60s assist delay
		TestNearlyEqual(TEXT("Max dissonance synergy damage bonus is 0.0%"), Evaluator->EvaluateSynergyDamageBonus(1.0f), 0.0f, 0.01f);
		TestNearlyEqual(TEXT("Max dissonance tandem stamina multiplier is 1.20x"), Evaluator->EvaluateTandemStaminaMultiplier(1.0f), 1.20f, 0.01f);
		TestNearlyEqual(TEXT("Max dissonance assist delay is 0.60s"), Evaluator->EvaluateCompanionAssistDelaySeconds(1.0f), 0.60f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST QUEST BOARD CONTRACT GENERATION & RESOLUTION
	// -----------------------------------------------------------------------------------
	{
		UAshenDissonanceQuestBoardSubsystem* QuestBoard = NewObject<UAshenDissonanceQuestBoardSubsystem>();

		FDissonanceQuestContract Contract1;
		Contract1.ContractId = TEXT("Contract_SunkenArchive_01");
		Contract1.Title = FText::FromString(TEXT("The Sunken Archive Cover-Up"));
		Contract1.Category = EDissonanceQuestCategory::ContradictionTrial;
		Contract1.DissonanceThreshold = 0.50f;

		QuestBoard->RegisterQuestContract(Contract1);
		TestEqual(TEXT("Active contracts count is 1"), QuestBoard->GetActiveContracts().Num(), 1);

		// Resolve contract with Garrett's outcome
		const bool bResolved = QuestBoard->ResolveContract(TEXT("Contract_SunkenArchive_01"), EQuestResolutionOutcome::ResolvedGarrettPragmatic);
		TestTrue(TEXT("Contract resolved successfully"), bResolved);
		TestEqual(TEXT("Active contracts count is 0"), QuestBoard->GetActiveContracts().Num(), 0);
		TestEqual(TEXT("Resolved contracts count is 1"), QuestBoard->GetResolvedContractCount(), 1);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST DUALSENSE CSE HAPTICS
	// -----------------------------------------------------------------------------------
	{
		UAshenCSEHapticBridge* HapticBridge = NewObject<UAshenCSEHapticBridge>();
		float ConsensusPurr = 0.0f;
		float FrictionPulse = 0.0f;

		// Harmonic consensus (D = 0.10 < 0.25)
		HapticBridge->EvaluateCSEHaptics(0.10f, ConsensusPurr, FrictionPulse);
		TestNearlyEqual(TEXT("Harmonic consensus purr is 0.85"), ConsensusPurr, 0.85f, 0.01f);
		TestNearlyEqual(TEXT("Harmonic friction pulse is 0.0"), FrictionPulse, 0.0f, 0.01f);

		// Psychological fracture (D = 0.80 > 0.25)
		HapticBridge->EvaluateCSEHaptics(0.80f, ConsensusPurr, FrictionPulse);
		TestNearlyEqual(TEXT("Fracture consensus purr is 0.0"), ConsensusPurr, 0.0f, 0.01f);
		TestNearlyEqual(TEXT("Fracture friction pulse is 0.72"), FrictionPulse, 0.72f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST SAVEGAME PERSISTENCE
	// -----------------------------------------------------------------------------------
	{
		UAshenCSESaveGameAdapter* SaveAdapter = NewObject<UAshenCSESaveGameAdapter>();
		SaveAdapter->PackageCSEState(0.65f, ECognitiveDissonanceTier::IdeologicalDivergence, 3);
		TestTrue(TEXT("SaveData is true"), SaveAdapter->HasSavedData());

		float RestoredDissonance = 0.0f;
		ECognitiveDissonanceTier RestoredTier = ECognitiveDissonanceTier::HarmonicConsensus;
		int32 RestoredCount = 0;

		const bool bSuccess = SaveAdapter->RestoreCSEState(RestoredDissonance, RestoredTier, RestoredCount);
		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestNearlyEqual(TEXT("Restored dissonance is 0.65"), RestoredDissonance, 0.65f, 0.01f);
		TestTrue(TEXT("Restored tier is IdeologicalDivergence"), RestoredTier == ECognitiveDissonanceTier::IdeologicalDivergence);
		TestEqual(TEXT("Restored resolved count is 3"), RestoredCount, 3);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
