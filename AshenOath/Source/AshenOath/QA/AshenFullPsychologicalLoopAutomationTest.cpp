// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 432: Ashen Full Psychological Runtime Closed-Loop Automation Test

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenFullPsychologicalLoopOrchestratorComponent.h"
#include "AshenSoulStateVectorComponent.h"
#include "AshenOath_HealthComponent.h"

// =============================================================================
//  Test 1: Full Closed-Loop Execution Across All 7 Stages
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenFullPsychologicalLoopExecutionTest,
	"AshenOath.PsychologicalLoop.Orchestrator.ExecuteAllStages",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenFullPsychologicalLoopExecutionTest::RunTest(const FString& Parameters)
{
	AActor* PlayerActor = NewObject<AActor>();
	if (!TestNotNull(TEXT("PlayerActor must be constructable"), PlayerActor)) return false;

	UAshenSoulStateVectorComponent* SoulState = NewObject<UAshenSoulStateVectorComponent>(PlayerActor);
	SoulState->RegisterComponent();

	UAshenFullPsychologicalLoopOrchestratorComponent* LoopOrchestrator = NewObject<UAshenFullPsychologicalLoopOrchestratorComponent>(PlayerActor);
	LoopOrchestrator->RegisterComponent();

	AActor* EnemyActor = NewObject<AActor>();
	UAshenOath_HealthComponent* EnemyHealth = NewObject<UAshenOath_HealthComponent>(EnemyActor);
	EnemyHealth->RegisterComponent();

	bool bLoopSuccess = LoopOrchestrator->ExecuteFullPsychologicalLoop(EnemyActor);
	TestTrue(TEXT("ExecuteFullPsychologicalLoop must return true for complete 7-stage execution"), bLoopSuccess);
	TestEqual(TEXT("CompletedStageMask must equal 0x7F (All 7 bits set)"), LoopOrchestrator->CompletedStageMask, 0x7F);

	return true;
}
