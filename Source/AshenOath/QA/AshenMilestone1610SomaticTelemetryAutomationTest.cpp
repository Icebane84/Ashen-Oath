// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1610: Somatic Telemetry Core Systems QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1610SynthesisOrchestrator.h"
#include "Memory/AshenNarrativeWeaponHistorySubsystem.h"
#include "Combat/AshenOathbringerNarrativeComponent.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1610SomaticTelemetryAutomationTest,
	"AshenOath.QA.SomaticTelemetry.Milestone1610Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1610SomaticTelemetryAutomationTest::RunTest(const FString& Parameters)
{
	UAshenNarrativeWeaponHistorySubsystem* WeaponHistory = NewObject<UAshenNarrativeWeaponHistorySubsystem>();
	if (!TestNotNull(TEXT("NarrativeWeaponHistorySubsystem must be constructable"), WeaponHistory)) return false;

	for (int32 i = 0; i < 10; ++i)
	{
		WeaponHistory->RecordExecutionKill(FName(TEXT("Cultist")));
	}
	TestEqual(TEXT("TotalWeaponExecutions must equal 10"), WeaponHistory->TotalWeaponExecutions, 10);
	TestEqual(TEXT("InscribedRuneTiers must equal 1"), WeaponHistory->InscribedRuneTiers, 1);

	UAshenOathbringerNarrativeComponent* Oathbringer = NewObject<UAshenOathbringerNarrativeComponent>();
	if (!TestNotNull(TEXT("OathbringerNarrativeComponent must be constructable"), Oathbringer)) return false;

	const float DmgMult = Oathbringer->CalculateDamageBonusMultiplier(2);
	TestEqual(TEXT("Damage multiplier for 2 runes must equal 1.10f"), DmgMult, 1.10f);

	UAshenMilestone1610SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1610SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1610 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1610 validation must return true"), Orchestrator->ValidateMilestone1610Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1610 SOMATIC TELEMETRY SUITE VERIFIED ======"));
	return true;
}
