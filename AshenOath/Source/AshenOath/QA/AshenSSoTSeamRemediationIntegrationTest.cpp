// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Companions/AshenTrustAccumulationComponent.h"
#include "Combat/AshenOath_SanityComponent.h"
#include "Combat/AshenAbilitySystemComponent.h"
#include "Soul/AshenSoulPublisher.h"
#include "Soul/AshenSoulTypes.h"
#include "Soul/AshenSoulStateVector.h"

#if WITH_DEV_AUTOMATION_TESTS

// -----------------------------------------------------------------------------
// 1. INTEGRATION TEST: TrustAccumulationComponent SSoT Synchronization
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenTrustAccumulationSSoTIntegrationTest,
	"AshenOath.Remediation.Integration.TrustAccumulationSSoT",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenTrustAccumulationSSoTIntegrationTest::RunTest(const FString& Parameters)
{
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("TrustSSoTTestWorld"));
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
			// Reset publisher state
			FSoulStateVector Baseline;
			Baseline.GarrettTrust = 0.50f;
			Baseline.SerafinaTrust = 0.50f;
			Publisher->CommitStateDirect(Baseline);

			UAshenTrustAccumulationComponent* TrustComp = NewObject<UAshenTrustAccumulationComponent>(World);
			TestNotNull(TEXT("Trust component created"), TrustComp);

			if (TrustComp)
			{
				// Initial score query (0.50 * 100 = 50.0)
				TestEqual(TEXT("Initial Garrett trust is 50.0"), TrustComp->GetTrustScore(FName("Garrett")), 50.0f);

				// Add trust (+20.0)
				TrustComp->AddTrust(FName("Garrett"), 20.0f);

				// Assert publisher received canonical delta (0.50 + 0.20 = 0.70)
				const FSoulStateVector UpdatedState = Publisher->GetSoulState();
				TestEqual(TEXT("Canonical GarrettTrust updated to 0.70"), UpdatedState.GarrettTrust, 0.70f);
				TestEqual(TEXT("TrustComp reports updated score 70.0"), TrustComp->GetTrustScore(FName("Garrett")), 70.0f);
			}
		}
	}

	World->DestroyWorld(false);
	return true;
}

// -----------------------------------------------------------------------------
// 2. INTEGRATION TEST: SanityComponent ASC & Publisher Routing
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSanityComponentSSoTIntegrationTest,
	"AshenOath.Remediation.Integration.SanityComponentSSoT",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenSanityComponentSSoTIntegrationTest::RunTest(const FString& Parameters)
{
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("SanitySSoTTestWorld"));
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
			// Reset publisher state
			FSoulStateVector Baseline;
			Baseline.Resolve = 0.80f;
			Baseline.Corruption = 0.0f;
			Baseline.IntegrationDebt = 0.0f;
			Baseline.Isolation = 0.0f;
			Publisher->CommitStateDirect(Baseline);

			UAshenOath_SanityComponent* SanityComp = NewObject<UAshenOath_SanityComponent>(World);
			TestNotNull(TEXT("Sanity component created"), SanityComp);

			if (SanityComp)
			{
				// Suffer mental damage (40.0)
				SanityComp->SufferMentalDamage(40.0f);

				// Assert publisher received canonical Dysregulation (N/Isolation) & Corruption (C)
				const FSoulStateVector PostDamageState = Publisher->GetSoulState();
				TestTrue(TEXT("Mental damage committed canonical Dysregulation (N)"), PostDamageState.Isolation > 0.15f);
				TestTrue(TEXT("Mental damage committed canonical Corruption (C)"), PostDamageState.Corruption > 0.10f);
			}
		}
	}

	World->DestroyWorld(false);
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
