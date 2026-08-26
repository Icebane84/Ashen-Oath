// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "World/AshenCampfireCookingTypes.h"
#include "World/AshenCampfireCookingSubsystem.h"
#include "World/AshenMoraleBuffEvaluator.h"
#include "World/AshenRationSpoilageEvaluator.h"
#include "World/AshenAlchemicalRationingDirectorComponent.h"
#include "Combat/AshenCampfireCookingHapticBridge.h"
#include "Core/AshenCampfireCookingSaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch146AutomationTest,
	"AshenOath.World.MasterBatch146_SoulEmberCampfireCookingAlchemicalRationing",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch146AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST CAMPFIRE RECIPE MORALE BUFFS
	// -----------------------------------------------------------------------------------
	{
		UAshenMoraleBuffEvaluator* BuffEvaluator = NewObject<UAshenMoraleBuffEvaluator>();

		// Sentinel's Iron Broth: +25% poise, +150 stamina
		TestNearlyEqual(TEXT("Sentinel Iron Broth poise bonus is 1.25x"), BuffEvaluator->EvaluatePoiseResistanceBonus(ECampfireRecipeType::SentinelsIronBroth), 1.25f, 0.01f);
		TestNearlyEqual(TEXT("Sentinel Iron Broth stamina bonus is 150"), BuffEvaluator->EvaluateMaxStaminaBonus(ECampfireRecipeType::SentinelsIronBroth), 150.0f, 0.01f);

		// White Flame Herbal Tisane: -30% burnout accumulation (0.70x)
		TestNearlyEqual(TEXT("White Flame Tisane burnout mitigation is 0.70x"), BuffEvaluator->EvaluateBurnoutMitigationMultiplier(ECampfireRecipeType::WhiteFlameHerbalTisane), 0.70f, 0.01f);

		// Gloomwood Venison Stew: +20% kinetic damage
		TestNearlyEqual(TEXT("Gloomwood Venison kinetic damage is 1.20x"), BuffEvaluator->EvaluateKineticDamageMultiplier(ECampfireRecipeType::GloomwoodVenisonStew), 1.20f, 0.01f);

		// Grand Zenith Soul Goulash: +25% all stats
		TestNearlyEqual(TEXT("Grand Zenith Goulash poise bonus is 1.25x"), BuffEvaluator->EvaluatePoiseResistanceBonus(ECampfireRecipeType::GrandZenithSoulGoulash), 1.25f, 0.01f);
		TestNearlyEqual(TEXT("Grand Zenith Goulash damage bonus is 1.25x"), BuffEvaluator->EvaluateKineticDamageMultiplier(ECampfireRecipeType::GrandZenithSoulGoulash), 1.25f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST RATION SPOILAGE & EMBER-SALT PRESERVATION
	// -----------------------------------------------------------------------------------
	{
		UAshenRationSpoilageEvaluator* SpoilageEvaluator = NewObject<UAshenRationSpoilageEvaluator>();

		// Common ration over 500m: 100% - (500/100) = 95%
		const float CommonFresh = SpoilageEvaluator->EvaluateFreshnessAfterDistance(100.0f, 500.0f, EIngredientQualityTier::CommonForaged);
		TestNearlyEqual(TEXT("Common ration after 500m is 95%"), CommonFresh, 95.0f, 0.01f);

		// Salted ration over 600m: 100% - ((600/100) / 3) = 98%
		const float SaltedFresh = SpoilageEvaluator->EvaluateFreshnessAfterDistance(100.0f, 600.0f, EIngredientQualityTier::PreservedSalted);
		TestNearlyEqual(TEXT("Salted ration after 600m is 98%"), SaltedFresh, 98.0f, 0.01f);

		// Spoilage check
		TestTrue(TEXT("0% freshness is spoiled"), SpoilageEvaluator->IsRationSpoiled(0.0f));
		TestFalse(TEXT("50% freshness is not spoiled"), SpoilageEvaluator->IsRationSpoiled(50.0f));
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST INGREDIENT VALIDATION FOR RECIPES
	// -----------------------------------------------------------------------------------
	{
		UAshenAlchemicalRationingDirectorComponent* RationDirector = NewObject<UAshenAlchemicalRationingDirectorComponent>();

		// Sentinel's Broth requires 1 meat + 1 salt
		TestTrue(TEXT("1 meat + 1 salt is valid for Broth"), RationDirector->ValidateIngredientsForRecipe(ECampfireRecipeType::SentinelsIronBroth, 1, 0, 1));
		TestFalse(TEXT("0 meat + 1 salt is INVALID for Broth"), RationDirector->ValidateIngredientsForRecipe(ECampfireRecipeType::SentinelsIronBroth, 0, 0, 1));

		// Tisane requires 2 herbs
		TestTrue(TEXT("2 herbs valid for Tisane"), RationDirector->ValidateIngredientsForRecipe(ECampfireRecipeType::WhiteFlameHerbalTisane, 0, 2, 0));
		TestFalse(TEXT("1 herb INVALID for Tisane"), RationDirector->ValidateIngredientsForRecipe(ECampfireRecipeType::WhiteFlameHerbalTisane, 0, 1, 0));
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST DUALSENSE HAPTICS
	// -----------------------------------------------------------------------------------
	{
		UAshenCampfireCookingHapticBridge* HapticBridge = NewObject<UAshenCampfireCookingHapticBridge>();
		float StirringRes = 0.0f;
		float WarmthGain = 0.0f;
		float ServedChime = 0.0f;

		// Active stirring haptics
		HapticBridge->EvaluateCookingHaptics(ECookingPotState::ActiveStirring, 95.0f, StirringRes, WarmthGain, ServedChime);
		TestNearlyEqual(TEXT("Active stirring resistance is 0.45"), StirringRes, 0.45f, 0.01f);
		TestNearlyEqual(TEXT("Warmth crackle gain is 0.65"), WarmthGain, 0.65f, 0.01f);
		TestNearlyEqual(TEXT("Served chime is 0.0"), ServedChime, 0.0f, 0.01f);

		// Meal ready served
		HapticBridge->EvaluateCookingHaptics(ECookingPotState::MealReadyServed, 80.0f, StirringRes, WarmthGain, ServedChime);
		TestNearlyEqual(TEXT("Served chime is 1.0"), ServedChime, 1.0f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST SAVEGAME PERSISTENCE
	// -----------------------------------------------------------------------------------
	{
		UAshenCampfireCookingSaveGameAdapter* SaveAdapter = NewObject<UAshenCampfireCookingSaveGameAdapter>();
		SaveAdapter->PackageCookingState(ECampfireRecipeType::SentinelsIronBroth, 450.0f, 6);
		TestTrue(TEXT("SaveData is true"), SaveAdapter->HasSavedData());

		ECampfireRecipeType RestoredMeal = ECampfireRecipeType::None;
		float RestoredTime = 0.0f;
		int32 RestoredRations = 0;

		const bool bSuccess = SaveAdapter->RestoreCookingState(RestoredMeal, RestoredTime, RestoredRations);
		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestTrue(TEXT("Restored recipe is Sentinel Broth"), RestoredMeal == ECampfireRecipeType::SentinelsIronBroth);
		TestNearlyEqual(TEXT("Restored buff time is 450s"), RestoredTime, 450.0f, 0.01f);
		TestEqual(TEXT("Restored rations count is 6"), RestoredRations, 6);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
