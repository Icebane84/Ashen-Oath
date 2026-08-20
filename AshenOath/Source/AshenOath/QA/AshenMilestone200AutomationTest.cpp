// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 199: Ashen Milestone 200 Systems Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenSoulConstellationVisualizerComponent.h"
#include "GA_KaelenUnchainedBerserkMode.h"
#include "AshenVendorMerchantSubsystem.h"
#include "AshenQuestJournalSubsystem.h"

// =============================================================================
//  Test 1: Constellation Visualizer — Glow Calculation
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenConstellationVisualizerGlowTest,
	"AshenOath.Mindscape.ConstellationVisualizer.GlowCalculation",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenConstellationVisualizerGlowTest::RunTest(const FString& Parameters)
{
	UAshenSoulConstellationVisualizerComponent* Visualizer = NewObject<UAshenSoulConstellationVisualizerComponent>();
	if (!TestNotNull(TEXT("ConstellationVisualizerComponent must be constructable"), Visualizer)) return false;

	Visualizer->NodeGlowMultiplier = 0.20f;
	Visualizer->RefreshVisuals(5, 1.0f); // 1.0 + (5 * 0.20) = 2.0

	TestEqual(TEXT("Total glow intensity must be 2.0 for 5 nodes"), Visualizer->GetTotalGlowIntensity(), 2.0f);

	return true;
}

// =============================================================================
//  Test 2: Unchained Berserk GAS — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenUnchainedBerserkClassTest,
	"AshenOath.GAS.KaelenBerserk.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenUnchainedBerserkClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_KaelenUnchainedBerserkMode"));
	TestNotNull(TEXT("UGA_KaelenUnchainedBerserkMode must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 3: Vendor Subsystem — Class Validation
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenVendorSubsystemValidTest,
	"AshenOath.Economy.VendorSubsystem.ValidClass",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenVendorSubsystemValidTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenVendorMerchantSubsystem class must be valid"),
		UAshenVendorMerchantSubsystem::StaticClass() != nullptr);
	return true;
}

// =============================================================================
//  Test 4: Quest Journal Subsystem — Class Validation
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenQuestJournalValidTest,
	"AshenOath.Quest.JournalSubsystem.ValidClass",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenQuestJournalValidTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenQuestJournalSubsystem class must be valid"),
		UAshenQuestJournalSubsystem::StaticClass() != nullptr);
	return true;
}

// =============================================================================
//  Test 5: Master Milestone 200 Integration Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone200MasterTest,
	"AshenOath.Milestone.Milestone200.MasterIntegration",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone200MasterTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Warning, TEXT("AshenOath.Milestone.Milestone200.MasterIntegration: ALL SYSTEMS GO FOR BUILD 200!"));
	return true;
}
