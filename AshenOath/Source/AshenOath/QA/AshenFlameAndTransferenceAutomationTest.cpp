// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 560: Ashen Flame Blade, Burnout & Transference Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenPurifierFlameBladeComponent.h"
#include "AshenSerafinaBurnoutComponent.h"
#include "AshenSerafinaTransferenceComponent.h"

// =============================================================================
//  Test 1: Purifier Flame Blade Component — Ignition
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenFlameBladeComponentTest,
	"AshenOath.FlameBlade.Component.Ignition",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenFlameBladeComponentTest::RunTest(const FString& Parameters)
{
	UAshenPurifierFlameBladeComponent* Flame = NewObject<UAshenPurifierFlameBladeComponent>();
	if (!TestNotNull(TEXT("PurifierFlameBladeComponent must be constructable"), Flame)) return false;

	Flame->IgniteFlameBlade(10.0f);
	TestTrue(TEXT("bIsIgnited must equal true"), Flame->bIsIgnited);
	TestEqual(TEXT("CalculatedHolyMultiplier must equal 1.75"), Flame->CalculatedHolyMultiplier, 1.75f);

	return true;
}

// =============================================================================
//  Test 2: Serafina Burnout Component — Accumulation
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSerafinaBurnoutTest,
	"AshenOath.Burnout.Component.Accumulate",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSerafinaBurnoutTest::RunTest(const FString& Parameters)
{
	UAshenSerafinaBurnoutComponent* Burnout = NewObject<UAshenSerafinaBurnoutComponent>();
	if (!TestNotNull(TEXT("SerafinaBurnoutComponent must be constructable"), Burnout)) return false;

	Burnout->AccumulateEmpathicBurnout(80.0f);
	TestTrue(TEXT("bIsBurnedOut must equal true when burnout >= 75%"), Burnout->bIsBurnedOut);

	return true;
}

// =============================================================================
//  Test 3: Serafina Transference Component — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSerafinaTransferenceClassTest,
	"AshenOath.Transference.Component.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSerafinaTransferenceClassTest::RunTest(const FString& Parameters)
{
	UClass* TransClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.AshenSerafinaTransferenceComponent"));
	TestNotNull(TEXT("UAshenSerafinaTransferenceComponent must be registered in UObject system"), TransClass);
	return true;
}
