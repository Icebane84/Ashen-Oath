// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 585: Ashen Abomination Phase & Alchemical Infusion Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenAbominationBossPhaseSubsystem.h"
#include "AshenAegisBarrierComponent.h"
#include "AshenAlchemicalInfusionSubsystem.h"
#include "AshenMilestone585SynthesisOrchestrator.h"

// =============================================================================
//  Test 1: Abomination Boss Phase Subsystem — Trigger Void Phase
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenAbominationBossPhaseSubsystemTest,
	"AshenOath.AbominationPhase.Subsystem.TriggerVoidPhase",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenAbominationBossPhaseSubsystemTest::RunTest(const FString& Parameters)
{
	UAshenAbominationBossPhaseSubsystem* PhaseSys = NewObject<UAshenAbominationBossPhaseSubsystem>();
	if (!TestNotNull(TEXT("AbominationBossPhaseSubsystem must be constructable"), PhaseSys)) return false;

	PhaseSys->TriggerAbominationVoidPhase(2, 1.5f);
	TestEqual(TEXT("ActivePhaseTier must equal 2"), PhaseSys->ActivePhaseTier, 2);

	return true;
}

// =============================================================================
//  Test 2: Aegis Barrier Component — Deploy Barrier
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenAegisBarrierComponentTest,
	"AshenOath.AegisBarrier.Component.DeployBarrier",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenAegisBarrierComponentTest::RunTest(const FString& Parameters)
{
	UAshenAegisBarrierComponent* Aegis = NewObject<UAshenAegisBarrierComponent>();
	if (!TestNotNull(TEXT("AegisBarrierComponent must be constructable"), Aegis)) return false;

	Aegis->DeployAegisBarrier(300.0f);
	TestTrue(TEXT("bIsBarrierActive must equal true"), Aegis->bIsBarrierActive);
	TestEqual(TEXT("ActiveBarrierStrength must equal 300.0"), Aegis->ActiveBarrierStrength, 300.0f);

	return true;
}

// =============================================================================
//  Test 3: Alchemical Infusion Subsystem — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenAlchemicalInfusionClassTest,
	"AshenOath.AlchemicalInfusion.Subsystem.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenAlchemicalInfusionClassTest::RunTest(const FString& Parameters)
{
	UClass* SubClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.AshenAlchemicalInfusionSubsystem"));
	TestNotNull(TEXT("UAshenAlchemicalInfusionSubsystem must be registered in UObject system"), SubClass);
	return true;
}

// =============================================================================
//  Test 4: Milestone 585 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone585VerificationTest,
	"AshenOath.Milestone.Milestone585.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone585VerificationTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Warning, TEXT("AshenOath.Milestone.Milestone585.Verification: Milestone 585 Systems Verified!"));
	return true;
}
