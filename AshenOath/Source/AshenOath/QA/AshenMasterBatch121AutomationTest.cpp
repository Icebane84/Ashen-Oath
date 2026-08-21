// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Narrative/AshenCampfireHearthTypes.h"
#include "Narrative/AshenSoulRecoveryEvaluatorComponent.h"
#include "Narrative/AshenProximitySeatingStagingComponent.h"
#include "Narrative/AshenTraumaTransmutationEngineComponent.h"
#include "Core/AshenCampfireSaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch121AutomationTest,
	"AshenOath.Narrative.MasterBatch121_CampfireHearth",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch121AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST THREE-TIER REST EVALUATION
	// -----------------------------------------------------------------------------------
	{
		UAshenSoulRecoveryEvaluatorComponent* Evaluator = NewObject<UAshenSoulRecoveryEvaluatorComponent>();

		// Case A: Minor Rest (< 0.30 Debt)
		const FCampfireIntegrationSnapshot SnapMinor = Evaluator->EvaluateRestSession(0.15f, 0.10f);
		TestEqual(TEXT("Minor Rest tier evaluated"), SnapMinor.RestTier, ECampfireRestTier::MinorRest);
		TestNearlyEqual(TEXT("Minor bonus is +5%"), SnapMinor.TransmutedTraitBonus, 0.05f, 0.001f);

		// Case B: Reflective Transmute (0.30 - 0.70 Debt)
		const FCampfireIntegrationSnapshot SnapReflect = Evaluator->EvaluateRestSession(0.50f, 0.40f);
		TestEqual(TEXT("Reflective Transmute tier evaluated"), SnapReflect.RestTier, ECampfireRestTier::ReflectiveTransmute);
		TestNearlyEqual(TEXT("Reflective bonus is +10%"), SnapReflect.TransmutedTraitBonus, 0.10f, 0.001f);

		// Case C: Solemn Vigil (> 0.70 Debt/Dysregulation)
		const FCampfireIntegrationSnapshot SnapVigil = Evaluator->EvaluateRestSession(0.85f, 0.75f);
		TestEqual(TEXT("Solemn Vigil tier evaluated"), SnapVigil.RestTier, ECampfireRestTier::SolemnVigil);
		TestNearlyEqual(TEXT("Vigil bonus is +15%"), SnapVigil.TransmutedTraitBonus, 0.15f, 0.001f);
		TestTrue(TEXT("Catharsis dialogue triggered for Solemn Vigil"), SnapVigil.bCatharsisDialogueTriggered);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST PROXIMITY SEATING CALCULATIONS
	// -----------------------------------------------------------------------------------
	{
		UAshenProximitySeatingStagingComponent* SeatingComp = NewObject<UAshenProximitySeatingStagingComponent>();

		// High trust / Low dysregulation -> Intimate (250uu)
		const ECompanionHearthSeating SeatIntimate = SeatingComp->CalculateSeating(0.80f, 0.20f);
		TestEqual(TEXT("Intimate seating evaluated"), SeatIntimate, ECompanionHearthSeating::IntimateProximity);
		TestNearlyEqual(TEXT("Intimate distance is 250uu"), SeatingComp->GetSeatingDistanceUU(SeatIntimate), 250.0f, 0.1f);

		// High dysregulation -> Guarded Standoff (800uu)
		const ECompanionHearthSeating SeatGuarded = SeatingComp->CalculateSeating(0.50f, 0.75f);
		TestEqual(TEXT("Guarded standoff seating evaluated"), SeatGuarded, ECompanionHearthSeating::GuardedStandoff);
		TestNearlyEqual(TEXT("Guarded distance is 800uu"), SeatingComp->GetSeatingDistanceUU(SeatGuarded), 800.0f, 0.1f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST TRAUMA TRANSMUTATION ENGINE
	// -----------------------------------------------------------------------------------
	{
		UAshenTraumaTransmutationEngineComponent* TransmuteEngine = NewObject<UAshenTraumaTransmutationEngineComponent>();

		const FTransmutedTraitReward Reward = TransmuteEngine->ForgeTrait(
			TEXT("UnbrokenResolve"),
			FGameplayTag::RequestGameplayTag(TEXT("Ashen.Trait.UnbrokenResolve"), false),
			0.10f);

		TestEqual(TEXT("Forged trait name matches"), Reward.TraitName, FName(TEXT("UnbrokenResolve")));
		TestNearlyEqual(TEXT("Bonus scalar is +10%"), Reward.StatBonusScalar, 0.10f, 0.001f);
		TestEqual(TEXT("Unlocked traits count is 1"), TransmuteEngine->GetUnlockedTraitsCount(), 1);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST CAMPFIRE SAVEGAME ADAPTER
	// -----------------------------------------------------------------------------------
	{
		UAshenCampfireSaveGameAdapter* SaveAdapter = NewObject<UAshenCampfireSaveGameAdapter>();

		SaveAdapter->PackageCampfireData(12, 4, 18);
		TestTrue(TEXT("HasSavedData is true"), SaveAdapter->HasSavedData());

		int32 RestoredRests = 0;
		int32 RestoredTraits = 0;
		int32 RestoredNotes = 0;
		const bool bSuccess = SaveAdapter->RestoreCampfireData(RestoredRests, RestoredTraits, RestoredNotes);

		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestEqual(TEXT("Total rests restored"), RestoredRests, 12);
		TestEqual(TEXT("Unlocked traits restored"), RestoredTraits, 4);
		TestEqual(TEXT("Discovered notes restored"), RestoredNotes, 18);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
