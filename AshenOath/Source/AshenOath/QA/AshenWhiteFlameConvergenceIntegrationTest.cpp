// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Combat/AshenWhiteFlameResolutionSubsystem.h"
#include "Combat/AshenInvokeWhiteFlameGASAbility.h"
#include "Memory/AshenIntegrationDebtAccumulatorSubsystem.h"
#include "Companions/AshenCompanionFatigueSubsystem.h"
#include "Combat/AshenCombatCharacter.h"
#include "Combat/AshenOath_SanityComponent.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenWhiteFlameConvergenceIntegrationTest,
	"AshenOath.Convergence.WhiteFlame.ResolutionAndTransferenceCatharsis",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenWhiteFlameConvergenceIntegrationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. SETUP TRANSIENT WORLD & GAME INSTANCE
	// -----------------------------------------------------------------------------------
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("WhiteFlameConvergenceTestWorld"));
	TestNotNull(TEXT("Transient World created"), World);
	if (!World)
	{
		return false;
	}

	UGameInstance* GameInstance = NewObject<UGameInstance>(World);
	GameInstance->Init();
	World->SetGameInstance(GameInstance);

	UAshenWhiteFlameResolutionSubsystem* WhiteFlameSubsystem = GameInstance->GetSubsystem<UAshenWhiteFlameResolutionSubsystem>();
	TestNotNull(TEXT("UAshenWhiteFlameResolutionSubsystem exists on GameInstance"), WhiteFlameSubsystem);

	UAshenCompanionFatigueSubsystem* FatigueSubsystem = GameInstance->GetSubsystem<UAshenCompanionFatigueSubsystem>();
	TestNotNull(TEXT("UAshenCompanionFatigueSubsystem exists on GameInstance"), FatigueSubsystem);

	UAshenIntegrationDebtAccumulatorSubsystem* DebtSubsystem = World->GetSubsystem<UAshenIntegrationDebtAccumulatorSubsystem>();
	TestNotNull(TEXT("UAshenIntegrationDebtAccumulatorSubsystem exists on World"), DebtSubsystem);

	// Spawn Player Character (Kaelen)
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	AAshenCombatCharacter* Kaelen = World->SpawnActor<AAshenCombatCharacter>(AAshenCombatCharacter::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
	TestNotNull(TEXT("Kaelen combat character spawned"), Kaelen);

	UAshenOath_SanityComponent* SanityComp = Kaelen ? Kaelen->FindComponentByClass<UAshenOath_SanityComponent>() : nullptr;
	TestNotNull(TEXT("Kaelen sanity component exists"), SanityComp);

	UAshenInvokeWhiteFlameGASAbility* WhiteFlameAbility = NewObject<UAshenInvokeWhiteFlameGASAbility>(Kaelen);
	TestNotNull(TEXT("White Flame GAS ability instantiated"), WhiteFlameAbility);

	// -----------------------------------------------------------------------------------
	// 2. TEST PRIMING REJECTION ON LOW RESOLVE / LOW BURNOUT
	// -----------------------------------------------------------------------------------
	if (WhiteFlameAbility && DebtSubsystem && FatigueSubsystem)
	{
		DebtSubsystem->SetIntegrationDebt(0.85f);
		FatigueSubsystem->SetSerafinaFatigue(0.40f); // Below 0.65 threshold

		const bool bFailedAttempt = WhiteFlameAbility->InvokeWhiteFlame(Kaelen, nullptr, 0.50f, 0.40f);
		TestFalse(TEXT("White Flame invocation rejected when conditions not met"), bFailedAttempt);
		TestNearlyEqual(TEXT("Debt remains untouched on failed priming"), DebtSubsystem->GetIntegrationDebt(), 0.85f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST SUCCESSFUL INVOCATION, 100% DEBT ERADICATION, AND BURNOUT PURGE
	// -----------------------------------------------------------------------------------
	if (WhiteFlameAbility && DebtSubsystem && FatigueSubsystem && SanityComp && WhiteFlameSubsystem)
	{
		DebtSubsystem->SetIntegrationDebt(0.85f);
		FatigueSubsystem->SetSerafinaFatigue(0.80f);
		SanityComp->SetCurrentSanity(40.0f);

		const bool bSuccessfulInvoke = WhiteFlameAbility->InvokeWhiteFlame(Kaelen, nullptr, 1.0f, 0.80f);
		TestTrue(TEXT("White Flame Resolution successfully invoked"), bSuccessfulInvoke);

		// Assert 100% debt eradication
		TestNearlyEqual(TEXT("100% of integration debt eradicated"), DebtSubsystem->GetIntegrationDebt(), 0.0f, 0.001f);

		// Assert 50% Serafina burnout relief (0.80 -> 0.40)
		TestNearlyEqual(TEXT("Serafina burnout relieved by 50% (0.40)"), FatigueSubsystem->SerafinaFatigue, 0.40f, 0.01f);

		// Assert Kaelen sanity healed +50 (40.0 -> 90.0)
		TestNearlyEqual(TEXT("Kaelen sanity healed +50 points (90.0)"), SanityComp->GetCurrentSanity(), 90.0f, 0.01f);

		// Assert state is active for 12.0s
		TestTrue(TEXT("White Flame state is Active"), WhiteFlameSubsystem->CurrentResolutionPayload.State == EWhiteFlameState::Active);
		TestNearlyEqual(TEXT("Catharsis duration is 12.0s"), WhiteFlameSubsystem->CurrentResolutionPayload.DurationRemainingSeconds, 12.0f, 0.01f);
	}

	// Cleanup
	if (Kaelen)
	{
		Kaelen->Destroy();
	}
	World->DestroyWorld(false);
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
