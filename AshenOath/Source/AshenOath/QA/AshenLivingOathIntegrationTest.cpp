// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Combat/AshenCombatCharacter.h"
#include "Core/AshenOath_OathRegistryComponent.h"
#include "Soul/AshenLivingOathRegistrySubsystem.h"
#include "Combat/AshenLivingOathGASAbility.h"
#include "Combat/AshenOathBurnStaminaDrainGASAbility.h"
#include "AbilitySystemComponent.h"
#include "Engine/World.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenLivingOathIntegrationTest,
	"AshenOath.Convergence.Pass2_LivingOathAndBurnLoop",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenLivingOathIntegrationTest::RunTest(const FString& Parameters)
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

	// -----------------------------------------------------------------------------------
	// 1. SPAWN ASHEN COMBAT CHARACTER & VERIFY OATH REGISTRY COMPONENT
	// -----------------------------------------------------------------------------------
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	AAshenCombatCharacter* CombatChar = World->SpawnActor<AAshenCombatCharacter>(
		AAshenCombatCharacter::StaticClass(),
		FVector(0.0f, 0.0f, 100.0f),
		FRotator::ZeroRotator,
		SpawnParams
	);

	TestNotNull(TEXT("AAshenCombatCharacter spawned cleanly"), CombatChar);
	if (!CombatChar)
	{
		return false;
	}

	UAshenOath_OathRegistryComponent* OathReg = CombatChar->FindComponentByClass<UAshenOath_OathRegistryComponent>();
	TestNotNull(TEXT("UAshenOath_OathRegistryComponent exists on CombatCharacter"), OathReg);

	UAshenLivingOathRegistrySubsystem* OathSubsystem = World->GetSubsystem<UAshenLivingOathRegistrySubsystem>();
	TestNotNull(TEXT("UAshenLivingOathRegistrySubsystem exists in World"), OathSubsystem);

	// -----------------------------------------------------------------------------------
	// 2. TEST SWEARING LIVING OATHS & BURDEN ACCUMULATION
	// -----------------------------------------------------------------------------------
	{
		TestEqual(TEXT("Initial active oaths is 0"), OathReg->GetActiveOathCount(), 0);
		TestNearlyEqual(TEXT("Initial burden is 0.0"), OathReg->GetOathBurden(), 0.0f, 0.01f);
		TestFalse(TEXT("Oath burn initially inactive"), OathReg->IsOathBurnActive());

		// Swear 3 Oaths
		OathReg->SwearOath(FName("Oath_ProtectTheWeak"), FText::FromString(TEXT("Protect the innocent")));
		OathReg->SwearOath(FName("Oath_SunderTheVeil"), FText::FromString(TEXT("Sunder corruption")));
		OathReg->SwearOath(FName("Oath_HonorTheFallen"), FText::FromString(TEXT("Honor fallen knights")));

		TestEqual(TEXT("Active oath count is 3"), OathReg->GetActiveOathCount(), 3);
		TestNearlyEqual(TEXT("Burden after 3 oaths is 0.30"), OathReg->GetOathBurden(), 0.30f, 0.02f);

		// Swear 7 more oaths to trigger Oath Burn threshold (Burden >= 1.0)
		for (int32 i = 0; i < 7; ++i)
		{
			const FName OathName = *FString::Printf(TEXT("Oath_Generic_%d"), i);
			OathReg->SwearOath(OathName, FText::FromString(TEXT("Generic Oath")));
		}

		TestEqual(TEXT("Active oath count is 10"), OathReg->GetActiveOathCount(), 10);
		TestNearlyEqual(TEXT("Burden after 10 oaths is 1.00"), OathReg->GetOathBurden(), 1.00f, 0.02f);
		TestTrue(TEXT("Oath Burn is active at burden >= 1.0"), OathReg->IsOathBurnActive());
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST LIVING OATH RESONANCE STRIKE & OATH BURN DEBUFF ABILITY
	// -----------------------------------------------------------------------------------
	{
		UAshenLivingOathGASAbility* LivingOathAbility = NewObject<UAshenLivingOathGASAbility>(CombatChar);
		TestNotNull(TEXT("UAshenLivingOathGASAbility instantiated"), LivingOathAbility);

		const bool bStrikeSuccess = LivingOathAbility->ActivateOathStrike(EAshenLivingOathType::OathOfSilentVigil);
		TestTrue(TEXT("Living Oath resonance strike executed"), bStrikeSuccess);

		UAshenOathBurnStaminaDrainGASAbility* OathBurnAbility = NewObject<UAshenOathBurnStaminaDrainGASAbility>(CombatChar);
		TestNotNull(TEXT("UAshenOathBurnStaminaDrainGASAbility instantiated"), OathBurnAbility);

		const bool bBurnDebuffApplied = OathBurnAbility->ActivateOathBurnDebuffState();
		TestTrue(TEXT("Oath Burn stamina drain debuff applied cleanly"), bBurnDebuffApplied);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST OATH FULFILLMENT & OATH BREACH LIFECYCLES
	// -----------------------------------------------------------------------------------
	{
		// Fulfill Oath
		const bool bFulfillSuccess = OathReg->FulfillOath(FName("Oath_ProtectTheWeak"));
		TestTrue(TEXT("Oath fulfillment returned true"), bFulfillSuccess);
		TestEqual(TEXT("Active oaths reduced to 9"), OathReg->GetActiveOathCount(), 9);

		// Break Oath
		const bool bBreakSuccess = OathReg->BreakOath(FName("Oath_SunderTheVeil"));
		TestTrue(TEXT("Oath break returned true"), bBreakSuccess);
		TestEqual(TEXT("Broken oath count is 1"), OathReg->GetBrokenOathCount(), 1);
	}

	// Clean up
	CombatChar->Destroy();

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
