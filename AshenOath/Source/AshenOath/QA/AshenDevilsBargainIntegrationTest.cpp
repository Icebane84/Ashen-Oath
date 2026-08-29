// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Combat/AshenCombatCharacter.h"
#include "Combat/AshenDevilsBargainTransformationSubsystem.h"
#include "Companions/AshenDevilsBargainTrustAtrophyDirector.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenDevilsBargainIntegrationTest,
	"AshenOath.Convergence.Pass4_DevilsBargainCrisisAndAtrophyLoop",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenDevilsBargainIntegrationTest::RunTest(const FString& Parameters)
{
	UWorld* World = nullptr;
	const TIndirectArray<FWorldContext>& WorldContexts = GEngine->GetWorldContexts();
	for (const FWorldContext& Context : WorldContexts)
	{
		if (Context.World() && Context.World()->IsGameWorld())
		{
			World = Context.World();
			break;
		}
	}
	if (!World && WorldContexts.Num() > 0)
	{
		World = WorldContexts[0].World();
	}

	TestNotNull(TEXT("World context exists"), World);
	if (!World)
	{
		return false;
	}

	UGameInstance* GameInstance = World->GetGameInstance();
	TestNotNull(TEXT("GameInstance exists"), GameInstance);
	if (!GameInstance)
	{
		return false;
	}

	UAshenDevilsBargainTransformationSubsystem* BargainSubsystem = GameInstance->GetSubsystem<UAshenDevilsBargainTransformationSubsystem>();
	TestNotNull(TEXT("UAshenDevilsBargainTransformationSubsystem exists"), BargainSubsystem);

	UAshenDevilsBargainTrustAtrophyDirector* AtrophyDirector = GameInstance->GetSubsystem<UAshenDevilsBargainTrustAtrophyDirector>();
	TestNotNull(TEXT("UAshenDevilsBargainTrustAtrophyDirector exists"), AtrophyDirector);

	if (!BargainSubsystem || !AtrophyDirector)
	{
		return false;
	}

	// -----------------------------------------------------------------------------------
	// 1. TEST INITIAL UNCHAINED & TRUST STATES
	// -----------------------------------------------------------------------------------
	TestFalse(TEXT("Unchained berserk initially inactive"), BargainSubsystem->bIsUnchainedBerserkActive);
	TestNearlyEqual(TEXT("Initial attack speed multiplier is 1.0"), BargainSubsystem->ActiveAttackSpeedMultiplier, 1.0f, 0.01f);
	TestNearlyEqual(TEXT("Initial companion trust is 100.0%"), AtrophyDirector->ActivePartyTrustLevel, 100.0f, 0.01f);

	// -----------------------------------------------------------------------------------
	// 2. TEST ACCEPTING DEVIL'S BARGAIN & CASUAL REACTION CASCADE
	// -----------------------------------------------------------------------------------
	{
		BargainSubsystem->AcceptDevilsBargain();

		TestTrue(TEXT("Unchained berserk active after bargain accepted"), BargainSubsystem->bIsUnchainedBerserkActive);
		TestNearlyEqual(TEXT("Attack speed surged to 3.0x (+200%)"), BargainSubsystem->ActiveAttackSpeedMultiplier, 3.0f, 0.01f);
		TestNearlyEqual(TEXT("Companion trust atrophied by -25% (now 75.0%)"), AtrophyDirector->ActivePartyTrustLevel, 75.0f, 0.01f);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
