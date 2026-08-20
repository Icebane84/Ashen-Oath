// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1550: Alchemical Ecology Core Systems QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1550SynthesisOrchestrator.h"
#include "Core/AshenAlchemicalLanternComponent.h"
#include "World/AshenRegionalCorruptionSpreadSubsystem.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1550AlchemicalEcologyAutomationTest,
	"AshenOath.QA.AlchemicalEcology.Milestone1550Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1550AlchemicalEcologyAutomationTest::RunTest(const FString& Parameters)
{
	UAshenAlchemicalLanternComponent* Lantern = NewObject<UAshenAlchemicalLanternComponent>();
	if (!TestNotNull(TEXT("LanternComponent must be constructable"), Lantern)) return false;

	Lantern->ToggleLantern(true);
	TestTrue(TEXT("Lantern lit state must be true"), Lantern->bIsLanternLit);

	Lantern->ConsumeFuel(10.0f);
	TestTrue(TEXT("Fuel must decrease after consumption"), Lantern->CurrentFuel < 100.0f);

	UAshenRegionalCorruptionSpreadSubsystem* CorruptionSys = NewObject<UAshenRegionalCorruptionSpreadSubsystem>();
	if (!TestNotNull(TEXT("RegionalCorruptionSubsystem must be constructable"), CorruptionSys)) return false;

	CorruptionSys->PropagateRegionalCorruption(3, 40.0f);
	TestEqual(TEXT("Sector 3 corruption must equal 40.0f"), CorruptionSys->GetSectorCorruption(3), 40.0f);

	UAshenMilestone1550SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1550SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1550 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1550 validation must return true"), Orchestrator->ValidateMilestone1550Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1550 ALCHEMICAL ECOLOGY SUITE VERIFIED ======"));
	return true;
}
