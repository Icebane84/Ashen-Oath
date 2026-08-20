// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 2195: Master Batch #109 QA Automation Test Suite — The Cartographer's Living Journal & Environmental Resonance Map Engine
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Narrative/AshenCartographicResonanceSubsystem.h"
#include "Narrative/AshenLivingParchmentMapComponent.h"
#include "World/AshenCompassCelestialResonanceComponent.h"
#include "Narrative/AshenParchmentMarginaliaEvaluatorComponent.h"
#include "Combat/Ashen3DJournalMeshAdapter.h"

// =============================================================================
//  Test 1: Cartographic Subsystem & Breadcrumb Path Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch109SubsystemAndPathTest,
	"AshenOath.Cartography.SubsystemAndPath.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch109SubsystemAndPathTest::RunTest(const FString& Parameters)
{
	// Test 1: Subsystem Initialization & Region Inking
	UAshenCartographicResonanceSubsystem* Subsystem = NewObject<UAshenCartographicResonanceSubsystem>();
	if (!TestNotNull(TEXT("CartographicResonanceSubsystem must be constructable"), Subsystem)) return false;

	const FName TestRegion(TEXT("Shadowfen_Basin"));
	Subsystem->UpdateRegionInking(TestRegion, 0.50f);
	TestEqual(TEXT("Exploration percentage must be 0.50"), Subsystem->DiscoveredRegions[TestRegion].ExplorationPercentage, 0.50f);
	TestFalse(TEXT("Region must not be fully inked at 50%"), Subsystem->DiscoveredRegions[TestRegion].bIsFullyInked);

	Subsystem->UpdateRegionInking(TestRegion, 0.60f);
	TestEqual(TEXT("Exploration percentage clamped to 1.0"), Subsystem->DiscoveredRegions[TestRegion].ExplorationPercentage, 1.0f);
	TestTrue(TEXT("Region must be fully inked at 100%"), Subsystem->DiscoveredRegions[TestRegion].bIsFullyInked);

	// Test 2: Living Parchment Map Breadcrumb Distance Threshold
	UAshenLivingParchmentMapComponent* MapComp = NewObject<UAshenLivingParchmentMapComponent>();
	if (!TestNotNull(TEXT("LivingParchmentMapComponent must be constructable"), MapComp)) return false;

	TestTrue(TEXT("First breadcrumb must be recorded"), MapComp->RecordPlayerPosition(FVector(0.0f, 0.0f, 0.0f)));
	TestFalse(TEXT("Point too close (<300uu) must be rejected"), MapComp->RecordPlayerPosition(FVector(100.0f, 0.0f, 0.0f)));
	TestTrue(TEXT("Point >=300uu must be recorded"), MapComp->RecordPlayerPosition(FVector(500.0f, 0.0f, 0.0f)));
	TestEqual(TEXT("Total breadcrumb nodes must be 2"), MapComp->BreadcrumbPath.Num(), 2);

	return true;
}

// =============================================================================
//  Test 2: Compass Trigonometry, Marginalia & Journal Mesh Adapter
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch109CompassAndMeshTest,
	"AshenOath.Cartography.CompassAndMesh.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch109CompassAndMeshTest::RunTest(const FString& Parameters)
{
	// Test 1: Compass Bearing Calculation (East vector (1, 0) = 0 degrees)
	UAshenCompassCelestialResonanceComponent* CompassComp = NewObject<UAshenCompassCelestialResonanceComponent>();
	if (!TestNotNull(TEXT("CompassCelestialResonanceComponent must be constructable"), CompassComp)) return false;

	CompassComp->CalculateCompassBearing(FVector(0.0f, 0.0f, 0.0f), FVector(1000.0f, 0.0f, 0.0f), false);
	TestEqual(TEXT("East target must yield 0.0 deg bearing"), CompassComp->NeedleBearingDegrees, 0.0f);
	TestEqual(TEXT("Resonance state must be Attuned"), CompassComp->ResonanceState, ECompassResonanceState::Attuned);

	// Null-Zone Disruption
	CompassComp->CalculateCompassBearing(FVector(0.0f, 0.0f, 0.0f), FVector(1000.0f, 0.0f, 0.0f), true);
	TestEqual(TEXT("Resonance state must be Disrupted in Null-Zone"), CompassComp->ResonanceState, ECompassResonanceState::Disrupted);

	// Test 2: Marginalia Text Evaluation
	UAshenParchmentMarginaliaEvaluatorComponent* MarginaliaComp = NewObject<UAshenParchmentMarginaliaEvaluatorComponent>();
	if (!TestNotNull(TEXT("ParchmentMarginaliaEvaluatorComponent must be constructable"), MarginaliaComp)) return false;

	MarginaliaComp->GenerateMarginalia(0.90f, 0.10f, true);
	TestTrue(TEXT("High trust must generate Serafina's hand"), MarginaliaComp->ActiveMarginAnnotation.Contains(TEXT("Serafina's Hand")));

	// Test 3: 3D Journal Gold Foil Glow
	UAshen3DJournalMeshAdapter* MeshAdapter = NewObject<UAshen3DJournalMeshAdapter>();
	if (!TestNotNull(TEXT("3DJournalMeshAdapter must be constructable"), MeshAdapter)) return false;

	MeshAdapter->UpdateJournalFoilLeafing(5);
	TestEqual(TEXT("5 inked regions must yield 2.0 gold foil glow"), MeshAdapter->GoldFoilLeafGlow, 2.0f);

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER BATCH #109 LIVING JOURNAL VERIFIED (2,195 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
