// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Combat/AshenCombatCharacter.h"
#include "Combat/AshenEmpathicConduitNovaGASAbility.h"
#include "Combat/AshenOath_HealthComponent.h"
#include "Combat/AshenOath_PoiseComponent.h"
#include "Companions/AshenDevilsBargainTrustAtrophyDirector.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenEmpathicConduitNovaConvergenceIntegrationTest,
	"AshenOath.Convergence.Trinity.EmpathicConduitNovaFinisher",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenEmpathicConduitNovaConvergenceIntegrationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. SETUP TRANSIENT WORLD & GAME INSTANCE
	// -----------------------------------------------------------------------------------
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("ConduitNovaTestWorld"));
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

	// Spawn Player Character (Kaelen) at origin
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	AAshenCombatCharacter* Kaelen = World->SpawnActor<AAshenCombatCharacter>(AAshenCombatCharacter::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
	TestNotNull(TEXT("Kaelen combat character spawned"), Kaelen);

	// Spawn In-Radius Target Dummy (700uu distance, within 1400uu radius)
	AAshenCombatCharacter* InRadiusTarget = World->SpawnActor<AAshenCombatCharacter>(AAshenCombatCharacter::StaticClass(), FVector(700, 0, 0), FRotator::ZeroRotator, SpawnParams);
	TestNotNull(TEXT("In-radius target dummy spawned"), InRadiusTarget);

	// Spawn Out-of-Radius Target Dummy (1800uu distance, outside 1400uu radius)
	AAshenCombatCharacter* OutOfRadiusTarget = World->SpawnActor<AAshenCombatCharacter>(AAshenCombatCharacter::StaticClass(), FVector(1800, 0, 0), FRotator::ZeroRotator, SpawnParams);
	TestNotNull(TEXT("Out-of-radius target dummy spawned"), OutOfRadiusTarget);

	UAshenOath_HealthComponent* InRadiusHealth = InRadiusTarget ? InRadiusTarget->FindComponentByClass<UAshenOath_HealthComponent>() : nullptr;
	UAshenOath_PoiseComponent* InRadiusPoise = InRadiusTarget ? InRadiusTarget->FindComponentByClass<UAshenOath_PoiseComponent>() : nullptr;
	UAshenOath_HealthComponent* OutOfRadiusHealth = OutOfRadiusTarget ? OutOfRadiusTarget->FindComponentByClass<UAshenOath_HealthComponent>() : nullptr;

	TestNotNull(TEXT("In-radius health component exists"), InRadiusHealth);
	TestNotNull(TEXT("In-radius poise component exists"), InRadiusPoise);
	TestNotNull(TEXT("Out-of-radius health component exists"), OutOfRadiusHealth);

	UAshenEmpathicConduitNovaGASAbility* NovaAbility = NewObject<UAshenEmpathicConduitNovaGASAbility>(Kaelen);
	TestNotNull(TEXT("Empathic Conduit Nova GAS ability instantiated"), NovaAbility);

	if (InRadiusHealth && InRadiusPoise && OutOfRadiusHealth && TrustDirector && NovaAbility && Kaelen)
	{
		InRadiusHealth->SetMaxHealth(2000.0f);
		InRadiusHealth->ReceiveDamage(0.0f, nullptr);
		InRadiusPoise->SetMaxPoise(500.0f);
		InRadiusPoise->ResetPoise();

		OutOfRadiusHealth->SetMaxHealth(2000.0f);
		OutOfRadiusHealth->ReceiveDamage(0.0f, nullptr);

		// -----------------------------------------------------------------------------------
		// 2. TEST LOW TRUST REJECTION (50% < 70%)
		// -----------------------------------------------------------------------------------
		TrustDirector->ActivePartyTrustLevel = 50.0f;

		const bool bFailedAttempt = NovaAbility->UnleashEmpathicNova(Kaelen);
		TestFalse(TEXT("Conduit Nova rejected due to low trust (<70%)"), bFailedAttempt);
		TestNearlyEqual(TEXT("In-radius dummy took 0 damage on rejected cast"), InRadiusHealth->GetCurrentHealth(), 2000.0f, 0.01f);

		// -----------------------------------------------------------------------------------
		// 3. TEST HIGH TRUST DETONATION & DAMAGE SCALING (85% >= 70%)
		// -----------------------------------------------------------------------------------
		TrustDirector->ActivePartyTrustLevel = 85.0f;

		const bool bSuccessAttempt = NovaAbility->UnleashEmpathicNova(Kaelen);
		TestTrue(TEXT("Conduit Nova successfully detonated with high trust"), bSuccessAttempt);

		// Expected Damage: 1200 * 0.85 = 1020.0 (Remaining Health: 2000 - 1020 = 980.0)
		TestNearlyEqual(TEXT("In-radius dummy took 1020 scaled damage (remaining: 980.0)"), InRadiusHealth->GetCurrentHealth(), 980.0f, 0.1f);

		// Expected Poise Damage: 300.0 (Remaining Poise: 500 - 300 = 200.0)
		TestNearlyEqual(TEXT("In-radius dummy took 300 poise damage (remaining: 200.0)"), InRadiusPoise->GetCurrentPoise(), 200.0f, 0.1f);

		// Assert Out-of-radius dummy took 0 damage (remains 2000)
		TestNearlyEqual(TEXT("Out-of-radius dummy took 0 damage (remains: 2000.0)"), OutOfRadiusHealth->GetCurrentHealth(), 2000.0f, 0.01f);
	}

	// Cleanup
	if (Kaelen) Kaelen->Destroy();
	if (InRadiusTarget) InRadiusTarget->Destroy();
	if (OutOfRadiusTarget) OutOfRadiusTarget->Destroy();
	World->DestroyWorld(false);
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
