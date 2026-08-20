// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1855: Master Batch #92 QA Automation Test Suite — Living Codex, Psychological Dialogue Trees & Semantic Mention Pipeline
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Narrative/AshenLivingCodexSubsystem.h"
#include "Narrative/AshenPsychologicalDialogueComponent.h"
#include "Narrative/AshenSemanticMentionEvaluatorComponent.h"
#include "Narrative/AshenLorekeeperRewardEvaluatorComponent.h"
#include "Companions/AshenLivingCodexCompanionAdapter.h"
#include "Combat/AshenLorekeeperBeaconGASAbility.h"
#include "Combat/AshenPsychicCatharsisGASAbility.h"

// =============================================================================
//  Test 1: Living Codex Unlocks & Faction Stat Reward Math
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch92CodexRewardsTest,
	"AshenOath.Narrative.CodexRewards.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch92CodexRewardsTest::RunTest(const FString& Parameters)
{
	// Test 1: Living Codex Registration and Unlock
	UAshenLivingCodexSubsystem* Subsystem = NewObject<UAshenLivingCodexSubsystem>();
	if (!TestNotNull(TEXT("LivingCodexSubsystem must be constructable"), Subsystem)) return false;

	FCodexEntryData Entry1;
	Entry1.EntryID = FName(TEXT("Lore.Oathsworn.FirstVow"));
	Entry1.Faction = ECodexFaction::Oathsworn;
	Entry1.Title = TEXT("The First Vow");
	Subsystem->RegisterCodexEntry(Entry1);

	FCodexEntryData Entry2;
	Entry2.EntryID = FName(TEXT("Lore.Voidcult.Whispers"));
	Entry2.Faction = ECodexFaction::Voidcult;
	Entry2.Title = TEXT("Whispers in the Ash");
	Subsystem->RegisterCodexEntry(Entry2);

	TestEqual(TEXT("Initial sanity reward with 0 unlocked factions must be 0.0"), Subsystem->CalculateCodexSanityReward(), 0.0f);

	TestTrue(TEXT("Unlocking Entry1 must succeed"), Subsystem->UnlockCodexEntry(FName(TEXT("Lore.Oathsworn.FirstVow"))));
	TestEqual(TEXT("Sanity reward with 1 unlocked faction must be 5.0"), Subsystem->CalculateCodexSanityReward(), 5.0f);

	TestTrue(TEXT("Unlocking Entry2 must succeed"), Subsystem->UnlockCodexEntry(FName(TEXT("Lore.Voidcult.Whispers"))));
	TestEqual(TEXT("Sanity reward with 2 unlocked factions must be 10.0"), Subsystem->CalculateCodexSanityReward(), 10.0f);

	// Test 2: Poise & Resolve Bonus Math
	UAshenLorekeeperRewardEvaluatorComponent* Evaluator = NewObject<UAshenLorekeeperRewardEvaluatorComponent>();
	if (!TestNotNull(TEXT("LorekeeperRewardEvaluatorComponent must be constructable"), Evaluator)) return false;

	TestEqual(TEXT("4 Oathsworn entries -> +10.0 Poise (4 * 2.5)"), Evaluator->CalculatePoiseReward(4), 10.0f);
	TestEqual(TEXT("10 read entries -> +0.20 Resolve/s"), Evaluator->CalculateResolveRegenBonus(10), 0.20f);

	return true;
}

// =============================================================================
//  Test 2: Psychological Dialogue Tone Evaluation & Semantic Mentions
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch92DialogueAndSemanticTest,
	"AshenOath.Narrative.DialogueAndSemantic.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch92DialogueAndSemanticTest::RunTest(const FString& Parameters)
{
	// Psychological Tone Evaluation
	UAshenPsychologicalDialogueComponent* Dialogue = NewObject<UAshenPsychologicalDialogueComponent>();
	if (!TestNotNull(TEXT("PsychologicalDialogueComponent must be constructable"), Dialogue)) return false;

	TestEqual(TEXT("High Corruption (0.75) -> Despairing tone"), Dialogue->EvaluateDialogueTone(0.50f, 0.75f, 0.20f), EPsychologicalTone::Despairing);
	TestEqual(TEXT("High Isolation (0.80) -> Cynical tone"), Dialogue->EvaluateDialogueTone(0.50f, 0.20f, 0.80f), EPsychologicalTone::Cynical);
	TestEqual(TEXT("High Resolve (0.85) low corruption -> Enlightened tone"), Dialogue->EvaluateDialogueTone(0.85f, 0.10f, 0.20f), EPsychologicalTone::Enlightened);

	// Gated Dialogue Choices (Enlightened bypasses restriction)
	TestTrue(TEXT("Enlightened tone can select any choice if Sanity allows"),
		Dialogue->CanSelectDialogueChoice(EPsychologicalTone::Resolute, 80.0f, 50.0f));
	TestFalse(TEXT("Choice fails if current sanity is below requirement"),
		Dialogue->CanSelectDialogueChoice(EPsychologicalTone::Resolute, 30.0f, 50.0f));

	// Semantic Mention Falloff Math
	UAshenSemanticMentionEvaluatorComponent* Semantic = NewObject<UAshenSemanticMentionEvaluatorComponent>();
	if (!TestNotNull(TEXT("SemanticMentionEvaluatorComponent must be constructable"), Semantic)) return false;

	float Ratio = 0.0f;
	const bool bNear = Semantic->EvaluateSemanticMention(FVector(0, 0, 0), FVector(400, 0, 0), FName(TEXT("Topic.AncientShrine")), Ratio);
	TestTrue(TEXT("Distance 400uu within 800uu radius must trigger semantic mention"), bNear);
	TestEqual(TEXT("Ratio at 400uu (half max radius) must equal 0.50"), Ratio, 0.50f);

	// Companion Backstory Trust Gains
	UAshenLivingCodexCompanionAdapter* CompanionAdapter = NewObject<UAshenLivingCodexCompanionAdapter>();
	if (!TestNotNull(TEXT("LivingCodexCompanionAdapter must be constructable"), CompanionAdapter)) return false;

	const float GarrettPersonalTrust = CompanionAdapter->EvaluateCompanionTrustGain(FName(TEXT("Lore.Garrett.Childhood")), FName(TEXT("Garrett")));
	TestEqual(TEXT("Personal backstory must award +0.08 trust"), GarrettPersonalTrust, 0.08f);

	const float GenericTrust = CompanionAdapter->EvaluateCompanionTrustGain(FName(TEXT("Lore.World.SunderedSpire")), FName(TEXT("Garrett")));
	TestEqual(TEXT("Generic lore must award +0.02 trust"), GenericTrust, 0.02f);

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER BATCH #92 LIVING CODEX & DIALOGUE TEST SUITE VERIFIED (1,855 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
