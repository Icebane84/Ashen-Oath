// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 745: Ashen Integrative Memory & Void Erosion Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenIntegrativeMemoryPassCompilerComponent.h"
#include "AshenHermeneuticFragmentationCalculator.h"
#include "AshenWhisperingVoidErosionVolume.h"

// =============================================================================
//  Test 1: Integrative Memory Pass Compiler Component — Execute Pass
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenIntegrativeMemoryPassCompilerComponentTest,
	"AshenOath.IntegrativeMemory.Component.ExecutePass",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenIntegrativeMemoryPassCompilerComponentTest::RunTest(const FString& Parameters)
{
	UAshenIntegrativeMemoryPassCompilerComponent* Comp = NewObject<UAshenIntegrativeMemoryPassCompilerComponent>();
	if (!TestNotNull(TEXT("IntegrativeMemoryPassCompilerComponent must be constructable"), Comp)) return false;

	Comp->ExecuteIntegrativeMemoryPass(10);
	TestEqual(TEXT("Integration clarity for 10 nodes must equal 85.0%"), Comp->IntegrationClarityPercent, 85.0f);

	return true;
}

// =============================================================================
//  Test 2: Hermeneutic Fragmentation Calculator — Calculate Fragmentation
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenHermeneuticFragmentationCalculatorTest,
	"AshenOath.HermeneuticFragmentation.Calculator.CalculateFragmentation",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenHermeneuticFragmentationCalculatorTest::RunTest(const FString& Parameters)
{
	UAshenHermeneuticFragmentationCalculator* Calc = NewObject<UAshenHermeneuticFragmentationCalculator>();
	if (!TestNotNull(TEXT("HermeneuticFragmentationCalculator must be constructable"), Calc)) return false;

	const float Frag = Calc->CalculateFragmentation(3.0f, 50.0f); // 36 + 20 = 56%
	TestEqual(TEXT("Calculated fragmentation must equal 56.0%"), Frag, 56.0f);

	return true;
}

// =============================================================================
//  Test 3: Whispering Void Erosion Volume — Apply Erosion
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenWhisperingVoidErosionVolumeTest,
	"AshenOath.VoidErosion.Volume.ApplyErosion",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenWhisperingVoidErosionVolumeTest::RunTest(const FString& Parameters)
{
	AAshenWhisperingVoidErosionVolume* Vol = NewObject<AAshenWhisperingVoidErosionVolume>();
	if (!TestNotNull(TEXT("WhisperingVoidErosionVolume must be constructable"), Vol)) return false;

	Vol->ApplyVoidErosionToActor(nullptr, 10.0f); // Null target safety test
	return true;
}
