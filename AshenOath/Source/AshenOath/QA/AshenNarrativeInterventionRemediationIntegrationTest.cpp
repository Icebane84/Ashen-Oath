// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Narrative/AshenCampfireContemplationDirectorComponent.h"
#include "Narrative/AshenMultiAuthorMarginaliaEvaluator.h"
#include "Combat/AshenMartyrSolitaryParryGASAbility.h"
#include "Combat/AshenTransferenceInterventionInterceptGASAbility.h"
#include "Soul/AshenSoulPublisher.h"
#include "Soul/AshenSoulTypes.h"
#include "Soul/AshenSoulStateVector.h"

#if WITH_DEV_AUTOMATION_TESTS

// -----------------------------------------------------------------------------
// 1. INTEGRATION TEST: Campfire Rest SSoT State Healing & Fatigue Reset
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCampfireRestSSoTIntegrationTest,
	"AshenOath.Remediation.Integration.CampfireRestSSoT",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenCampfireRestSSoTIntegrationTest::RunTest(const FString& Parameters)
{
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("CampfireSSoTTestWorld"));
	TestNotNull(TEXT("Transient World created"), World);

	if (!World)
	{
		return false;
	}

	UGameInstance* GameInstance = NewObject<UGameInstance>(World);
	TestNotNull(TEXT("Transient GameInstance created"), GameInstance);

	if (GameInstance)
	{
		GameInstance->Init();
		World->SetGameInstance(GameInstance);

		UAshenSoulPublisher* Publisher = GameInstance->GetSubsystem<UAshenSoulPublisher>();
		TestNotNull(TEXT("Soul Publisher acquired"), Publisher);

		if (Publisher)
		{
			// Setup high dysregulation (0.60) and debt (0.50)
			FSoulStateVector Baseline;
			Baseline.Resolve = 0.30f;
			Baseline.Isolation = 0.60f; // High Dysregulation
			Baseline.IntegrationDebt = 0.50f;
			Baseline.Corruption = 0.40f;
			Publisher->CommitStateDirect(Baseline);

			UAshenCampfireContemplationDirectorComponent* CampfireComp = NewObject<UAshenCampfireContemplationDirectorComponent>(World);
			TestNotNull(TEXT("Campfire Comp created"), CampfireComp);

			if (CampfireComp)
			{
				// 5.0 seconds rest restores 0.25
				const float Restored = CampfireComp->RestAtCampfire(5.0f);
				TestEqual(TEXT("Restored sanity is 0.25"), Restored, 0.25f);

				// Assert publisher received healing
				const FSoulStateVector PostRestState = Publisher->GetSoulState();
				TestTrue(TEXT("Resolve increased after campfire rest"), PostRestState.Resolve > 0.30f);
				TestTrue(TEXT("Dysregulation (Isolation) decreased after rest"), PostRestState.Isolation < 0.60f);
			}
		}
	}

	World->DestroyWorld(false);
	return true;
}

// -----------------------------------------------------------------------------
// 2. INTEGRATION TEST: Multi-Author Marginalia SSoT Gating
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMultiAuthorMarginaliaSSoTIntegrationTest,
	"AshenOath.Remediation.Integration.MultiAuthorMarginaliaSSoT",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMultiAuthorMarginaliaSSoTIntegrationTest::RunTest(const FString& Parameters)
{
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("MarginaliaSSoTTestWorld"));
	TestNotNull(TEXT("Transient World created"), World);

	if (!World)
	{
		return false;
	}

	UGameInstance* GameInstance = NewObject<UGameInstance>(World);
	TestNotNull(TEXT("Transient GameInstance created"), GameInstance);

	if (GameInstance)
	{
		GameInstance->Init();
		World->SetGameInstance(GameInstance);

		UAshenSoulPublisher* Publisher = GameInstance->GetSubsystem<UAshenSoulPublisher>();
		TestNotNull(TEXT("Soul Publisher acquired"), Publisher);

		if (Publisher)
		{
			// Garrett Trust = 0.50 (>= 0.40 -> Unlocked), Serafina Trust = 0.30 (< 0.70 -> Locked)
			FSoulStateVector State;
			State.GarrettTrust = 0.50f;
			State.SerafinaTrust = 0.30f;
			Publisher->CommitStateDirect(State);

			UAshenMultiAuthorMarginaliaEvaluator* Marginalia = NewObject<UAshenMultiAuthorMarginaliaEvaluator>(World);
			TestNotNull(TEXT("Marginalia Evaluator created"), Marginalia);

			if (Marginalia)
			{
				TestTrue(TEXT("Kaelen notes always unlocked"), Marginalia->IsAuthorMarginaliaUnlocked(EForensicMarginaliaAuthor::Kaelen));
				TestTrue(TEXT("Garrett notes unlocked at 0.50 trust"), Marginalia->IsAuthorMarginaliaUnlocked(EForensicMarginaliaAuthor::Garrett));
				TestFalse(TEXT("Serafina notes locked at 0.30 trust"), Marginalia->IsAuthorMarginaliaUnlocked(EForensicMarginaliaAuthor::Serafina));
			}
		}
	}

	World->DestroyWorld(false);
	return true;
}

// -----------------------------------------------------------------------------
// 3. INTEGRATION TEST: Martyr Parry & Transference Intervention SSoT Commits
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenTacticalInterventionSSoTIntegrationTest,
	"AshenOath.Remediation.Integration.TacticalInterventionSSoT",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenTacticalInterventionSSoTIntegrationTest::RunTest(const FString& Parameters)
{
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("TacticalInterventionTestWorld"));
	TestNotNull(TEXT("Transient World created"), World);

	if (!World)
	{
		return false;
	}

	UGameInstance* GameInstance = NewObject<UGameInstance>(World);
	TestNotNull(TEXT("Transient GameInstance created"), GameInstance);

	if (GameInstance)
	{
		GameInstance->Init();
		World->SetGameInstance(GameInstance);

		UAshenSoulPublisher* Publisher = GameInstance->GetSubsystem<UAshenSoulPublisher>();
		TestNotNull(TEXT("Soul Publisher acquired"), Publisher);

		if (Publisher)
		{
			// Reset trust
			FSoulStateVector State;
			State.GarrettTrust = 0.50f;
			State.SerafinaTrust = 0.50f;
			Publisher->CommitStateDirect(State);

			// Test 1: Martyr Parry reduces trust by 0.05
			UAshenMartyrSolitaryParryGASAbility* ParryAbility = NewObject<UAshenMartyrSolitaryParryGASAbility>(World);
			TestNotNull(TEXT("Parry Ability created"), ParryAbility);

			if (ParryAbility)
			{
				float OutPenalty = 0.0f;
				ParryAbility->ExecuteMartyrParry(OutPenalty);

				const FSoulStateVector PostParryState = Publisher->GetSoulState();
				TestEqual(TEXT("Garrett trust reduced to 0.45 after solitary parry"), PostParryState.GarrettTrust, 0.45f);
			}

			// Test 2: Transference Intervention increases trust by 0.20
			UAshenTransferenceInterventionInterceptGASAbility* InterceptAbility = NewObject<UAshenTransferenceInterventionInterceptGASAbility>(World);
			TestNotNull(TEXT("Intercept Ability created"), InterceptAbility);

			if (InterceptAbility)
			{
				InterceptAbility->ActivateAbility(FGameplayAbilitySpecHandle(), nullptr, FGameplayAbilityActivationInfo(), nullptr);

				const FSoulStateVector PostInterceptState = Publisher->GetSoulState();
				TestEqual(TEXT("Garrett trust increased to 0.65 after intervention"), PostInterceptState.GarrettTrust, 0.65f);
			}
		}
	}

	World->DestroyWorld(false);
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
