// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1250: Soul State Vector QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1250SynthesisOrchestrator.h"
#include "Soul/AshenSoulConstellationSubsystem.h"
#include "Soul/AshenBehavioralProfileCompiler.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenIdentityStateVectorAutomationTest,
	"AshenOath.QA.SoulStateVector.Milestone1250Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenIdentityStateVectorAutomationTest::RunTest(const FString& Parameters)
{
	// Verify BehavioralProfileCompiler produces correct profiles from known weights
	UAshenBehavioralProfileCompiler* Compiler = NewObject<UAshenBehavioralProfileCompiler>();
	if (!TestNotNull(TEXT("BehavioralProfileCompiler must be constructable"), Compiler)) return false;

	FAshenBehavioralProfile Profile = Compiler->CompileProfileFromWeights(0.80f, 0.80f, 0.80f);
	TestEqual(TEXT("High-weight stance must compile to Resolved_Protector"), Profile.StanceProfile, EAshenStanceProfile::Resolved_Protector);
	TestEqual(TEXT("High-weight empathic must compile to Open_Compassionate"), Profile.EmpathicProfile, EAshenEmpathicProfile::Open_Compassionate);
	TestEqual(TEXT("High-weight tactical must compile to Methodical_Calculated"), Profile.TacticalProfile, EAshenTacticalProfile::Methodical_Calculated);

	FAshenBehavioralProfile LowProfile = Compiler->CompileProfileFromWeights(0.10f, 0.10f, 0.10f);
	TestEqual(TEXT("Low-weight stance must compile to Fractured_Reactive"), LowProfile.StanceProfile, EAshenStanceProfile::Fractured_Reactive);

	// Verify Milestone 1250 orchestrator
	UAshenMilestone1250SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1250SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1250 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1250 validation must return true"), Orchestrator->ValidateMilestone1250Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1250 SOUL STATE VECTOR SUITE VERIFIED ======"));
	return true;
}

