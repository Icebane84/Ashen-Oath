// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Combat/AshenCombatCharacter.h"
#include "Combat/AshenOath_HealthComponent.h"
#include "Combat/AshenOath_SanityComponent.h"
#include "Core/AshenFocusModeInvestigationComponent.h"
#include "Core/AshenMartyrsTitheComponent.h"
#include "Companions/AshenDevilsBargainTrustAtrophyDirector.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenFocusAndMartyrTitheConvergenceIntegrationTest,
	"AshenOath.Convergence.FocusAndMartyrTithe.PerceptionAndSacrifice",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenFocusAndMartyrTitheConvergenceIntegrationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. SETUP TRANSIENT WORLD & GAME INSTANCE
	// -----------------------------------------------------------------------------------
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("FocusAndMartyrTitheTestWorld"));
	TestNotNull(TEXT("Transient World created"), World);
	if (!World)
	{
		return false;
	}

	UGameInstance* GameInstance = NewObject<UGameInstance>(World);
	GameInstance->Init();
	World->SetGameInstance(GameInstance);

	UAshenDevilsBargainTrustAtrophyDirector* TrustDirector = GameInstance->GetSubsystem<UAshenDevilsBargainTrustAtrophyDirector>();
	TestNotNull(TEXT("UAshenDevilsBargainTrustAtrophyDirector exists on GameInstance"), TrustDirector);

	// Spawn Player Character (Kaelen)
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	AAshenCombatCharacter* Kaelen = World->SpawnActor<AAshenCombatCharacter>(AAshenCombatCharacter::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
	TestNotNull(TEXT("Kaelen combat character spawned"), Kaelen);

	UAshenFocusModeInvestigationComponent* FocusComp = Kaelen ? Kaelen->GetFocusModeInvestigationComponent() : nullptr;
	TestNotNull(TEXT("FocusModeInvestigationComponent exists on Kaelen"), FocusComp);

	UAshenMartyrsTitheComponent* MartyrComp = Kaelen ? Kaelen->GetMartyrsTitheComponent() : nullptr;
	TestNotNull(TEXT("MartyrsTitheComponent exists on Kaelen"), MartyrComp);

	UAshenOath_HealthComponent* HealthComp = Kaelen ? Kaelen->FindComponentByClass<UAshenOath_HealthComponent>() : nullptr;
	TestNotNull(TEXT("Kaelen health component exists"), HealthComp);

	UAshenOath_SanityComponent* SanityComp = Kaelen ? Kaelen->FindComponentByClass<UAshenOath_SanityComponent>() : nullptr;
	TestNotNull(TEXT("Kaelen sanity component exists"), SanityComp);

	// -----------------------------------------------------------------------------------
	// 2. TEST FOCUS MODE DILATION, SANITY DRAIN & AUTO-COLLAPSE
	// -----------------------------------------------------------------------------------
	if (FocusComp && SanityComp)
	{
		SanityComp->SetCurrentSanity(50.0f);

		// Toggle Focus Mode ON
		FocusComp->ToggleFocusMode(true);
		TestTrue(TEXT("Focus Mode is active"), FocusComp->IsFocusModeActive());
		TestNearlyEqual(TEXT("Time dilation is 0.35x"), FocusComp->GetTimeDilationMultiplier(), 0.35f, 0.01f);

		// Simulate 5.0 seconds of TickComponent at 4.0 units/sec drain (50 -> 30)
		FocusComp->TickComponent(5.0f, ELevelTick::LEVELTICK_All, nullptr);
		TestNearlyEqual(TEXT("Sanity drained to 30.0 after 5s"), SanityComp->GetCurrentSanity(), 30.0f, 0.01f);

		// Drain remaining sanity to 0
		FocusComp->TickComponent(10.0f, ELevelTick::LEVELTICK_All, nullptr);
		TestNearlyEqual(TEXT("Sanity is exhausted (0.0)"), SanityComp->GetCurrentSanity(), 0.0f, 0.01f);
		TestFalse(TEXT("Focus mode auto-collapsed on sanity depletion"), FocusComp->IsFocusModeActive());
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST MARTYR'S TITHE MAX HEALTH SACRIFICE & COMPANION TRUST RESTORATION
	// -----------------------------------------------------------------------------------
	if (MartyrComp && HealthComp && TrustDirector)
	{
		HealthComp->SetMaxHealth(500.0f);
		TrustDirector->ActivePartyTrustLevel = 70.0f;

		// Perform 100 HP permanent sacrifice
		const bool bSacrificeSuccess = MartyrComp->PerformMartyrSacrifice(100.0f);
		TestTrue(TEXT("Martyr sacrifice of 100 HP succeeded"), bSacrificeSuccess);

		// Assert permanent Max HP reduction
		TestNearlyEqual(TEXT("Max Health permanently reduced from 500 to 400"), HealthComp->GetMaxHealth(), 400.0f, 0.01f);

		// Assert party buff calculation (1.0 + (100/100)*0.25 = 1.25x)
		TestNearlyEqual(TEXT("Party combat buff multiplier is 1.25x"), MartyrComp->GetPartyBuffMultiplier(), 1.25f, 0.01f);

		// Assert +15.0% Companion Trust restored (70% -> 85%)
		TestNearlyEqual(TEXT("Companion trust restored to 85.0%"), TrustDirector->ActivePartyTrustLevel, 85.0f, 0.01f);

		// Test rejection when sacrifice would reduce Max HP below 50.0 threshold
		const bool bExcessiveSacrifice = MartyrComp->PerformMartyrSacrifice(380.0f);
		TestFalse(TEXT("Excessive sacrifice rejected (cannot reduce Max HP below 50)"), bExcessiveSacrifice);
		TestNearlyEqual(TEXT("Max Health unchanged after rejected sacrifice"), HealthComp->GetMaxHealth(), 400.0f, 0.01f);
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
