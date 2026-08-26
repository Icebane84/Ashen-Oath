// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "World/AshenDynamicWeatherTypes.h"
#include "World/AshenDynamicWeatherSubsystem.h"
#include "World/AshenWeatherDegradationEvaluator.h"
#include "World/AshenLightningSurgeEvaluator.h"
#include "World/AshenWeatherShelterDirectorComponent.h"
#include "Combat/AshenWeatherHapticBridge.h"
#include "Core/AshenWeatherSaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch148AutomationTest,
	"AshenOath.World.MasterBatch148_DynamicWeatherEnvironmentalBiomeHazards",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch148AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST WEATHER DEGRADATION & ACID CORROSION
	// -----------------------------------------------------------------------------------
	{
		UAshenWeatherDegradationEvaluator* DegradationEvaluator = NewObject<UAshenWeatherDegradationEvaluator>();

		// Movement slow in blizzard: 0.70x (-30%)
		TestNearlyEqual(TEXT("Blizzard movement slow is 0.70x"), DegradationEvaluator->EvaluateMovementSpeedModifier(EWeatherHazardState::BlizzardWhiteout), 0.70f, 0.01f);
		TestNearlyEqual(TEXT("Clear weather speed is 1.00x"), DegradationEvaluator->EvaluateMovementSpeedModifier(EWeatherHazardState::ClearTemperate), 1.00f, 0.01f);

		// Acid corrosion base: 2.5%/s; with alchemical insulation: 1.0%/s (60% mitigation)
		TestNearlyEqual(TEXT("Acid corrosion unmitigated is 2.5%/s"), DegradationEvaluator->EvaluateArmorCorrosionRate(EWeatherHazardState::AcidRainCorrosion, false), 2.5f, 0.01f);
		TestNearlyEqual(TEXT("Acid corrosion insulated is 1.0%/s"), DegradationEvaluator->EvaluateArmorCorrosionRate(EWeatherHazardState::AcidRainCorrosion, true), 1.0f, 0.01f);

		// Stamina regen in ash storm: 0.75x (-25%)
		TestNearlyEqual(TEXT("Ash storm stamina regen is 0.75x"), DegradationEvaluator->EvaluateStaminaRegenModifier(EWeatherHazardState::VolcanicAshStorm), 0.75f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST LIGHTNING STRIKE DAMAGE & TELEGRAPH
	// -----------------------------------------------------------------------------------
	{
		UAshenLightningSurgeEvaluator* LightningEvaluator = NewObject<UAshenLightningSurgeEvaluator>();

		// Lightning damage: Moderate = 850 Dmg, Cataclysm = 1250 Dmg
		TestNearlyEqual(TEXT("Moderate lightning damage is 850 Dmg"), LightningEvaluator->EvaluateLightningStrikeDamage(EAtmosphericSeverity::ModerateGale), 850.0f, 0.01f);
		TestNearlyEqual(TEXT("Cataclysm lightning damage is 1250 Dmg"), LightningEvaluator->EvaluateLightningStrikeDamage(EAtmosphericSeverity::SevereCataclysm), 1250.0f, 0.01f);

		// Telegraph timing
		TestNearlyEqual(TEXT("Lightning telegraph duration is 1.5s"), LightningEvaluator->GetTelegraphWarningDurationSeconds(), 1.5f, 0.01f);
		TestNearlyEqual(TEXT("Lightning telegraph radius is 250uu"), LightningEvaluator->GetTelegraphRadiusUU(), 250.0f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST SHELTER MITIGATION PERCENTAGES
	// -----------------------------------------------------------------------------------
	{
		UAshenWeatherShelterDirectorComponent* ShelterDirector = NewObject<UAshenWeatherShelterDirectorComponent>();

		// Hearth Sanctuary = 100%, Cavern = 75%, Exposed = 0%
		TestNearlyEqual(TEXT("Hearth sanctuary mitigation is 100%"), ShelterDirector->EvaluateHazardMitigation(EWeatherShelterType::HearthSanctuary), 1.00f, 0.01f);
		TestNearlyEqual(TEXT("Cavern overhang mitigation is 75%"), ShelterDirector->EvaluateHazardMitigation(EWeatherShelterType::CavernOverhang), 0.75f, 0.01f);
		TestNearlyEqual(TEXT("Exposed wilds mitigation is 0%"), ShelterDirector->EvaluateHazardMitigation(EWeatherShelterType::ExposedWilds), 0.00f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST DUALSENSE HAPTICS
	// -----------------------------------------------------------------------------------
	{
		UAshenWeatherHapticBridge* HapticBridge = NewObject<UAshenWeatherHapticBridge>();
		float WindResistance = 0.0f;
		float RainTickle = 0.0f;
		float LightningShock = 0.0f;

		// Exposed in Acid Rain with 20m/s wind
		HapticBridge->EvaluateWeatherHaptics(EWeatherHazardState::AcidRainCorrosion, 20.0f, EWeatherShelterType::ExposedWilds, WindResistance, RainTickle, LightningShock);
		TestNearlyEqual(TEXT("Wind drag resistance is 0.575"), WindResistance, 0.575f, 0.01f);
		TestNearlyEqual(TEXT("Rain tickle gain is 0.85"), RainTickle, 0.85f, 0.01f);

		// Inside Hearth Sanctuary: 0 haptics
		HapticBridge->EvaluateWeatherHaptics(EWeatherHazardState::AcidRainCorrosion, 20.0f, EWeatherShelterType::HearthSanctuary, WindResistance, RainTickle, LightningShock);
		TestNearlyEqual(TEXT("Sheltered wind resistance is 0"), WindResistance, 0.0f, 0.01f);
		TestNearlyEqual(TEXT("Sheltered rain tickle is 0"), RainTickle, 0.0f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST SAVEGAME PERSISTENCE
	// -----------------------------------------------------------------------------------
	{
		UAshenWeatherSaveGameAdapter* SaveAdapter = NewObject<UAshenWeatherSaveGameAdapter>();
		SaveAdapter->PackageWeatherState(EWeatherHazardState::BlizzardWhiteout, EAtmosphericSeverity::SevereCataclysm, -35.0f);
		TestTrue(TEXT("SaveData is true"), SaveAdapter->HasSavedData());

		EWeatherHazardState RestoredState = EWeatherHazardState::ClearTemperate;
		EAtmosphericSeverity RestoredSeverity = EAtmosphericSeverity::MildDrift;
		float RestoredTemp = 0.0f;

		const bool bSuccess = SaveAdapter->RestoreWeatherState(RestoredState, RestoredSeverity, RestoredTemp);
		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestTrue(TEXT("Restored weather is Blizzard"), RestoredState == EWeatherHazardState::BlizzardWhiteout);
		TestTrue(TEXT("Restored severity is Cataclysm"), RestoredSeverity == EAtmosphericSeverity::SevereCataclysm);
		TestNearlyEqual(TEXT("Restored temperature is -35C"), RestoredTemp, -35.0f, 0.01f);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
