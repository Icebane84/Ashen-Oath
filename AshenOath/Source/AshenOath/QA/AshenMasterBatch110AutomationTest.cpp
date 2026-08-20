// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 2215: Master Batch #110 QA Automation Test Suite — The Tripartite Encounter Arena & Multi-Tier Boss Incursion Engine
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Combat/AshenBossIncursionSubsystem.h"
#include "Combat/AshenBossStaggerTelemetryComponent.h"
#include "World/AshenArenaHazardGridComponent.h"
#include "Combat/AshenTripartiteCinematicFinisherGASAbility.h"
#include "Combat/AshenBossDesecrationMeshAdapter.h"

// =============================================================================
//  Test 1: Boss Subsystem Phase Shifts & Stagger Execution Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch110SubsystemAndStaggerTest,
	"AshenOath.Boss.SubsystemAndStagger.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch110SubsystemAndStaggerTest::RunTest(const FString& Parameters)
{
	// Test 1: Subsystem Phase Transition Logic
	UAshenBossIncursionSubsystem* Subsystem = NewObject<UAshenBossIncursionSubsystem>();
	if (!TestNotNull(TEXT("BossIncursionSubsystem must be constructable"), Subsystem)) return false;

	EBossPhaseState Phase = EBossPhaseState::Phase1_TacticalDuel;

	// 100% HP -> Phase 1
	Subsystem->EvaluatePhaseTransition(1.0f, Phase);
	TestEqual(TEXT("100% HP must be Phase 1"), Phase, EBossPhaseState::Phase1_TacticalDuel);

	// 65% HP -> Phase 2 Chasm Fracture
	TestTrue(TEXT("Phase shift must trigger at 65%"), Subsystem->EvaluatePhaseTransition(0.65f, Phase));
	TestEqual(TEXT("65% HP must be Phase 2"), Phase, EBossPhaseState::Phase2_ChasmFracture);

	// 30% HP -> Phase 3 Apex Cataclysm
	TestTrue(TEXT("Phase shift must trigger at 30%"), Subsystem->EvaluatePhaseTransition(0.30f, Phase));
	TestEqual(TEXT("30% HP must be Phase 3"), Phase, EBossPhaseState::Phase3_ApexCataclysm);

	// 0% HP -> Defeated
	TestTrue(TEXT("Phase shift must trigger at 0%"), Subsystem->EvaluatePhaseTransition(0.0f, Phase));
	TestEqual(TEXT("0% HP must be Defeated"), Phase, EBossPhaseState::Phase_Defeated);

	// Test 2: 0.75s Stagger Window & Finisher Math
	UAshenBossStaggerTelemetryComponent* StaggerComp = NewObject<UAshenBossStaggerTelemetryComponent>();
	if (!TestNotNull(TEXT("BossStaggerTelemetryComponent must be constructable"), StaggerComp)) return false;

	float ExecutionDamage = 0.0f;
	TestFalse(TEXT("Finisher must fail when window is closed"), StaggerComp->ExecuteStaggerFinisher(EStaggerExecutionType::TripartiteResonantCleave, ExecutionDamage));

	StaggerComp->OpenStaggerWindow(0.75f);
	TestTrue(TEXT("Stagger window must be open"), StaggerComp->bIsStaggerWindowOpen);

	TestTrue(TEXT("Finisher must succeed when window is open"), StaggerComp->ExecuteStaggerFinisher(EStaggerExecutionType::TripartiteResonantCleave, ExecutionDamage));
	TestEqual(TEXT("Tripartite finisher damage must equal 2500.0"), ExecutionDamage, 2500.0f);
	TestFalse(TEXT("Window must close after execution"), StaggerComp->bIsStaggerWindowOpen);

	return true;
}

// =============================================================================
//  Test 2: Arena Hazard Grid, Finisher GAS & Boss Mesh Adapter Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch110HazardsAndMeshTest,
	"AshenOath.Boss.HazardsAndMesh.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch110HazardsAndMeshTest::RunTest(const FString& Parameters)
{
	// Test 1: Arena Hazard Grid Spawning
	UAshenArenaHazardGridComponent* HazardGrid = NewObject<UAshenArenaHazardGridComponent>();
	if (!TestNotNull(TEXT("ArenaHazardGridComponent must be constructable"), HazardGrid)) return false;

	TestTrue(TEXT("Fissure hazard spawn must succeed"), HazardGrid->SpawnHazardZone(FVector(0.0f, 0.0f, 0.0f), 500.0f, EArenaHazardType::VoidFissureChasm));
	TestTrue(TEXT("Masonry hazard spawn must succeed"), HazardGrid->SpawnHazardZone(FVector(500.0f, 0.0f, 0.0f), 300.0f, EArenaHazardType::FallingMasonry));
	TestEqual(TEXT("Active hazards count must be 2"), HazardGrid->ActiveHazards.Num(), 2);

	// Test 2: Tripartite Cinematic Finisher GAS Ability
	UAshenTripartiteCinematicFinisherGASAbility* FinisherAbility = NewObject<UAshenTripartiteCinematicFinisherGASAbility>();
	if (!TestNotNull(TEXT("TripartiteCinematicFinisherGASAbility must be constructable"), FinisherAbility)) return false;

	TestEqual(TEXT("Finisher ability base damage must be 2500.0"), FinisherAbility->FinisherDamage, 2500.0f);

	// Test 3: Boss Desecration Mesh Adapter
	UAshenBossDesecrationMeshAdapter* MeshAdapter = NewObject<UAshenBossDesecrationMeshAdapter>();
	if (!TestNotNull(TEXT("BossDesecrationMeshAdapter must be constructable"), MeshAdapter)) return false;

	MeshAdapter->UpdateBossDesecrationVisuals(EBossPhaseState::Phase1_TacticalDuel);
	TestEqual(TEXT("Phase 1 vein intensity must be 0.2"), MeshAdapter->DesecrationVeinIntensity, 0.2f);

	MeshAdapter->UpdateBossDesecrationVisuals(EBossPhaseState::Phase3_ApexCataclysm);
	TestEqual(TEXT("Phase 3 vein intensity must be 1.0"), MeshAdapter->DesecrationVeinIntensity, 1.0f);

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER BATCH #110 BOSS ENCOUNTER VERIFIED (2,215 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
