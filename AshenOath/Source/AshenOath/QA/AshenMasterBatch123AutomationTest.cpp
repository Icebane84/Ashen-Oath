// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Crafting/AshenRunicReliquaryTypes.h"
#include "Crafting/AshenRunicReliquarySubsystem.h"
#include "Crafting/AshenSoulForgeTransmuterComponent.h"
#include "Crafting/AshenWeaponAttunementEvaluatorComponent.h"
#include "Crafting/AshenRunicSocketRegistryComponent.h"
#include "Core/AshenRunicForgeSaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch123AutomationTest,
	"AshenOath.Crafting.MasterBatch123_RunicReliquary",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch123AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST BOSS SHARD TRANSMUTATION
	// -----------------------------------------------------------------------------------
	{
		UAshenSoulForgeTransmuterComponent* Transmuter = NewObject<UAshenSoulForgeTransmuterComponent>();

		// Transmute Nightsteel Titan shard
		const FRunicSocketEntry BossRune = Transmuter->TransmuteBossShard(TEXT("Titan"), 1.0f);

		TestEqual(TEXT("Rune ID is Rune_Core_Titan"), BossRune.RuneId, FName(TEXT("Rune_Core_Titan")));
		TestEqual(TEXT("Socket Type is BladeCore"), BossRune.SocketType, ERunicSocketType::BladeCore);
		TestEqual(TEXT("Tier is MasterForged"), BossRune.AttunementTier, ESoulForgeAttunementTier::MasterForged);
		TestNearlyEqual(TEXT("Mass modifier is +35kg"), BossRune.MassModifierKg, 35.0f, 0.01f);
		TestNearlyEqual(TEXT("Poise multiplier is 1.40x"), BossRune.PoiseMultiplier, 1.40f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST TRAUMA MEMORY CRYSTALLIZATION
	// -----------------------------------------------------------------------------------
	{
		UAshenSoulForgeTransmuterComponent* Transmuter = NewObject<UAshenSoulForgeTransmuterComponent>();

		// Transmute Garrett's trauma memory (Debt = 0.80 -> Overcharged)
		const FRunicSocketEntry MemoryRune = Transmuter->TransmuteTraumaMemory(TEXT("Garrett"), 0.80f);

		TestEqual(TEXT("Rune ID is Rune_Memory_Garrett"), MemoryRune.RuneId, FName(TEXT("Rune_Memory_Garrett")));
		TestEqual(TEXT("Socket Type is HiltRelic"), MemoryRune.SocketType, ERunicSocketType::HiltRelic);
		TestEqual(TEXT("Tier is Overcharged"), MemoryRune.AttunementTier, ESoulForgeAttunementTier::Overcharged);
		TestNearlyEqual(TEXT("Mass modifier is -10kg"), MemoryRune.MassModifierKg, -10.0f, 0.01f);
		TestNearlyEqual(TEXT("Stamina cost scalar is 0.85x"), MemoryRune.StaminaCostScalar, 0.85f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST WEAPON ATTUNEMENT & KINETIC ENERGY EVALUATION
	// -----------------------------------------------------------------------------------
	{
		UAshenWeaponAttunementEvaluatorComponent* Evaluator = NewObject<UAshenWeaponAttunementEvaluatorComponent>();

		FSoulForgeWeaponState State;
		State.WeaponId = FName(TEXT("Greatsword"));
		State.BaseMassKg = 120.0f;
		State.EffectiveMassKg = 155.0f; // +35kg Boss Core
		State.TotalPoiseMultiplier = 1.40f;

		// Test Kinetic Energy at 1200 velocity (12.0 normalized)
		// E_k = 0.5 * 155.0 * (12.0^2) * 1.40 = 0.5 * 155.0 * 144.0 * 1.40 = 15,624.0 J
		const float Ek = Evaluator->EvaluateKineticEnergy(State, 1200.0f);
		TestNearlyEqual(TEXT("Kinetic Energy is 15,624.0 J"), Ek, 15624.0f, 1.0f);

		const float StaminaCost = Evaluator->EvaluateStaminaCostScalar(State);
		TestNearlyEqual(TEXT("Stamina Cost is 155/120 = 1.29x"), StaminaCost, 155.0f / 120.0f, 0.02f);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST RUNIC FORGE SAVEGAME ADAPTER
	// -----------------------------------------------------------------------------------
	{
		UAshenRunicForgeSaveGameAdapter* SaveAdapter = NewObject<UAshenRunicForgeSaveGameAdapter>();

		FSoulForgeWeaponState OriginalState;
		OriginalState.WeaponId = FName(TEXT("NightsteelGreatsword"));
		OriginalState.BaseMassKg = 120.0f;
		OriginalState.EffectiveMassKg = 155.0f;
		OriginalState.TotalPoiseMultiplier = 1.40f;
		OriginalState.ActiveSocketCount = 2;
		OriginalState.bHasBossCoreInfusion = true;

		SaveAdapter->PackageWeaponState(OriginalState);
		TestTrue(TEXT("HasSavedData is true"), SaveAdapter->HasSavedData());

		FSoulForgeWeaponState RestoredState;
		const bool bSuccess = SaveAdapter->RestoreWeaponState(RestoredState);

		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestEqual(TEXT("WeaponId restored"), RestoredState.WeaponId, FName(TEXT("NightsteelGreatsword")));
		TestNearlyEqual(TEXT("EffectiveMassKg restored"), RestoredState.EffectiveMassKg, 155.0f, 0.01f);
		TestNearlyEqual(TEXT("TotalPoiseMultiplier restored"), RestoredState.TotalPoiseMultiplier, 1.40f, 0.01f);
		TestEqual(TEXT("ActiveSocketCount restored"), RestoredState.ActiveSocketCount, 2);
		TestTrue(TEXT("bHasBossCoreInfusion restored"), RestoredState.bHasBossCoreInfusion);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
