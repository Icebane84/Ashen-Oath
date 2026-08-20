// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 245: Ashen Pin Lock & Trust UI Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "GA_KaelenOathbringerPinLock.h"
#include "AshenParanoiaPostProcessComponent.h"
#include "AshenSanctuaryFastTravelUIController.h"
#include "AshenUserWidget_TrustLevelMeter.h"

// =============================================================================
//  Test 1: Kaelen Oathbringer Pin Lock — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenOathbringerPinLockClassTest,
	"AshenOath.GAS.KaelenPinLock.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenOathbringerPinLockClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_KaelenOathbringerPinLock"));
	TestNotNull(TEXT("UGA_KaelenOathbringerPinLock must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 2: Paranoia Post Process — Vignette & Aberration Calculation
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenParanoiaPostProcessTest,
	"AshenOath.VFX.ParanoiaPostProcess.Calculation",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenParanoiaPostProcessTest::RunTest(const FString& Parameters)
{
	UAshenParanoiaPostProcessComponent* PP = NewObject<UAshenParanoiaPostProcessComponent>();
	if (!TestNotNull(TEXT("ParanoiaPostProcessComponent must be constructable"), PP)) return false;

	PP->UpdateParanoiaVFX(100.0f);
	TestEqual(TEXT("Vignette intensity must be 0.85 at 100% paranoia"), PP->GetVignetteIntensity(), 0.85f);
	TestEqual(TEXT("Chromatic aberration must be 3.5 at 100% paranoia"), PP->GetChromaticAberration(), 3.5f);

	PP->UpdateParanoiaVFX(0.0f);
	TestEqual(TEXT("Vignette intensity must be 0.0 at 0% paranoia"), PP->GetVignetteIntensity(), 0.0f);

	return true;
}

// =============================================================================
//  Test 3: Fast Travel UI Controller — Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenFastTravelUIControllerReflectionTest,
	"AshenOath.UI.FastTravelUIController.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenFastTravelUIControllerReflectionTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenSanctuaryFastTravelUIController class must be valid"),
		UAshenSanctuaryFastTravelUIController::StaticClass() != nullptr);
	return true;
}

// =============================================================================
//  Test 4: Trust Level Meter Widget — Update Display
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenTrustLevelMeterWidgetTest,
	"AshenOath.UI.TrustLevelMeterWidget.UpdateDisplay",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenTrustLevelMeterWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_TrustLevelMeter* Meter = NewObject<UAshenUserWidget_TrustLevelMeter>();
	if (!TestNotNull(TEXT("TrustLevelMeter widget must be constructable"), Meter)) return false;

	const FName Serafina(TEXT("Serafina"));
	Meter->UpdateTrustDisplay(Serafina, 80.0f, 1.40f);

	TestEqual(TEXT("ActiveCompanionName must be Serafina"), Meter->ActiveCompanionName, Serafina);
	TestEqual(TEXT("ActiveTrustScore must be 80.0"), Meter->ActiveTrustScore, 80.0f);
	TestEqual(TEXT("ActiveSynergyMultiplier must be 1.40x"), Meter->ActiveSynergyMultiplier, 1.40f);

	return true;
}

// =============================================================================
//  Test 5: Pin Lock — Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenPinLockReflectionTest,
	"AshenOath.GAS.KaelenPinLock.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenPinLockReflectionTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UGA_KaelenOathbringerPinLock class must be valid"),
		UGA_KaelenOathbringerPinLock::StaticClass() != nullptr);
	return true;
}
