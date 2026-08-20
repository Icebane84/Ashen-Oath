// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1710: Character Finisher GAS Core Systems QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1710SynthesisOrchestrator.h"
#include "Companions/GA_GarrettSentinelsEclipse.h"
#include "Companions/AshenGarrettAssassinationExecution.h"
#include "Combat/GA_SerafinaEmpathicConduitNova.h"
#include "Combat/GA_KaelenEmpathicNovaThrust.h"
#include "Combat/AshenFinisherMotionWarpComponent.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1710CharacterFinisherAutomationTest,
	"AshenOath.QA.CharacterFinisherGAS.Milestone1710Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1710CharacterFinisherAutomationTest::RunTest(const FString& Parameters)
{
	// Test 1: Garrett Sentinel's Eclipse Ability
	UGA_GarrettSentinelsEclipse* EclipseAbility = NewObject<UGA_GarrettSentinelsEclipse>();
	if (!TestNotNull(TEXT("GA_GarrettSentinelsEclipse must be constructable"), EclipseAbility)) return false;
	TestEqual(TEXT("FlankingDamageMultiplier must equal 2.5f"), EclipseAbility->FlankingDamageMultiplier, 2.5f);

	// Test 2: Garrett Assassination Execution
	UAshenGarrettAssassinationExecution* AssassinationAbility = NewObject<UAshenGarrettAssassinationExecution>();
	if (!TestNotNull(TEXT("AshenGarrettAssassinationExecution must be constructable"), AssassinationAbility)) return false;
	TestEqual(TEXT("ArmorShredDamage must equal 350.0f"), AssassinationAbility->ArmorShredDamage, 350.0f);

	// Test 3: Serafina Conduit Nova
	UGA_SerafinaEmpathicConduitNova* NovaAbility = NewObject<UGA_SerafinaEmpathicConduitNova>();
	if (!TestNotNull(TEXT("GA_SerafinaEmpathicConduitNova must be constructable"), NovaAbility)) return false;
	TestEqual(TEXT("BaseNovaDamage must equal 750.0f"), NovaAbility->BaseNovaDamage, 750.0f);

	// Test 4: Kaelen Nova Thrust
	UGA_KaelenEmpathicNovaThrust* ThrustAbility = NewObject<UGA_KaelenEmpathicNovaThrust>();
	if (!TestNotNull(TEXT("GA_KaelenEmpathicNovaThrust must be constructable"), ThrustAbility)) return false;
	TestEqual(TEXT("KaelenHandSocketName must equal hand_l"), ThrustAbility->KaelenHandSocketName, FName(TEXT("hand_l")));

	// Test 5: Motion Warp Component
	UAshenFinisherMotionWarpComponent* WarpComp = NewObject<UAshenFinisherMotionWarpComponent>();
	if (!TestNotNull(TEXT("FinisherMotionWarpComponent must be constructable"), WarpComp)) return false;

	UAshenMilestone1710SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1710SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1710 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1710 validation must return true"), Orchestrator->ValidateMilestone1710Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1710 CHARACTER FINISHER GAS SUITE VERIFIED ======"));
	return true;
}
