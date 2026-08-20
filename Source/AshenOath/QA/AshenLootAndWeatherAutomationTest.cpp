// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 255: Ashen Boss Loot & Weather Audio Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenBossLootChestComponent.h"
#include "GA_SerafinaHolyLightRays.h"
#include "AshenDynamicWeatherAudioSubsystem.h"
#include "AshenUserWidget_BossLootReward.h"

// =============================================================================
//  Test 1: Boss Loot Chest — Opening & State
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenBossLootChestTest,
	"AshenOath.Loot.BossChest.OpeningState",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenBossLootChestTest::RunTest(const FString& Parameters)
{
	UAshenBossLootChestComponent* Chest = NewObject<UAshenBossLootChestComponent>();
	if (!TestNotNull(TEXT("BossLootChestComponent must be constructable"), Chest)) return false;

	TestFalse(TEXT("Chest must initially be unopened"), Chest->IsOpened());
	bool bOpened = Chest->OpenChest(nullptr);
	TestTrue(TEXT("OpenChest must return true"), bOpened);
	TestTrue(TEXT("Chest must be opened"), Chest->IsOpened());

	return true;
}

// =============================================================================
//  Test 2: Serafina Holy Light Rays — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenHolyLightRaysClassTest,
	"AshenOath.GAS.SerafinaHolyRays.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenHolyLightRaysClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_SerafinaHolyLightRays"));
	TestNotNull(TEXT("UGA_SerafinaHolyLightRays must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 3: Dynamic Weather Audio — Wind Volume Modulations
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenWeatherAudioWindVolumeTest,
	"AshenOath.Audio.DynamicWeather.WindVolumeModulation",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenWeatherAudioWindVolumeTest::RunTest(const FString& Parameters)
{
	UAshenDynamicWeatherAudioSubsystem* AudioSub = NewObject<UAshenDynamicWeatherAudioSubsystem>();
	if (!TestNotNull(TEXT("DynamicWeatherAudioSubsystem must be constructable"), AudioSub)) return false;

	AudioSub->UpdateWeatherAudio(EAshenWeatherState::ClearCalm);
	TestEqual(TEXT("Wind volume for ClearCalm must be 0.20"), AudioSub->GetWindVolume(), 0.20f);

	AudioSub->UpdateWeatherAudio(EAshenWeatherState::HeavyBlizzard);
	TestEqual(TEXT("Wind volume for HeavyBlizzard must be 0.95"), AudioSub->GetWindVolume(), 0.95f);

	return true;
}

// =============================================================================
//  Test 4: Boss Loot Reward Widget — Display & Dismiss
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenBossLootRewardWidgetTest,
	"AshenOath.UI.BossLootRewardWidget.DisplayAndDismiss",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenBossLootRewardWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_BossLootReward* Reward = NewObject<UAshenUserWidget_BossLootReward>();
	if (!TestNotNull(TEXT("BossLootReward widget must be constructable"), Reward)) return false;

	const FName ItemID(TEXT("Item_Sword_01"));
	const FText ItemName = FText::FromString(TEXT("Paladin Blade"));

	Reward->DisplayRewardOverlay(500.0f, ItemID, ItemName);
	TestTrue(TEXT("bRewardActive must be true after display"), Reward->bRewardActive);

	Reward->DismissRewardOverlay();
	TestFalse(TEXT("bRewardActive must be false after dismiss"), Reward->bRewardActive);

	return true;
}

// =============================================================================
//  Test 5: Boss Loot Chest — Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenBossLootChestReflectionTest,
	"AshenOath.Loot.BossChest.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenBossLootChestReflectionTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenBossLootChestComponent class must be valid"),
		UAshenBossLootChestComponent::StaticClass() != nullptr);
	return true;
}
