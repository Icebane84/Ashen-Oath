// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Narrative/AshenCompanionTrustDialogueTreeAdapter.h"
#include "Companions/AshenRelationalTrustAtrophyCalculator.h"
#include "Companions/AshenRelationalTrustRecoveryCalculator.h"
#include "Soul/AshenSoulPublisher.h"
#include "Soul/AshenSoulTypes.h"
#include "Soul/AshenSoulStateVector.h"

#if WITH_DEV_AUTOMATION_TESTS

// -----------------------------------------------------------------------------
// 1. INTEGRATION TEST: Dialogue Node SSoT Trust Gating
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenDialogueTrustGatingSSoTIntegrationTest,
	"AshenOath.Remediation.Integration.DialogueTrustGatingSSoT",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenDialogueTrustGatingSSoTIntegrationTest::RunTest(const FString& Parameters)
{
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("DialogueTrustTestWorld"));
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
			// Garrett Trust = 0.50 (>= 0.40 -> Vulnerability unlocked, < 0.65 -> TraumaConfession locked)
			FSoulStateVector State;
			State.GarrettTrust = 0.50f;
			Publisher->CommitStateDirect(State);

			UAshenCompanionTrustDialogueTreeAdapter* DialogueAdapter = NewObject<UAshenCompanionTrustDialogueTreeAdapter>(World);
			TestNotNull(TEXT("Dialogue Adapter created"), DialogueAdapter);

			if (DialogueAdapter)
			{
				TestTrue(TEXT("Intro unlocked at 0.0"), DialogueAdapter->IsDialogueNodeUnlockedByTrust(FName("Garrett"), FName("Node_Intro")));
				TestTrue(TEXT("Vulnerability unlocked at 0.50 trust"), DialogueAdapter->IsDialogueNodeUnlockedByTrust(FName("Garrett"), FName("Node_Vulnerability")));
				TestFalse(TEXT("Trauma Confession locked at 0.50 trust (< 0.65)"), DialogueAdapter->IsDialogueNodeUnlockedByTrust(FName("Garrett"), FName("Node_TraumaConfession")));
			}
		}
	}

	World->DestroyWorld(false);
	return true;
}

// -----------------------------------------------------------------------------
// 2. INTEGRATION TEST: Trust Atrophy & Recovery SSoT Commits
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenTrustDynamicsSSoTIntegrationTest,
	"AshenOath.Remediation.Integration.TrustDynamicsSSoT",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenTrustDynamicsSSoTIntegrationTest::RunTest(const FString& Parameters)
{
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("TrustDynamicsTestWorld"));
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
			// Baseline Trust = 0.50
			FSoulStateVector Baseline;
			Baseline.GarrettTrust = 0.50f;
			Baseline.SerafinaTrust = 0.50f;
			Publisher->CommitStateDirect(Baseline);

			// Test 1: Trust Atrophy (Ignored 3 times -> -0.15)
			const float PostAtrophyTrust = UAshenRelationalTrustAtrophyCalculator::ApplyTrustAtrophy(FName("Garrett"), 3, World);
			TestEqual(TEXT("Garrett trust atrophied to 0.35"), PostAtrophyTrust, 0.35f);
			TestEqual(TEXT("Publisher GarrettTrust updated to 0.35"), Publisher->GetSoulState().GarrettTrust, 0.35f);

			// Test 2: Trust Recovery (Synergy 1.0 -> +0.15)
			const float PostRecoveryTrust = UAshenRelationalTrustRecoveryCalculator::ApplyTrustRecovery(FName("Garrett"), 1.0f, World);
			TestEqual(TEXT("Garrett trust recovered to 0.50"), PostRecoveryTrust, 0.50f);
			TestEqual(TEXT("Publisher GarrettTrust restored to 0.50"), Publisher->GetSoulState().GarrettTrust, 0.50f);
		}
	}

	World->DestroyWorld(false);
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
