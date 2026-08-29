// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Combat/AshenCombatCharacter.h"
#include "Combat/AshenUnreliableNarratorGASAbility.h"
#include "Combat/AshenOath_StaminaComponent.h"
#include "Combat/AshenOath_SanityComponent.h"
#include "Core/AshenUnreliableStateMachineSubsystem.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenUnreliableNarratorConvergenceIntegrationTest,
	"AshenOath.Convergence.UnreliableNarrator.WillpowerDispelAndInterfaceMode",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenUnreliableNarratorConvergenceIntegrationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. SETUP TRANSIENT WORLD & GAME INSTANCE
	// -----------------------------------------------------------------------------------
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("UnreliableNarratorTestWorld"));
	TestNotNull(TEXT("Transient World created"), World);
	if (!World)
	{
		return false;
	}

	UGameInstance* GameInstance = NewObject<UGameInstance>(World);
	GameInstance->Init();
	World->SetGameInstance(GameInstance);

	UAshenUnreliableStateMachineSubsystem* StateSubsystem = World->GetSubsystem<UAshenUnreliableStateMachineSubsystem>();
	TestNotNull(TEXT("UAshenUnreliableStateMachineSubsystem exists on World"), StateSubsystem);

	// Spawn Player Character (Kaelen)
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	AAshenCombatCharacter* Kaelen = World->SpawnActor<AAshenCombatCharacter>(AAshenCombatCharacter::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
	TestNotNull(TEXT("Kaelen combat character spawned"), Kaelen);

	UAshenOath_StaminaComponent* StaminaComp = Kaelen ? Kaelen->FindComponentByClass<UAshenOath_StaminaComponent>() : nullptr;
	UAshenOath_SanityComponent* SanityComp = Kaelen ? Kaelen->FindComponentByClass<UAshenOath_SanityComponent>() : nullptr;
	TestNotNull(TEXT("Kaelen stamina component exists"), StaminaComp);
	TestNotNull(TEXT("Kaelen sanity component exists"), SanityComp);

	UAshenUnreliableNarratorGASAbility* DispelAbility = NewObject<UAshenUnreliableNarratorGASAbility>(Kaelen);
	TestNotNull(TEXT("Dispel GAS ability instantiated"), DispelAbility);

	// -----------------------------------------------------------------------------------
	// 2. TEST INSUFFICIENT STAMINA REJECTION
	// -----------------------------------------------------------------------------------
	if (DispelAbility && StaminaComp && SanityComp && StateSubsystem)
	{
		StateSubsystem->SetInterfaceMode(EAshenInterfaceMode::FalseConfidence);
		TestTrue(TEXT("Interface mode is FalseConfidence"), StateSubsystem->GetCurrentInterfaceMode() == EAshenInterfaceMode::FalseConfidence);

		StaminaComp->SetCurrentStamina(5.0f); // Insufficient (requires 15.0)
		SanityComp->SetCurrentSanity(30.0f);

		const bool bFailedDispel = DispelAbility->DispelHallucinatoryMirage(Kaelen);
		TestFalse(TEXT("Dispel pulse rejected due to low stamina"), bFailedDispel);
		TestTrue(TEXT("Interface mode remains FalseConfidence"), StateSubsystem->GetCurrentInterfaceMode() == EAshenInterfaceMode::FalseConfidence);
		TestNearlyEqual(TEXT("Stamina unchanged on failed attempt"), StaminaComp->GetCurrentStamina(), 5.0f, 0.01f);

		// -----------------------------------------------------------------------------------
		// 3. TEST SUCCESSFUL WILLPOWER PULSE & CAUSAL RECOVERY
		// -----------------------------------------------------------------------------------
		StaminaComp->SetCurrentStamina(50.0f);
		SanityComp->SetCurrentSanity(30.0f);

		const bool bSuccessDispel = DispelAbility->DispelHallucinatoryMirage(Kaelen);
		TestTrue(TEXT("Dispel pulse successfully executed"), bSuccessDispel);

		// Assert 15.0 stamina consumed (50 -> 35)
		TestNearlyEqual(TEXT("15.0 stamina consumed (remaining: 35.0)"), StaminaComp->GetCurrentStamina(), 35.0f, 0.01f);

		// Assert +15.0 sanity healed (30 -> 45)
		TestNearlyEqual(TEXT("15.0 sanity restored (current: 45.0)"), SanityComp->GetCurrentSanity(), 45.0f, 0.01f);

		// Assert Interface Mode restored to DiegeticOnly
		TestTrue(TEXT("Interface mode restored to DiegeticOnly"), StateSubsystem->GetCurrentInterfaceMode() == EAshenInterfaceMode::DiegeticOnly);
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
