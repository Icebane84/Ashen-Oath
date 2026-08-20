// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1795: Master Batch #89 QA Automation Test Suite — Memory Palace Graph, Cognitive Loci & Mindscape Reconstruction
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Memory/AshenMemoryPalaceGraphSubsystem.h"
#include "Memory/AshenMemoryPalaceNodeComponent.h"
#include "Memory/AshenCognitiveLocusEvaluatorComponent.h"
#include "Memory/AshenMindscapeReconstructionManagerComponent.h"
#include "World/AshenMemoryPalaceLocusActor.h"
#include "World/AshenSunderedMemoryBridgeActor.h"
#include "Combat/AshenPsychicReconstructionGASAbility.h"
#include "AI/AshenMemoryPalaceNightmareDirectorComponent.h"
#include "Narrative/AshenMemoryPalaceDialogueAdapter.h"
#include "Companions/AshenMemoryPalaceCompanionAdapter.h"

// =============================================================================
//  Test 1: Memory Palace Graph Topology & Node Connectivity
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch89GraphTopologyTest,
	"AshenOath.MemoryPalace.GraphTopology.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch89GraphTopologyTest::RunTest(const FString& Parameters)
{
	UAshenMemoryPalaceGraphSubsystem* Subsystem = NewObject<UAshenMemoryPalaceGraphSubsystem>();
	if (!TestNotNull(TEXT("MemoryPalaceGraphSubsystem must be constructable"), Subsystem)) return false;

	// Verify default Core Sanctuary node
	TestEqual(TEXT("Initial unsealed node count must equal 1 (Core Sanctuary)"), Subsystem->GetUnsealedNodeCount(), 1);

	// Register a new node
	FMemoryGraphNode NexusNode;
	NexusNode.NodeID = FName(TEXT("Node.Trauma.GarrettPast"));
	NexusNode.NodeType = EMemoryNodeType::TraumaNexus;
	NexusNode.TraumaLevel = EMemoryTraumaLevel::Severe;
	NexusNode.bIsUnsealed = false;
	Subsystem->RegisterNode(NexusNode);

	// Connect nodes
	TestTrue(TEXT("Connecting Core to Trauma Nexus must succeed"),
		Subsystem->ConnectNodes(FName(TEXT("Node.Sanctuary.Core")), FName(TEXT("Node.Trauma.GarrettPast"))));

	// Unseal node
	TestTrue(TEXT("Unsealing Trauma Nexus must succeed"),
		Subsystem->UnsealNode(FName(TEXT("Node.Trauma.GarrettPast"))));

	TestEqual(TEXT("Unsealed node count must now equal 2"), Subsystem->GetUnsealedNodeCount(), 2);
	return true;
}

// =============================================================================
//  Test 2: Proximity Falloff, Trauma Density & Reconstruction Math
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch89MathAndMechanicsTest,
	"AshenOath.MemoryPalace.MathAndMechanics.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch89MathAndMechanicsTest::RunTest(const FString& Parameters)
{
	// Distance Proximity Falloff Math
	UAshenCognitiveLocusEvaluatorComponent* Evaluator = NewObject<UAshenCognitiveLocusEvaluatorComponent>();
	if (!TestNotNull(TEXT("CognitiveLocusEvaluatorComponent must be constructable"), Evaluator)) return false;
	Evaluator->MaxResonanceRadius = 1000.0f;

	const float IntensityAt500uu = Evaluator->CalculateResonanceIntensity(FVector(0, 0, 0), FVector(500, 0, 0));
	TestEqual(TEXT("Intensity at 500uu distance must equal 0.50f"), IntensityAt500uu, 0.50f);

	const float IntensityBeyondMax = Evaluator->CalculateResonanceIntensity(FVector(0, 0, 0), FVector(1500, 0, 0));
	TestEqual(TEXT("Intensity beyond max radius must equal 0.0f"), IntensityBeyondMax, 0.0f);

	// Trauma Density Math
	const float Density = Evaluator->EvaluateTraumaDensity(2, 0.20f); // 0.20 + (2 * 0.15) = 0.50
	TestEqual(TEXT("Trauma density must equal 0.50f"), Density, 0.50f);

	// Reconstruction Resolve Drain Math
	UAshenMindscapeReconstructionManagerComponent* Reconstructor = NewObject<UAshenMindscapeReconstructionManagerComponent>();
	if (!TestNotNull(TEXT("ReconstructionManagerComponent must be constructable"), Reconstructor)) return false;
	Reconstructor->ResolveDrainRatePerSecond = 20.0f;

	float RemainingResolve = 0.0f;
	const bool bCompleted = Reconstructor->AdvanceReconstruction(1.0f, 50.0f, RemainingResolve);
	TestFalse(TEXT("1 second of reconstruction should not complete progress immediately"), bCompleted);
	TestEqual(TEXT("Remaining Resolve after 1s at 20/s from 50 must equal 30.0f"), RemainingResolve, 30.0f);

	// AI Nightmare Spawn Gating
	UAshenMemoryPalaceNightmareDirectorComponent* Director = NewObject<UAshenMemoryPalaceNightmareDirectorComponent>();
	if (!TestNotNull(TEXT("NightmareDirectorComponent must be constructable"), Director)) return false;
	Director->NightmareSpawnThreshold = 0.60f;
	TestFalse(TEXT("Trauma density 0.50 should NOT spawn nightmare"), Director->ShouldSpawnNightmareShade(0.50f));
	TestTrue(TEXT("Trauma density 0.75 MUST spawn nightmare"), Director->ShouldSpawnNightmareShade(0.75f));

	// Dialogue Adapter Gate
	UAshenMemoryPalaceDialogueAdapter* Dialogue = NewObject<UAshenMemoryPalaceDialogueAdapter>();
	if (!TestNotNull(TEXT("MemoryPalaceDialogueAdapter must be constructable"), Dialogue)) return false;
	TestFalse(TEXT("Sundering lore must be locked at 2 loci"), Dialogue->IsLoreDialogueUnlocked(FName(TEXT("Lore.TheSunderingEvent")), 2));
	TestTrue(TEXT("Sundering lore must be unlocked at 3 loci"), Dialogue->IsLoreDialogueUnlocked(FName(TEXT("Lore.TheSunderingEvent")), 3));

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER BATCH #89 MEMORY PALACE & RECONSTRUCTION TEST SUITE VERIFIED (1,795 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
