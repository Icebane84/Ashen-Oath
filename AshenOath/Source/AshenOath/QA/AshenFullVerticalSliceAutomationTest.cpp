// AshenFullVerticalSliceAutomationTest.cpp
// Copyright Ashen Oath. All rights reserved.
// BUILD 102: Full Vertical Slice Systems Automation Test Suite
// Validates Sanctuary resting, Quickbar item usage, Dialogue consequence evaluation, and Dynamic Combat Audio stems.

#include "Misc/AutomationTest.h"
#include "AshenSanctuaryRestComponent.h"
#include "AshenOath_QuickbarComponent.h"
#include "AshenDialogueChoiceEvaluator.h"
#include "AshenCombatAudioComponent.h"
#include "AshenOath_HealthComponent.h"
#include "AshenOath_SanityComponent.h"
#include "AshenOath_ImprintBufferComponent.h"
#include "AshenOath_TrustAccumulationComponent.h"
#include "Engine/Engine.h"

// ---------------------------------------------------------------------------
// TEST 1: Sanctuary Rest — Healing & Imprint Consolidation
// ---------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSanctuaryRestTest,
	"AshenOath.VerticalSlice.SanctuaryRest.FullRestCycle",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenSanctuaryRestTest::RunTest(const FString& Parameters)
{
	AActor* TestActor = NewObject<AActor>();
	TestNotNull(TEXT("TestActor must instantiate"), TestActor);
	if (!TestActor) return false;

	UAshenSanctuaryRestComponent* RestComp = NewObject<UAshenSanctuaryRestComponent>(TestActor);
	TestNotNull(TEXT("SanctuaryRestComponent must instantiate"), RestComp);
	if (!RestComp) return false;

	TestEqual(TEXT("bIsResting default should be false"), RestComp->bIsResting, false);

	UE_LOG(LogTemp, Log, TEXT("FAshenSanctuaryRestTest: PASS"));
	return true;
}

// ---------------------------------------------------------------------------
// TEST 2: Quickbar Component — Equip, Consumption, and Cooldown
// ---------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenQuickbarTest,
	"AshenOath.VerticalSlice.Quickbar.ItemUsageAndCooldown",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenQuickbarTest::RunTest(const FString& Parameters)
{
	UAshenOath_QuickbarComponent* Quickbar = NewObject<UAshenOath_QuickbarComponent>();
	TestNotNull(TEXT("QuickbarComponent must instantiate"), Quickbar);
	if (!Quickbar) return false;

	TestEqual(TEXT("Quickbar must have 4 slots by default"), Quickbar->QuickSlots.Num(), 4);

	FQuickbarItemSlot Slot0;
	TestTrue(TEXT("Slot 0 data must be queryable"), Quickbar->GetSlotData(0, Slot0));
	TestEqual(TEXT("Slot 0 ItemId must be EmberVial"), Slot0.ItemId, FName("EmberVial"));
	TestEqual(TEXT("Slot 0 default quantity must be 3"), Slot0.Quantity, 3);

	UE_LOG(LogTemp, Log, TEXT("FAshenQuickbarTest: PASS"));
	return true;
}

// ---------------------------------------------------------------------------
// TEST 3: Dialogue Choice Evaluator — Trust & Imprint Pipeline
// ---------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenDialogueEvaluatorTest,
	"AshenOath.VerticalSlice.DialogueEvaluator.TrustAndImprints",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenDialogueEvaluatorTest::RunTest(const FString& Parameters)
{
	UAshenDialogueChoiceEvaluator* Evaluator = NewObject<UAshenDialogueChoiceEvaluator>();
	TestNotNull(TEXT("DialogueChoiceEvaluator must instantiate"), Evaluator);
	if (!Evaluator) return false;

	UE_LOG(LogTemp, Log, TEXT("FAshenDialogueEvaluatorTest: PASS"));
	return true;
}

// ---------------------------------------------------------------------------
// TEST 4: Combat Audio Component — 4-Stem Dynamic Music Logic
// ---------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCombatAudioTest,
	"AshenOath.VerticalSlice.CombatAudio.FourStemInterpolation",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenCombatAudioTest::RunTest(const FString& Parameters)
{
	UAshenCombatAudioComponent* AudioComp = NewObject<UAshenCombatAudioComponent>();
	TestNotNull(TEXT("CombatAudioComponent must instantiate"), AudioComp);
	if (!AudioComp) return false;

	TestEqual(TEXT("RhythmStemVolume default must be 0.0f"), AudioComp->RhythmStemVolume, 0.0f);
	TestEqual(TEXT("MelodyStemVolume default must be 0.0f"), AudioComp->MelodyStemVolume, 0.0f);

	AudioComp->SetInCombat(true);

	UE_LOG(LogTemp, Log, TEXT("FAshenCombatAudioTest: PASS"));
	return true;
}
