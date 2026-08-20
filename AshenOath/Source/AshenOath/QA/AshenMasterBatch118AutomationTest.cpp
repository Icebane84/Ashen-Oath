// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Narrative/AshenCanonicalPromiseTypes.h"
#include "Narrative/AshenPromiseLedgerComponent.h"
#include "Narrative/AshenSemanticContextMatcherComponent.h"
#include "Narrative/AshenRetroactiveMarginaliaInscriberComponent.h"
#include "Core/AshenPromiseSaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch118AutomationTest,
	"AshenOath.Narrative.MasterBatch118_CanonicalPromises",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch118AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST CANONICAL PROMISE REGISTRATION & STATUS LIFECYCLE
	// -----------------------------------------------------------------------------------
	{
		UAshenPromiseLedgerComponent* Ledger = NewObject<UAshenPromiseLedgerComponent>();

		const FGameplayTag CrisisTag = FGameplayTag::RequestGameplayTag(FName(TEXT("Combat.Retreat.Sanctuary")), false);
		const FCanonicalPromiseRecord Promise1 = Ledger->RegisterPromise(
			FName(TEXT("Garrett")),
			TEXT("I'll get you home."),
			EPromiseDomainScope::PersonalCompanion,
			CrisisTag);

		TestEqual(TEXT("Total promise count is 1"), Ledger->GetTotalPromiseCount(), 1);
		TestEqual(TEXT("Promise status is Active"), Promise1.Status, EPromiseResolutionStatus::Active);

		// Update to Fulfilled
		const bool bUpdated = Ledger->UpdatePromiseStatus(Promise1.PromiseId, EPromiseResolutionStatus::Fulfilled);
		TestTrue(TEXT("Status updated to Fulfilled"), bUpdated);
		TestEqual(TEXT("Active promise count is 0"), Ledger->GetActivePromises().Num(), 0);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST SEMANTIC CONTEXT MATCHER IN CRISIS MOMENTS
	// -----------------------------------------------------------------------------------
	{
		UAshenSemanticContextMatcherComponent* Matcher = NewObject<UAshenSemanticContextMatcherComponent>();

		FCanonicalPromiseRecord Promise;
		Promise.Status = EPromiseResolutionStatus::Active;
		Promise.TargetCompanionName = FName(TEXT("Garrett"));
		Promise.TriggerContextTag = FGameplayTag::RequestGameplayTag(FName(TEXT("Crisis.Cataclysm.Collapse")), false);

		// Case A: Matching crisis tag and companion
		const FGameplayTag MatchingTag = FGameplayTag::RequestGameplayTag(FName(TEXT("Crisis.Cataclysm.Collapse")), false);
		const bool bMatch = Matcher->MatchesCrisisContext(Promise, MatchingTag, FName(TEXT("Garrett")));
		TestTrue(TEXT("Crisis context matches active promise"), bMatch);

		// Case B: Mismatched companion
		const bool bWrongCompanion = Matcher->MatchesCrisisContext(Promise, MatchingTag, FName(TEXT("Serafina")));
		TestFalse(TEXT("Wrong companion does not match"), bWrongCompanion);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST RETROACTIVE UNNOTIFIED MARGINALIA INSCRIBER
	// -----------------------------------------------------------------------------------
	{
		UAshenRetroactiveMarginaliaInscriberComponent* Inscriber = NewObject<UAshenRetroactiveMarginaliaInscriberComponent>();

		// Serafina secretly writes on Page 4 ("He looked afraid")
		const FRetroactiveMarginaliaEntry Entry1 = Inscriber->InscribeMarginalia(
			4,
			FName(TEXT("Serafina")),
			TEXT("You were not alone."),
			EMarginaliaInkMedium::SerafinaGoldenInk);

		TestEqual(TEXT("Total marginalia count is 1"), Inscriber->GetTotalMarginaliaCount(), 1);
		TestFalse(TEXT("Annotation is undiscovered initially"), Entry1.bDiscoveredByPlayer);

		// Query Page 4
		const TArray<FRetroactiveMarginaliaEntry> PageEntries = Inscriber->GetMarginaliaForPage(4);
		TestEqual(TEXT("Page 4 contains 1 marginalia entry"), PageEntries.Num(), 1);
		TestEqual(TEXT("Author is Serafina"), PageEntries[0].InscribingAuthor, FName(TEXT("Serafina")));
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST PROMISE SAVEGAME ADAPTER
	// -----------------------------------------------------------------------------------
	{
		UAshenPromiseSaveGameAdapter* SaveAdapter = NewObject<UAshenPromiseSaveGameAdapter>();

		SaveAdapter->PackagePromiseData(3, 5, 8);
		TestTrue(TEXT("HasSavedData is true"), SaveAdapter->HasSavedData());

		int32 RestoredActive = 0;
		int32 RestoredFulfilled = 0;
		int32 RestoredMarginalia = 0;
		const bool bSuccess = SaveAdapter->RestorePromiseData(RestoredActive, RestoredFulfilled, RestoredMarginalia);

		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestEqual(TEXT("Active promises restored"), RestoredActive, 3);
		TestEqual(TEXT("Fulfilled promises restored"), RestoredFulfilled, 5);
		TestEqual(TEXT("Marginalia count restored"), RestoredMarginalia, 8);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
