// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "World/AshenSanctuarySurvivalConvergenceSubsystem.h"
#include "World/AshenMealHazardImmunityEvaluator.h"
#include "World/AshenShelterThermodynamicsEvaluator.h"
#include "World/AshenSanctuarySurvivalBalanceDataAsset.h"
#include "Companions/AshenCompanionFatigueSubsystem.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSanctuarySurvivalConvergenceIntegrationTest,
	"AshenOath.Convergence.SanctuarySurvival.MealsAndThermodynamics",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenSanctuarySurvivalConvergenceIntegrationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. SETUP TRANSIENT WORLD & GAME INSTANCE
	// -----------------------------------------------------------------------------------
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("SanctuarySurvivalTestWorld"));
	TestNotNull(TEXT("Transient World created"), World);
	if (!World)
	{
		return false;
	}

	UGameInstance* GameInstance = NewObject<UGameInstance>(World);
	GameInstance->Init();
	World->SetGameInstance(GameInstance);

	UAshenSanctuarySurvivalConvergenceSubsystem* Subsystem = World->GetSubsystem<UAshenSanctuarySurvivalConvergenceSubsystem>();
	UAshenCompanionFatigueSubsystem* FatigueSubsystem = GameInstance->GetSubsystem<UAshenCompanionFatigueSubsystem>();

	TestNotNull(TEXT("UAshenSanctuarySurvivalConvergenceSubsystem exists on World"), Subsystem);
	TestNotNull(TEXT("UAshenCompanionFatigueSubsystem exists on GameInstance"), FatigueSubsystem);

	UAshenMealHazardImmunityEvaluator* MealEvaluator = NewObject<UAshenMealHazardImmunityEvaluator>(World);
	UAshenShelterThermodynamicsEvaluator* ThermoEvaluator = NewObject<UAshenShelterThermodynamicsEvaluator>(World);

	TestNotNull(TEXT("MealEvaluator instantiated"), MealEvaluator);
	TestNotNull(TEXT("ThermoEvaluator instantiated"), ThermoEvaluator);

	// -----------------------------------------------------------------------------------
	// 2. TEST CAMPFIRE COOKED MEAL HAZARD IMMUNITIES (100% REDUCTION)
	// -----------------------------------------------------------------------------------
	if (MealEvaluator)
	{
		// Glacial Stew vs Blizzard -> 100% Immunity
		const bool bGlacialImmune = MealEvaluator->IsImmuneToHazard(ECookedMealBuffType::GlacialHeartStew, true, false, false);
		const float GlacialReduction = MealEvaluator->EvaluateHazardDamageReduction(ECookedMealBuffType::GlacialHeartStew, true, false, false);
		TestTrue(TEXT("Glacial Stew grants Blizzard immunity"), bGlacialImmune);
		TestNearlyEqual(TEXT("Glacial Stew grants 100% damage reduction in Blizzard"), GlacialReduction, 1.0f, 0.01f);

		// Vitriol Broth vs Acid Rain -> 100% Immunity
		const bool bVitriolImmune = MealEvaluator->IsImmuneToHazard(ECookedMealBuffType::VitriolPurgeBroth, false, true, false);
		const float VitriolReduction = MealEvaluator->EvaluateHazardDamageReduction(ECookedMealBuffType::VitriolPurgeBroth, false, true, false);
		TestTrue(TEXT("Vitriol Broth grants Acid Rain immunity"), bVitriolImmune);
		TestNearlyEqual(TEXT("Vitriol Broth grants 100% damage reduction in Acid Rain"), VitriolReduction, 1.0f, 0.01f);

		// Cinder Ash Cake vs Ash Storm -> 100% Immunity
		const bool bCinderImmune = MealEvaluator->IsImmuneToHazard(ECookedMealBuffType::CinderAshCake, false, false, true);
		const float CinderReduction = MealEvaluator->EvaluateHazardDamageReduction(ECookedMealBuffType::CinderAshCake, false, false, true);
		TestTrue(TEXT("Cinder Cake grants Ash Storm immunity"), bCinderImmune);
		TestNearlyEqual(TEXT("Cinder Cake grants 100% damage reduction in Ash Storm"), CinderReduction, 1.0f, 0.01f);

		// Unmatched: Glacial Stew in Acid Rain -> 0% Immunity
		const bool bUnmatched = MealEvaluator->IsImmuneToHazard(ECookedMealBuffType::GlacialHeartStew, false, true, false);
		const float UnmatchedReduction = MealEvaluator->EvaluateHazardDamageReduction(ECookedMealBuffType::GlacialHeartStew, false, true, false);
		TestFalse(TEXT("Glacial Stew does NOT protect against Acid Rain"), bUnmatched);
		TestNearlyEqual(TEXT("Unmatched meal grants 0% damage reduction"), UnmatchedReduction, 0.0f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST 3-TIER SHELTER THERMODYNAMICS
	// -----------------------------------------------------------------------------------
	if (ThermoEvaluator)
	{
		// Open Wilderness in Blizzard -> -2.5 HP/s, 1.0x cook speed, 1.0 sanity decay
		const float OpenHPLoss = ThermoEvaluator->EvaluateHypothermiaHPLoss(EThermalShelterTier::OpenWilderness, true);
		const float OpenCooking = ThermoEvaluator->EvaluateCookingSpeedMultiplier(EThermalShelterTier::OpenWilderness);
		const float OpenSanityDecay = ThermoEvaluator->EvaluateSanityDecayScale(EThermalShelterTier::OpenWilderness);
		TestNearlyEqual(TEXT("Wilderness hypothermia loss is -2.50 HP/s"), OpenHPLoss, -2.50f, 0.01f);
		TestNearlyEqual(TEXT("Wilderness cooking speed is 1.00x"), OpenCooking, 1.00f, 0.01f);
		TestNearlyEqual(TEXT("Wilderness sanity decay scale is 1.00"), OpenSanityDecay, 1.00f, 0.01f);

		// Natural Cavern in Blizzard -> 0.0 HP/s, 2.0x cook speed, 0.25 sanity decay
		const float CavernHPLoss = ThermoEvaluator->EvaluateHypothermiaHPLoss(EThermalShelterTier::NaturalCavern, true);
		const float CavernCooking = ThermoEvaluator->EvaluateCookingSpeedMultiplier(EThermalShelterTier::NaturalCavern);
		const float CavernSanityDecay = ThermoEvaluator->EvaluateSanityDecayScale(EThermalShelterTier::NaturalCavern);
		TestNearlyEqual(TEXT("Cavern blocks hypothermia damage (0.0 HP/s)"), CavernHPLoss, 0.0f, 0.01f);
		TestNearlyEqual(TEXT("Cavern cooking speed is 2.00x"), CavernCooking, 2.00f, 0.01f);
		TestNearlyEqual(TEXT("Cavern sanity decay scale is 0.25"), CavernSanityDecay, 0.25f, 0.01f);

		// Sanctuary Hearth -> 0.0 HP/s, 2.0x cook speed, 0.0 sanity decay
		const float HearthSanityDecay = ThermoEvaluator->EvaluateSanityDecayScale(EThermalShelterTier::SanctuaryHearthRadius);
		TestNearlyEqual(TEXT("Sanctuary hearth completely stops sanity decay (0.00)"), HearthSanityDecay, 0.0f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST SANCTUARY BEACON IGNITION & FATIGUE PURGE
	// -----------------------------------------------------------------------------------
	if (Subsystem && FatigueSubsystem)
	{
		FatigueSubsystem->AccumulateFatigue(TEXT("Garrett"), 0.75f);
		FatigueSubsystem->AccumulateFatigue(TEXT("Serafina"), 0.75f);
		TestNearlyEqual(TEXT("Garrett fatigue accumulated to 0.75"), FatigueSubsystem->GarrettFatigue, 0.75f, 0.01f);

		const FName TestBeaconId = FName(TEXT("FrostboundCitadelHearth"));
		Subsystem->IgniteBeacon(TestBeaconId, TEXT("Sundered Crags"), FText::FromString(TEXT("Ancient sacred flames reignited.")));

		TestTrue(TEXT("Beacon is marked ignited"), Subsystem->IsBeaconIgnited(TestBeaconId));
		TestTrue(TEXT("Shelter tier updated to SanctuaryHearthRadius"), Subsystem->GetShelterTier() == EThermalShelterTier::SanctuaryHearthRadius);

		// Assert Companion Fatigue completely purged to 0.0
		TestNearlyEqual(TEXT("Garrett fatigue purged to 0.0 at Sanctuary"), FatigueSubsystem->GarrettFatigue, 0.0f, 0.01f);
		TestNearlyEqual(TEXT("Serafina fatigue purged to 0.0 at Sanctuary"), FatigueSubsystem->SerafinaFatigue, 0.0f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST DATA ASSET LIVE OVERRIDE
	// -----------------------------------------------------------------------------------
	if (ThermoEvaluator)
	{
		UAshenSanctuarySurvivalBalanceDataAsset* BalanceAsset = NewObject<UAshenSanctuarySurvivalBalanceDataAsset>(World);
		BalanceAsset->ShelterBalancing.WildernessHypothermiaHPLoss = -4.0f;
		BalanceAsset->ShelterBalancing.CavernCookingSpeedMultiplier = 3.5f;

		ThermoEvaluator->BalanceDataAsset = BalanceAsset;

		const float CustomLoss = ThermoEvaluator->EvaluateHypothermiaHPLoss(EThermalShelterTier::OpenWilderness, true);
		const float CustomCooking = ThermoEvaluator->EvaluateCookingSpeedMultiplier(EThermalShelterTier::NaturalCavern);

		TestNearlyEqual(TEXT("DataAsset live override sets hypothermia loss to -4.0 HP/s"), CustomLoss, -4.0f, 0.01f);
		TestNearlyEqual(TEXT("DataAsset live override sets cavern cooking to 3.5x"), CustomCooking, 3.5f, 0.01f);
	}

	// Cleanup
	World->DestroyWorld(false);
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
