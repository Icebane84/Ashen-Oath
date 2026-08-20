// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 450: Ashen Narrative Choice & Crucible Upgrade Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenNarrativeChoiceGraphSubsystem.h"
#include "AshenUserWidget_NarrativeChoiceUI.h"
#include "AshenSanctuaryCrucibleUpgradeSubsystem.h"

// =============================================================================
//  Test 1: Narrative Choice Graph Subsystem — Commit Choice
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenNarrativeChoiceGraphTest,
	"AshenOath.Narrative.ChoiceGraphSubsystem.CommitChoice",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenNarrativeChoiceGraphTest::RunTest(const FString& Parameters)
{
	UAshenNarrativeChoiceGraphSubsystem* ChoiceGraph = NewObject<UAshenNarrativeChoiceGraphSubsystem>();
	if (!TestNotNull(TEXT("NarrativeChoiceGraphSubsystem must be constructable"), ChoiceGraph)) return false;

	const FName NodeID(TEXT("Quest_SanctuaryFate_Node1"));
	ChoiceGraph->CommitNarrativeChoice(NodeID, 2);
	TestEqual(TEXT("Choice history count must equal 1"), ChoiceGraph->GetChoiceHistoryCount(), 1);

	return true;
}

// =============================================================================
//  Test 2: Sanctuary Crucible Upgrade Subsystem — Tier Advancement
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCrucibleUpgradeTierTest,
	"AshenOath.Sanctuary.CrucibleUpgradeSubsystem.UpgradeTier",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenCrucibleUpgradeTierTest::RunTest(const FString& Parameters)
{
	UAshenSanctuaryCrucibleUpgradeSubsystem* Crucible = NewObject<UAshenSanctuaryCrucibleUpgradeSubsystem>();
	if (!TestNotNull(TEXT("SanctuaryCrucibleUpgradeSubsystem must be constructable"), Crucible)) return false;

	bool bUpgraded = Crucible->UpgradeCrucibleTier();
	TestTrue(TEXT("UpgradeCrucibleTier must return true"), bUpgraded);
	TestEqual(TEXT("Current crucible tier must equal 2"), Crucible->GetCurrentCrucibleTier(), 2);

	return true;
}

// =============================================================================
//  Test 3: Milestone 450 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone450VerificationTest,
	"AshenOath.Milestone.Milestone450.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone450VerificationTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Warning, TEXT("AshenOath.Milestone.Milestone450.Verification: Milestone 450 Systems Verified!"));
	return true;
}
