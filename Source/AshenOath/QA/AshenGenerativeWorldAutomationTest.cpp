// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 440: Ashen Generative World & Non-Binary Morality Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenNonBinaryMoralitySubsystem.h"
#include "AshenGenerativeWorldStateComponent.h"
#include "GA_GarrettAssassinationExecution.h"

// =============================================================================
//  Test 1: Non-Binary Morality Subsystem — Record & Dominant Disposition
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenNonBinaryMoralitySubsystemTest,
	"AshenOath.Morality.NonBinaryMoralitySubsystem.RecordAndDominant",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenNonBinaryMoralitySubsystemTest::RunTest(const FString& Parameters)
{
	UAshenNonBinaryMoralitySubsystem* Morality = NewObject<UAshenNonBinaryMoralitySubsystem>();
	if (!TestNotNull(TEXT("NonBinaryMoralitySubsystem must be constructable"), Morality)) return false;

	Morality->RecordDispositionAction(EAshenMoralDisposition::Vengeful, 25.0f);
	TestEqual(TEXT("Dominant disposition must equal Vengeful"), Morality->GetDominantDisposition(), EAshenMoralDisposition::Vengeful);

	return true;
}

// =============================================================================
//  Test 2: Generative World State Component — Update Tension & Dissonance
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenGenerativeWorldStateTest,
	"AshenOath.GenerativeWorld.Component.UpdateTension",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenGenerativeWorldStateTest::RunTest(const FString& Parameters)
{
	UAshenGenerativeWorldStateComponent* GenWorld = NewObject<UAshenGenerativeWorldStateComponent>();
	if (!TestNotNull(TEXT("GenerativeWorldStateComponent must be constructable"), GenWorld)) return false;

	FAshenSoulStateVector SoulVec;
	SoulVec.CorruptionLevel = 40.0f;
	SoulVec.IntegrationDebt = 40.0f;
	SoulVec.Sanity = 50.0f;

	GenWorld->UpdateGenerativeWorldState(SoulVec);
	TestEqual(TEXT("CalculatedWeatherTension must equal 40.0"), GenWorld->CalculatedWeatherTension, 40.0f);

	return true;
}

// =============================================================================
//  Test 3: Garrett Assassination Execution — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenGarrettAssassinationClassTest,
	"AshenOath.GAS.GarrettAssassinationExecution.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenGarrettAssassinationClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_GarrettAssassinationExecution"));
	TestNotNull(TEXT("UGA_GarrettAssassinationExecution must be registered in UObject system"), AbilityClass);
	return true;
}


