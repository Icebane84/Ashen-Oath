// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 485: Ashen Enemy Family Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenEnemyFamilyBlightGhoulComponent.h"
#include "AshenEnemyFamilyAshWalkerComponent.h"
#include "GA_AshWalkerShieldBashExecution.h"

// =============================================================================
//  Test 1: Blight Ghoul Swarm Component — Flank Multiplier
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenBlightGhoulSwarmTest,
	"AshenOath.EnemyFamily.BlightGhoulComponent.UpdateSwarm",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenBlightGhoulSwarmTest::RunTest(const FString& Parameters)
{
	UAshenEnemyFamilyBlightGhoulComponent* Ghoul = NewObject<UAshenEnemyFamilyBlightGhoulComponent>();
	if (!TestNotNull(TEXT("EnemyFamilyBlightGhoulComponent must be constructable"), Ghoul)) return false;

	Ghoul->UpdateSwarmCoordination(4);
	TestEqual(TEXT("CalculatedFlankMultiplier must equal 1.6"), Ghoul->CalculatedFlankMultiplier, 1.6f);

	return true;
}

// =============================================================================
//  Test 2: Ash Walker Component — Hyper Armor Toggle
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenAshWalkerHyperArmorTest,
	"AshenOath.EnemyFamily.AshWalkerComponent.SetHyperArmor",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenAshWalkerHyperArmorTest::RunTest(const FString& Parameters)
{
	UAshenEnemyFamilyAshWalkerComponent* AshWalker = NewObject<UAshenEnemyFamilyAshWalkerComponent>();
	if (!TestNotNull(TEXT("EnemyFamilyAshWalkerComponent must be constructable"), AshWalker)) return false;

	AshWalker->SetHyperArmorState(true);
	TestTrue(TEXT("bIsHyperArmorActive must equal true"), AshWalker->bIsHyperArmorActive);

	return true;
}

// =============================================================================
//  Test 3: Ash Walker Shield Bash Execution — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenAshWalkerShieldBashClassTest,
	"AshenOath.GAS.AshWalkerShieldBashExecution.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenAshWalkerShieldBashClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_AshWalkerShieldBashExecution"));
	TestNotNull(TEXT("UGA_AshWalkerShieldBashExecution must be registered in UObject system"), AbilityClass);
	return true;
}
