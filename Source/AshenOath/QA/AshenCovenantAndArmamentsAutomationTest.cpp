// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 345: Ashen Covenant of Whispers & Resonant Armaments Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenCovenantOfWhispersComponent.h"
#include "GA_KaelenEldrinsGambitAbility.h"
#include "AshenResonantArmamentsSubsystem.h"

// =============================================================================
//  Test 1: Covenant of Whispers — Form & Dissolve Pact
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCovenantPactTest,
	"AshenOath.Covenant.WhispersComponent.FormPact",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenCovenantPactTest::RunTest(const FString& Parameters)
{
	UAshenCovenantOfWhispersComponent* Covenant = NewObject<UAshenCovenantOfWhispersComponent>();
	if (!TestNotNull(TEXT("CovenantOfWhispersComponent must be constructable"), Covenant)) return false;

	const FName PactID(TEXT("Pact_EldrinDefiance"));
	bool bFormed = Covenant->FormCovenantPact(PactID, 1.25f);
	TestTrue(TEXT("FormCovenantPact must return true"), bFormed);

	return true;
}

// =============================================================================
//  Test 2: Kaelen Eldrin's Gambit — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenEldrinsGambitClassTest,
	"AshenOath.GAS.KaelenEldrinsGambit.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenEldrinsGambitClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_KaelenEldrinsGambitAbility"));
	TestNotNull(TEXT("UGA_KaelenEldrinsGambitAbility must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 3: Resonant Armaments Subsystem — Memory Imprint
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenResonantArmamentsImprintTest,
	"AshenOath.Armaments.ResonantSubsystem.ImprintMemory",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenResonantArmamentsImprintTest::RunTest(const FString& Parameters)
{
	UAshenResonantArmamentsSubsystem* Armaments = NewObject<UAshenResonantArmamentsSubsystem>();
	if (!TestNotNull(TEXT("ResonantArmamentsSubsystem must be constructable"), Armaments)) return false;

	const FName WeaponID(TEXT("Weapon_Oathbringer_Core"));
	const FName MemoryID(TEXT("Memory_FallOfAethelgard"));
	bool bImprinted = Armaments->ImprintMemoryOnArmament(WeaponID, MemoryID);
	TestTrue(TEXT("ImprintMemoryOnArmament must return true"), bImprinted);

	return true;
}
