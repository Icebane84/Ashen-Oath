// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Combat/AshenCombatCharacter.h"
#include "Combat/AshenShadowMarkCorruptionGASAbility.h"
#include "Combat/AshenOath_HealthComponent.h"
#include "Companions/AshenDevilsBargainTrustAtrophyDirector.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenShadowMarkConvergenceIntegrationTest,
	"AshenOath.Convergence.ShadowMark.CorruptionBurstAndTrustPenalty",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenShadowMarkConvergenceIntegrationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. SETUP TRANSIENT WORLD & GAME INSTANCE
	// -----------------------------------------------------------------------------------
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("ShadowMarkConvergenceTestWorld"));
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

	// Spawn In-Radius Target Dummy (300uu distance)
	AAshenCombatCharacter* InRadiusTarget = World->SpawnActor<AAshenCombatCharacter>(AAshenCombatCharacter::StaticClass(), FVector(300, 0, 0), FRotator::ZeroRotator, SpawnParams);
	TestNotNull(TEXT("In-radius target dummy spawned"), InRadiusTarget);

	// Spawn Out-of-Radius Target Dummy (900uu distance)
	AAshenCombatCharacter* OutOfRadiusTarget = World->SpawnActor<AAshenCombatCharacter>(AAshenCombatCharacter::StaticClass(), FVector(900, 0, 0), FRotator::ZeroRotator, SpawnParams);
	TestNotNull(TEXT("Out-of-radius target dummy spawned"), OutOfRadiusTarget);

	UAshenOath_HealthComponent* InRadiusHealth = InRadiusTarget ? InRadiusTarget->FindComponentByClass<UAshenOath_HealthComponent>() : nullptr;
	UAshenOath_HealthComponent* OutOfRadiusHealth = OutOfRadiusTarget ? OutOfRadiusTarget->FindComponentByClass<UAshenOath_HealthComponent>() : nullptr;
	TestNotNull(TEXT("In-radius health component exists"), InRadiusHealth);
	TestNotNull(TEXT("Out-of-radius health component exists"), OutOfRadiusHealth);

	if (InRadiusHealth && OutOfRadiusHealth && TrustDirector && Kaelen)
	{
		InRadiusHealth->SetMaxHealth(500.0f);
		InRadiusHealth->ReceiveDamage(0.0f, nullptr); // Initialize
		OutOfRadiusHealth->SetMaxHealth(500.0f);
		OutOfRadiusHealth->ReceiveDamage(0.0f, nullptr);
		TrustDirector->ActivePartyTrustLevel = 100.0f;

		// -----------------------------------------------------------------------------------
		// 2. EXECUTE SHADOW MARK CORRUPTION BURST
		// -----------------------------------------------------------------------------------
		UAshenShadowMarkCorruptionGASAbility* ShadowMarkAbility = NewObject<UAshenShadowMarkCorruptionGASAbility>(Kaelen);
		TestNotNull(TEXT("Shadow Mark GAS ability instantiated"), ShadowMarkAbility);

		const bool bBurstSuccess = ShadowMarkAbility->ActivateShadowMarkBurst(Kaelen);
		TestTrue(TEXT("Shadow Mark burst activated successfully"), bBurstSuccess);

		// Assert in-radius target received 250.0 Void AoE damage (500 -> 250)
		TestNearlyEqual(TEXT("In-radius target took 250 Void AoE damage (remaining: 250.0)"), InRadiusHealth->GetCurrentHealth(), 250.0f, 0.01f);

		// Assert out-of-radius target took 0 damage (remains 500)
		TestNearlyEqual(TEXT("Out-of-radius target took 0 damage (remains: 500.0)"), OutOfRadiusHealth->GetCurrentHealth(), 500.0f, 0.01f);

		// Assert -15.0% Companion Trust penalty applied (100% -> 85%)
		TestNearlyEqual(TEXT("Companion trust penalized by -15% (remaining: 85.0%)"), TrustDirector->ActivePartyTrustLevel, 85.0f, 0.01f);
	}

	// Cleanup
	if (Kaelen) Kaelen->Destroy();
	if (InRadiusTarget) InRadiusTarget->Destroy();
	if (OutOfRadiusTarget) OutOfRadiusTarget->Destroy();
	World->DestroyWorld(false);
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
