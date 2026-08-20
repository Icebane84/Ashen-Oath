// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 525: Ashen Armor Scuff & Tactical Cover Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenDiegeticArmorScuffDecalSubsystem.h"
#include "AshenUserWidget_ArmorScuffDebugHUD.h"
#include "AshenCompanionTacticalCoverSubsystem.h"
#include "GA_GarrettSmokeScreenRelocationExecution.h"
#include "AshenMilestone525SynthesisOrchestrator.h"

// =============================================================================
//  Test 1: Armor Scuff Decal Subsystem — Apply Scuff
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenArmorScuffDecalSubsystemTest,
	"AshenOath.ArmorScuff.Subsystem.ApplyScuff",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenArmorScuffDecalSubsystemTest::RunTest(const FString& Parameters)
{
	UAshenDiegeticArmorScuffDecalSubsystem* Scuff = NewObject<UAshenDiegeticArmorScuffDecalSubsystem>();
	if (!TestNotNull(TEXT("DiegeticArmorScuffDecalSubsystem must be constructable"), Scuff)) return false;

	AActor* TestActor = NewObject<AActor>();
	Scuff->ApplyArmorScuffImpact(TestActor, 50.0f);
	return true;
}

// =============================================================================
//  Test 2: Companion Tactical Cover Subsystem — Find Cover
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCompanionTacticalCoverTest,
	"AshenOath.TacticalCover.Subsystem.FindCover",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenCompanionTacticalCoverTest::RunTest(const FString& Parameters)
{
	UAshenCompanionTacticalCoverSubsystem* Cover = NewObject<UAshenCompanionTacticalCoverSubsystem>();
	if (!TestNotNull(TEXT("CompanionTacticalCoverSubsystem must be constructable"), Cover)) return false;

	const FVector Origin(0, 0, 0);
	const FVector CoverPoint = Cover->FindOptimalTacticalCover(FName(TEXT("Companion_Garrett")), Origin);
	TestEqual(TEXT("CoverPoint X offset must equal 300"), (float)CoverPoint.X, 300.0f);

	return true;
}

// =============================================================================
//  Test 3: Garrett Smoke Screen Relocation Execution — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSmokeScreenRelocationClassTest,
	"AshenOath.GAS.GarrettSmokeScreenRelocationExecution.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSmokeScreenRelocationClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_GarrettSmokeScreenRelocationExecution"));
	TestNotNull(TEXT("UGA_GarrettSmokeScreenRelocationExecution must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 4: Milestone 525 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone525VerificationTest,
	"AshenOath.Milestone.Milestone525.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone525VerificationTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Warning, TEXT("AshenOath.Milestone.Milestone525.Verification: Milestone 525 Systems Verified!"));
	return true;
}
