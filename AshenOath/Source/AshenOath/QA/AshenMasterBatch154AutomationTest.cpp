// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Combat/AshenAlchemicalSlagTypes.h"
#include "Combat/AshenAlchemicalSlagConvergenceSubsystem.h"
#include "Combat/AshenBladeSootAccumulatorEvaluator.h"
#include "Combat/AshenThermalReactionEvaluator.h"
#include "Combat/AshenGarrettAlchemicalCoatingDirectorComponent.h"
#include "Combat/AshenAlchemicalSlagHapticBridge.h"
#include "Core/AshenAlchemicalSlagSaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch154AutomationTest,
	"AshenOath.Combat.MasterBatch154_AlchemicalSlagConvergence",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch154AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST BLADE SOOT ACCUMULATOR EVALUATOR
	// -----------------------------------------------------------------------------------
	{
		UAshenBladeSootAccumulatorEvaluator* SootEvaluator = NewObject<UAshenBladeSootAccumulatorEvaluator>();

		// Strike soot gain: 0.04 standard, 0.08 heavy cleave
		TestNearlyEqual(TEXT("Standard strike soot gain is 0.04"), SootEvaluator->EvaluateStrikeSootGain(false), 0.04f, 0.01f);
		TestNearlyEqual(TEXT("Heavy cleave soot gain is 0.08"), SootEvaluator->EvaluateStrikeSootGain(true), 0.08f, 0.01f);

		// Execution gain: 0.15
		TestNearlyEqual(TEXT("Execution soot gain is 0.15"), SootEvaluator->EvaluateExecutionSootGain(), 0.15f, 0.01f);

		// Superheated threshold >= 0.80
		TestTrue(TEXT("0.85 soot is superheated"), SootEvaluator->IsSuperheatedSlag(0.85f));
		TestFalse(TEXT("0.75 soot is not superheated"), SootEvaluator->IsSuperheatedSlag(0.75f));
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST THERMAL REACTION EVALUATOR (CONFLAGRATION & THERMAL SHOCK)
	// -----------------------------------------------------------------------------------
	{
		UAshenThermalReactionEvaluator* ReactionEvaluator = NewObject<UAshenThermalReactionEvaluator>();

		// Conflagration: Superheated + Naphtha -> 450 Dmg, 400uu radius
		const FThermalReactionResult Conflagration = ReactionEvaluator->EvaluateReaction(
			EOathbringerBladeSurfaceState::SuperheatedThermalSlag,
			EAlchemicalBladeCoating::PyrophoricNaphtha,
			false, false, false);

		TestTrue(TEXT("Reaction is Conflagration"), Conflagration.ReactionType == EThermalReactionType::ConflagrationDeflagration);
		TestNearlyEqual(TEXT("Conflagration bonus damage is 450"), Conflagration.BonusDamage, 450.0f, 0.01f);
		TestNearlyEqual(TEXT("Conflagration AoE radius is 400uu"), Conflagration.AoERadiusUU, 400.0f, 0.01f);

		// Thermal Shock: Superheated + Chilled Target -> 250 Dmg, 2.0x poise multiplier
		const FThermalReactionResult ThermalShock = ReactionEvaluator->EvaluateReaction(
			EOathbringerBladeSurfaceState::SuperheatedThermalSlag,
			EAlchemicalBladeCoating::GlacialFrostResin,
			true, false, false);

		TestTrue(TEXT("Reaction is Thermal Shock"), ThermalShock.ReactionType == EThermalReactionType::ThermalShockShatter);
		TestNearlyEqual(TEXT("Thermal Shock bonus damage is 250"), ThermalShock.BonusDamage, 250.0f, 0.01f);
		TestNearlyEqual(TEXT("Thermal Shock poise multiplier is 2.0x"), ThermalShock.PoiseDamageMultiplier, 2.00f, 0.01f);

		// Galvanic Pull: Copper Salve + Lightning Storm -> 500 Dmg, 500uu radius
		const FThermalReactionResult Galvanic = ReactionEvaluator->EvaluateReaction(
			EOathbringerBladeSurfaceState::PolishedResolve,
			EAlchemicalBladeCoating::ConductiveCopperSalve,
			false, false, true);

		TestTrue(TEXT("Reaction is Galvanic Pull"), Galvanic.ReactionType == EThermalReactionType::GalvanicShockBurst);
		TestNearlyEqual(TEXT("Galvanic bonus damage is 500"), Galvanic.BonusDamage, 500.0f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST GARRETT FLASK DIRECTOR COMPONENT
	// -----------------------------------------------------------------------------------
	{
		UAshenGarrettAlchemicalCoatingDirectorComponent* FlaskDirector = NewObject<UAshenGarrettAlchemicalCoatingDirectorComponent>();

		TestEqual(TEXT("Initial Naphtha flasks count is 3"), FlaskDirector->GetFlaskCount(EAlchemicalBladeCoating::PyrophoricNaphtha), 3);
		TestTrue(TEXT("Consume flask succeeds"), FlaskDirector->ConsumeFlask(EAlchemicalBladeCoating::PyrophoricNaphtha));
		TestEqual(TEXT("Remaining Naphtha flasks count is 2"), FlaskDirector->GetFlaskCount(EAlchemicalBladeCoating::PyrophoricNaphtha), 2);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST DUALSENSE REACTION HAPTICS
	// -----------------------------------------------------------------------------------
	{
		UAshenAlchemicalSlagHapticBridge* HapticBridge = NewObject<UAshenAlchemicalSlagHapticBridge>();
		float HeavyGain = 0.0f;
		float LightGain = 0.0f;

		// Conflagration deflagration: 0.95 heavy blast
		HapticBridge->EvaluateReactionHaptics(EThermalReactionType::ConflagrationDeflagration, HeavyGain, LightGain);
		TestNearlyEqual(TEXT("Conflagration heavy haptic gain is 0.95"), HeavyGain, 0.95f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST SAVEGAME PERSISTENCE
	// -----------------------------------------------------------------------------------
	{
		UAshenAlchemicalSlagSaveGameAdapter* SaveAdapter = NewObject<UAshenAlchemicalSlagSaveGameAdapter>();
		SaveAdapter->PackageSlagState(0.85f, EAlchemicalBladeCoating::VitriolAcid, 4);
		TestTrue(TEXT("SaveData is true"), SaveAdapter->HasSavedData());

		float RestoredSoot = 0.0f;
		EAlchemicalBladeCoating RestoredCoating = EAlchemicalBladeCoating::None;
		int32 RestoredCharges = 0;

		const bool bSuccess = SaveAdapter->RestoreSlagState(RestoredSoot, RestoredCoating, RestoredCharges);
		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestNearlyEqual(TEXT("Restored soot is 0.85"), RestoredSoot, 0.85f, 0.01f);
		TestTrue(TEXT("Restored coating is Vitriol Acid"), RestoredCoating == EAlchemicalBladeCoating::VitriolAcid);
		TestEqual(TEXT("Restored charges is 4"), RestoredCharges, 4);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
