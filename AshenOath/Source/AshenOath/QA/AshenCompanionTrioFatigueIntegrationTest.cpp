// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Combat/AshenCombatCharacter.h"
#include "Companions/AshenCompanionFatigueSubsystem.h"
#include "Companions/AshenTrioPartySpawnerComponent.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCompanionTrioFatigueIntegrationTest,
	"AshenOath.Convergence.Pass3_CompanionTrioFatigueLoop",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenCompanionTrioFatigueIntegrationTest::RunTest(const FString& Parameters)
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

	UAshenCompanionFatigueSubsystem* FatigueSubsystem = GameInstance->GetSubsystem<UAshenCompanionFatigueSubsystem>();
	TestNotNull(TEXT("UAshenCompanionFatigueSubsystem exists in GameInstance"), FatigueSubsystem);
	if (!FatigueSubsystem)
	{
		return false;
	}

	// -----------------------------------------------------------------------------------
	// 1. TEST INITIAL FATIGUE STATE & ZERO VULNERABILITY
	// -----------------------------------------------------------------------------------
	FatigueSubsystem->ResetAllFatigue();
	TestNearlyEqual(TEXT("Garrett initial fatigue is 0.0"), FatigueSubsystem->GarrettFatigue, 0.0f, 0.01f);
	TestNearlyEqual(TEXT("Serafina initial fatigue is 0.0"), FatigueSubsystem->SerafinaFatigue, 0.0f, 0.01f);
	TestNearlyEqual(TEXT("Kaelen initial fatigue is 0.0"), FatigueSubsystem->KaelenFatigue, 0.0f, 0.01f);

	TestFalse(TEXT("Garrett initially not vulnerable"), FatigueSubsystem->IsCompanionVulnerable(FName("Garrett")));
	TestFalse(TEXT("Serafina initially not vulnerable"), FatigueSubsystem->IsCompanionVulnerable(FName("Serafina")));

	// -----------------------------------------------------------------------------------
	// 2. TEST GARRETT TACTICAL ASSIST ACCUMULATION & VULNERABILITY THRESHOLD
	// -----------------------------------------------------------------------------------
	{
		// 1 assist: +0.25
		FatigueSubsystem->AccumulateFatigue(FName("Garrett"), 0.25f);
		TestNearlyEqual(TEXT("Garrett fatigue after 1 assist is 0.25"), FatigueSubsystem->GarrettFatigue, 0.25f, 0.01f);
		TestFalse(TEXT("Garrett not vulnerable at 0.25"), FatigueSubsystem->IsCompanionVulnerable(FName("Garrett")));

		// 2 more assists: +0.50 -> 0.75 (Crosses 0.70 threshold)
		FatigueSubsystem->AccumulateFatigue(FName("Garrett"), 0.50f);
		TestNearlyEqual(TEXT("Garrett fatigue after 3 assists is 0.75"), FatigueSubsystem->GarrettFatigue, 0.75f, 0.01f);
		TestTrue(TEXT("Garrett is vulnerable at >= 0.70 fatigue"), FatigueSubsystem->IsCompanionVulnerable(FName("Garrett")));
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST SERAFINA HEALING PRAYER FATIGUE ACCUMULATION
	// -----------------------------------------------------------------------------------
	{
		// 4 prayers: +0.20 * 4 = 0.80
		FatigueSubsystem->AccumulateFatigue(FName("Serafina"), 0.80f);
		TestNearlyEqual(TEXT("Serafina fatigue after 4 prayers is 0.80"), FatigueSubsystem->SerafinaFatigue, 0.80f, 0.01f);
		TestTrue(TEXT("Serafina is vulnerable at >= 0.70 fatigue"), FatigueSubsystem->IsCompanionVulnerable(FName("Serafina")));
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST DYNAMIC TIME RECOVERY
	// -----------------------------------------------------------------------------------
	{
		// Recover 10.0 seconds of decay (0.015 * 10 = 0.15 recovery)
		FatigueSubsystem->RecoverFatigue(10.0f);
		TestNearlyEqual(TEXT("Garrett fatigue after 10s recovery is 0.60"), FatigueSubsystem->GarrettFatigue, 0.60f, 0.02f);
		TestFalse(TEXT("Garrett no longer vulnerable below 0.70"), FatigueSubsystem->IsCompanionVulnerable(FName("Garrett")));
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST CAMPFIRE / SANCTUARY REST PURGE
	// -----------------------------------------------------------------------------------
	{
		FatigueSubsystem->ResetAllFatigue();
		TestNearlyEqual(TEXT("Garrett fatigue after rest is 0.0"), FatigueSubsystem->GarrettFatigue, 0.0f, 0.01f);
		TestNearlyEqual(TEXT("Serafina fatigue after rest is 0.0"), FatigueSubsystem->SerafinaFatigue, 0.0f, 0.01f);
		TestFalse(TEXT("Garrett not vulnerable after rest"), FatigueSubsystem->IsCompanionVulnerable(FName("Garrett")));
		TestFalse(TEXT("Serafina not vulnerable after rest"), FatigueSubsystem->IsCompanionVulnerable(FName("Serafina")));
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
