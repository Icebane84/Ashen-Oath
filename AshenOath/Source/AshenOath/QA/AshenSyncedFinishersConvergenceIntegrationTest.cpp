// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Combat/AshenCombatCharacter.h"
#include "Combat/AshenOath_HealthComponent.h"
#include "Combat/AshenOath_PoiseComponent.h"
#include "Combat/GA_KaelenGarrettSyncedShadowStrike.h"
#include "Combat/GA_KaelenSerafinaSyncedHolyBurst.h"
#include "Combat/AshenTripartiteSovereignFinisherGASAbility.h"
#include "Combat/AshenSyncFinisherBalanceDataAsset.h"
#include "Companions/AshenCompanionFatigueSubsystem.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSyncedFinishersConvergenceIntegrationTest,
	"AshenOath.Convergence.Finishers.SyncedAndTripartiteZenith",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenSyncedFinishersConvergenceIntegrationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. SETUP TRANSIENT WORLD & GAME INSTANCE
	// -----------------------------------------------------------------------------------
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("SyncedFinishersTestWorld"));
	TestNotNull(TEXT("Transient World created"), World);
	if (!World)
	{
		return false;
	}

	UGameInstance* GameInstance = NewObject<UGameInstance>(World);
	GameInstance->Init();
	World->SetGameInstance(GameInstance);

	UAshenCompanionFatigueSubsystem* FatigueSubsystem = GameInstance->GetSubsystem<UAshenCompanionFatigueSubsystem>();
	TestNotNull(TEXT("UAshenCompanionFatigueSubsystem exists on GameInstance"), FatigueSubsystem);

	// Spawn Player Character (Kaelen)
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	AAshenCombatCharacter* Kaelen = World->SpawnActor<AAshenCombatCharacter>(AAshenCombatCharacter::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
	TestNotNull(TEXT("Kaelen combat character spawned"), Kaelen);

	// Spawn Boss Target Dummy
	AAshenCombatCharacter* BossDummy = World->SpawnActor<AAshenCombatCharacter>(AAshenCombatCharacter::StaticClass(), FVector(200, 0, 0), FRotator::ZeroRotator, SpawnParams);
	TestNotNull(TEXT("Boss target dummy spawned"), BossDummy);

	UAshenOath_HealthComponent* KaelenHealth = Kaelen ? Kaelen->FindComponentByClass<UAshenOath_HealthComponent>() : nullptr;
	UAshenOath_HealthComponent* BossHealth = BossDummy ? BossDummy->FindComponentByClass<UAshenOath_HealthComponent>() : nullptr;
	UAshenOath_PoiseComponent* BossPoise = BossDummy ? BossDummy->FindComponentByClass<UAshenOath_PoiseComponent>() : nullptr;

	TestNotNull(TEXT("Kaelen health component exists"), KaelenHealth);
	TestNotNull(TEXT("Boss health component exists"), BossHealth);
	TestNotNull(TEXT("Boss poise component exists"), BossPoise);

	// -----------------------------------------------------------------------------------
	// 2. TEST KAELEN + GARRETT SYNCED SHADOW STRIKE
	// -----------------------------------------------------------------------------------
	if (Kaelen && BossDummy && BossHealth && FatigueSubsystem)
	{
		BossHealth->SetMaxHealth(5000.0f);
		BossHealth->ReceiveDamage(0.0f, nullptr);
		FatigueSubsystem->ResetAllFatigue();

		UGA_KaelenGarrettSyncedShadowStrike* ShadowStrike = NewObject<UGA_KaelenGarrettSyncedShadowStrike>(Kaelen);
		TestNotNull(TEXT("Shadow Strike ability instantiated"), ShadowStrike);

		const bool bShadowStrikeSuccess = ShadowStrike->ExecuteSyncedShadowStrike(Kaelen, BossDummy);
		TestTrue(TEXT("Shadow Strike executed successfully"), bShadowStrikeSuccess);

		// Assert 600 damage dealt
		TestNearlyEqual(TEXT("Boss took 600 damage from Shadow Strike (remaining: 4400)"), BossHealth->GetCurrentHealth(), 4400.0f, 0.1f);

		// Assert Garrett fatigue accumulated +0.25
		TestNearlyEqual(TEXT("Garrett fatigue is 0.25"), FatigueSubsystem->GarrettFatigue, 0.25f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST KAELEN + SERAFINA SYNCED HOLY BURST
	// -----------------------------------------------------------------------------------
	if (Kaelen && KaelenHealth && BossDummy && BossHealth && FatigueSubsystem)
	{
		KaelenHealth->SetMaxHealth(500.0f);
		KaelenHealth->ReceiveDamage(400.0f, nullptr); // Health is 100.0

		UGA_KaelenSerafinaSyncedHolyBurst* HolyBurst = NewObject<UGA_KaelenSerafinaSyncedHolyBurst>(Kaelen);
		TestNotNull(TEXT("Holy Burst ability instantiated"), HolyBurst);

		const bool bHolyBurstSuccess = HolyBurst->ExecuteSyncedHolyBurst(Kaelen);
		TestTrue(TEXT("Holy Burst executed successfully"), bHolyBurstSuccess);

		// Assert 500 damage dealt to Boss (4400 -> 3900)
		TestNearlyEqual(TEXT("Boss took 500 Holy damage (remaining: 3900)"), BossHealth->GetCurrentHealth(), 3900.0f, 0.1f);

		// Assert Kaelen healed +50 HP (100 -> 150)
		TestNearlyEqual(TEXT("Kaelen healed +50 HP (current: 150)"), KaelenHealth->GetCurrentHealth(), 150.0f, 0.1f);

		// Assert Serafina fatigue accumulated +0.20
		TestNearlyEqual(TEXT("Serafina fatigue is 0.20"), FatigueSubsystem->SerafinaFatigue, 0.20f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST 3-WAY TRIPARTITE ZENITH FINISHER & DATA ASSET OVERRIDE
	// -----------------------------------------------------------------------------------
	if (Kaelen && BossDummy && BossHealth && BossPoise && FatigueSubsystem)
	{
		BossPoise->SetMaxPoise(500.0f);
		BossPoise->ResetPoise();

		UAshenTripartiteSovereignFinisherGASAbility* ZenithFinisher = NewObject<UAshenTripartiteSovereignFinisherGASAbility>(Kaelen);
		TestNotNull(TEXT("Zenith Finisher ability instantiated"), ZenithFinisher);

		// Create DataAsset with 3500.0 damage tuning override
		UAshenSyncFinisherBalanceDataAsset* BalanceAsset = NewObject<UAshenSyncFinisherBalanceDataAsset>(World);
		BalanceAsset->TripartiteZenithParams.BaseDamage = 3500.0f;
		BalanceAsset->TripartiteZenithParams.PoiseDamage = 500.0f;
		BalanceAsset->TripartiteZenithParams.CompanionFatigueCost = 0.35f;
		ZenithFinisher->BalanceDataAsset = BalanceAsset;

		const bool bZenithSuccess = ZenithFinisher->ExecuteTripartiteFinisher(Kaelen, BossDummy);
		TestTrue(TEXT("Tripartite Zenith Finisher executed successfully"), bZenithSuccess);

		// Assert Boss took 3500 tuned damage (3900 -> 400)
		TestNearlyEqual(TEXT("Boss took 3500 DataAsset tuned damage (remaining: 400)"), BossHealth->GetCurrentHealth(), 400.0f, 0.1f);

		// Assert Boss Poise shattered (500 -> 0)
		TestNearlyEqual(TEXT("Boss Poise shattered to 0.0"), BossPoise->GetCurrentPoise(), 0.0f, 0.1f);

		// Assert Fatigue accumulated to both companions (+0.35 each)
		TestNearlyEqual(TEXT("Garrett fatigue is 0.60 (0.25 + 0.35)"), FatigueSubsystem->GarrettFatigue, 0.60f, 0.01f);
		TestNearlyEqual(TEXT("Serafina fatigue is 0.55 (0.20 + 0.35)"), FatigueSubsystem->SerafinaFatigue, 0.55f, 0.01f);
	}

	// Cleanup
	if (Kaelen) Kaelen->Destroy();
	if (BossDummy) BossDummy->Destroy();
	World->DestroyWorld(false);
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
