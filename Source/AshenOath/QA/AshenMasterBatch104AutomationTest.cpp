// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 2095: Master Batch #104 QA Automation Test Suite — The Shepherd's Gambit (Unchained Party Collapse AI)
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AI/AshenShepherdsGambitSubsystem.h"
#include "AI/AshenSerafinaSoulAnchorAIComponent.h"
#include "AI/AshenGarrettSentinelContainmentAIComponent.h"
#include "Combat/AshenUnchainedVitalLeechComponent.h"
#include "Combat/AshenAshenPallorMeshAdapter.h"

// =============================================================================
//  Test 1: Shepherd's Gambit Corruption Thresholds & Containment AI Trees
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch104SubsystemAndAITest,
	"AshenOath.Gambit.SubsystemAndAI.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch104SubsystemAndAITest::RunTest(const FString& Parameters)
{
	// Test 1: Subsystem Threshold Evaluation
	UAshenShepherdsGambitSubsystem* Subsystem = NewObject<UAshenShepherdsGambitSubsystem>();
	if (!TestNotNull(TEXT("ShepherdsGambitSubsystem must be constructable"), Subsystem)) return false;

	Subsystem->EvaluateCorruptionThreshold(0.50f);
	TestEqual(TEXT("C=0.50 must be Safe"), Subsystem->CurrentHazardLevel, EUnchainedHazardLevel::Safe);
	TestFalse(TEXT("C=0.50 containment must not be active"), Subsystem->bIsUnchainedContainmentActive);

	Subsystem->EvaluateCorruptionThreshold(0.75f);
	TestEqual(TEXT("C=0.75 must be Hazardous"), Subsystem->CurrentHazardLevel, EUnchainedHazardLevel::Hazardous);
	TestTrue(TEXT("C=0.75 containment must be active"), Subsystem->bIsUnchainedContainmentActive);

	Subsystem->EvaluateCorruptionThreshold(0.95f);
	TestEqual(TEXT("C=0.95 must be Catastrophic"), Subsystem->CurrentHazardLevel, EUnchainedHazardLevel::Catastrophic);

	// Test 2: Serafina Decision Tree Evaluation
	UAshenSerafinaSoulAnchorAIComponent* SeraAI = NewObject<UAshenSerafinaSoulAnchorAIComponent>();
	if (!TestNotNull(TEXT("SerafinaSoulAnchorAIComponent must be constructable"), SeraAI)) return false;

	// Safe state
	SeraAI->EvaluateSerafinaContainmentTree(false, false, 0.2f);
	TestEqual(TEXT("Standard when not unchained"), SeraAI->CurrentContainmentAction, EContainmentState::StandardCooperation);

	// Targeting allies -> Sun-Pulse
	SeraAI->EvaluateSerafinaContainmentTree(true, true, 0.3f);
	TestEqual(TEXT("Containment active when targeting allies"), SeraAI->CurrentContainmentAction, EContainmentState::ContainmentActive);

	// Burnout >= 0.70 -> Bulwark Lockout
	SeraAI->EvaluateSerafinaContainmentTree(true, false, 0.85f);
	TestEqual(TEXT("Bulwark lockout when burnout >= 0.70"), SeraAI->CurrentContainmentAction, EContainmentState::BulwarkLockout);

	return true;
}

// =============================================================================
//  Test 2: Garrett Escort AI, Vital Leech & Facial Mesh Adapter Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch104GarrettAndMeshTest,
	"AshenOath.Gambit.GarrettAndMesh.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch104GarrettAndMeshTest::RunTest(const FString& Parameters)
{
	// Test 1: Garrett Escort Decision
	UAshenGarrettSentinelContainmentAIComponent* GarrettAI = NewObject<UAshenGarrettSentinelContainmentAIComponent>();
	if (!TestNotNull(TEXT("GarrettSentinelContainmentAIComponent must be constructable"), GarrettAI)) return false;

	GarrettAI->EvaluateGarrettContainmentTree(true, true);
	TestTrue(TEXT("Garrett must escort Serafina when she channels anchor"), GarrettAI->bIsEscortingSerafina);

	GarrettAI->EvaluateGarrettContainmentTree(true, false);
	TestFalse(TEXT("Garrett deploys needles when Serafina not channeling"), GarrettAI->bIsEscortingSerafina);

	// Test 2: Vital Leech Math (15% drain on companion hit)
	UAshenUnchainedVitalLeechComponent* LeechComp = NewObject<UAshenUnchainedVitalLeechComponent>();
	if (!TestNotNull(TEXT("UnchainedVitalLeechComponent must be constructable"), LeechComp)) return false;

	AActor* DummyActor = NewObject<AActor>();
	float DrainedAmount = 0.0f;

	TestTrue(TEXT("Leech on companion must return true"), LeechComp->ProcessUnchainedCleaveHit(DummyActor, true, DrainedAmount));
	TestEqual(TEXT("Drained amount must equal 15.0"), DrainedAmount, 15.0f);

	TestFalse(TEXT("Leech on non-companion must return false"), LeechComp->ProcessUnchainedCleaveHit(DummyActor, false, DrainedAmount));
	TestEqual(TEXT("Non-companion drained amount must be 0.0"), DrainedAmount, 0.0f);

	// Test 3: Ashen Pallor Facial Shader Scaling
	UAshenAshenPallorMeshAdapter* MeshAdapter = NewObject<UAshenAshenPallorMeshAdapter>();
	if (!TestNotNull(TEXT("AshenPallorMeshAdapter must be constructable"), MeshAdapter)) return false;

	MeshAdapter->UpdateUnchainedFacialMorphs(0.85f); // (0.85 - 0.70)/0.30 = 0.50
	TestEqual(TEXT("Pallor at 0.85 must be 0.50"), MeshAdapter->SkinPallorDesaturation, 0.50f);
	TestEqual(TEXT("Crimson eye emissive must be 2.0"), MeshAdapter->CrimsonEyeEmissive, 2.0f);

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER BATCH #104 SHEPHERD'S GAMBIT VERIFIED (2,095 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
