// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Narrative/AshenJournalTypes.h"
#include "Narrative/AshenForensicJournalSubsystem.h"
#include "Narrative/AshenMultiAuthorMarginaliaEvaluator.h"
#include "Narrative/AshenSootProvenanceLedgerEvaluator.h"
#include "Narrative/AshenCampfireContemplationDirectorComponent.h"
#include "Narrative/AshenJournalHapticBridge.h"
#include "Core/AshenJournalSaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch141AutomationTest,
	"AshenOath.Narrative.MasterBatch141_GrandCampaignForensicCampfireJournal",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch141AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST MULTI-AUTHOR MARGINALIA TRUST GATING
	// -----------------------------------------------------------------------------------
	{
		UAshenMultiAuthorMarginaliaEvaluator* MargEvaluator = NewObject<UAshenMultiAuthorMarginaliaEvaluator>();

		// Kaelen always unlocked
		TestTrue(TEXT("Kaelen is unlocked at 0% trust"), MargEvaluator->IsAuthorMarginaliaUnlocked(EForensicMarginaliaAuthor::Kaelen, 0.0f));

		// Garrett requires >= 0.40 trust
		TestFalse(TEXT("Garrett locked at 0.30 trust"), MargEvaluator->IsAuthorMarginaliaUnlocked(EForensicMarginaliaAuthor::Garrett, 0.30f));
		TestTrue(TEXT("Garrett unlocked at 0.50 trust"), MargEvaluator->IsAuthorMarginaliaUnlocked(EForensicMarginaliaAuthor::Garrett, 0.50f));

		// Serafina requires >= 0.70 trust
		TestFalse(TEXT("Serafina locked at 0.65 trust"), MargEvaluator->IsAuthorMarginaliaUnlocked(EForensicMarginaliaAuthor::Serafina, 0.65f));
		TestTrue(TEXT("Serafina unlocked at 0.85 trust"), MargEvaluator->IsAuthorMarginaliaUnlocked(EForensicMarginaliaAuthor::Serafina, 0.85f));
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST SOOT PROVENANCE LEDGER EVALUATION
	// -----------------------------------------------------------------------------------
	{
		UAshenSootProvenanceLedgerEvaluator* SootEvaluator = NewObject<UAshenSootProvenanceLedgerEvaluator>();

		TArray<float> SootArray = { 10.0f, 15.0f, 20.0f, 25.0f, 30.0f };
		const float TotalSoot = SootEvaluator->CalculateTotalCampaignSoot(SootArray);
		TestNearlyEqual(TEXT("Total campaign soot is 100 microns"), TotalSoot, 100.0f, 0.01f);

		// Luster evaluation: 25 / 100 -> 0.75 luster
		const float Luster = SootEvaluator->EvaluateWeaponLuster(25.0f, 100.0f);
		TestNearlyEqual(TEXT("Weapon luster is 0.75"), Luster, 0.75f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST CAMPFIRE CONTEMPLATION REST
	// -----------------------------------------------------------------------------------
	{
		UAshenCampfireContemplationDirectorComponent* Director = NewObject<UAshenCampfireContemplationDirectorComponent>();

		// 5 seconds rest -> 0.25 (25% sanity restored)
		const float Restored = Director->RestAtCampfire(5.0f);
		TestNearlyEqual(TEXT("5s rest restores 0.25 sanity"), Restored, 0.25f, 0.01f);

		// Mood evaluation: High Trust -> SharedCatharsis
		const ECampfireReflectionMood Mood1 = Director->EvaluateCampfireMood(0.85f, 0.10f);
		TestEqual(TEXT("High trust yields SharedCatharsis"), Mood1, ECampfireReflectionMood::SharedCatharsis);

		// Mood evaluation: High Debt -> SomberSilence
		const ECampfireReflectionMood Mood2 = Director->EvaluateCampfireMood(0.50f, 0.80f);
		TestEqual(TEXT("High debt yields SomberSilence"), Mood2, ECampfireReflectionMood::SomberSilence);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST DUALSENSE JOURNAL HAPTICS
	// -----------------------------------------------------------------------------------
	{
		UAshenJournalHapticBridge* HapticBridge = NewObject<UAshenJournalHapticBridge>();
		float PageSnap = 0.0f;
		float QuillVibe = 0.0f;
		float EmberRumble = 0.0f;

		HapticBridge->EvaluateJournalHaptics(true, true, ECampfireReflectionMood::SharedCatharsis, PageSnap, QuillVibe, EmberRumble);
		TestNearlyEqual(TEXT("Page-turn snap is 0.70"), PageSnap, 0.70f, 0.01f);
		TestNearlyEqual(TEXT("Quill vibration is 0.45"), QuillVibe, 0.45f, 0.01f);
		TestNearlyEqual(TEXT("Ember rumble is 0.60"), EmberRumble, 0.60f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST SAVEGAME PERSISTENCE
	// -----------------------------------------------------------------------------------
	{
		UAshenJournalSaveGameAdapter* SaveAdapter = NewObject<UAshenJournalSaveGameAdapter>();
		SaveAdapter->PackageJournalState(10, 145.0f, true, true);
		TestTrue(TEXT("HasSavedData is true"), SaveAdapter->HasSavedData());

		int32 RestoredUnlocked = 0;
		float RestoredSoot = 0.0f;
		bool bRestoredGarrett = false;
		bool bRestoredSerafina = false;

		const bool bSuccess = SaveAdapter->RestoreJournalState(RestoredUnlocked, RestoredSoot, bRestoredGarrett, bRestoredSerafina);
		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestEqual(TEXT("10 unlocked scenarios restored"), RestoredUnlocked, 10);
		TestNearlyEqual(TEXT("145 microns restored"), RestoredSoot, 145.0f, 0.01f);
		TestTrue(TEXT("Garrett marginalia unlocked"), bRestoredGarrett);
		TestTrue(TEXT("Serafina marginalia unlocked"), bRestoredSerafina);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
