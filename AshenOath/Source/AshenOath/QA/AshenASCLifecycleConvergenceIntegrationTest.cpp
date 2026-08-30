// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Combat/AshenAbilitySystemComponent.h"
#include "Soul/AshenSoulPublisher.h"
#include "Soul/AshenSoulDerivationSubsystem.h"
#include "Soul/AshenSoulStateVector.h"
#include "Soul/AshenSoulTypes.h"

#if WITH_DEV_AUTOMATION_TESTS

// -----------------------------------------------------------------------------
// 1. UNIT TEST: Attribute Clamping & Delegate Firing
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenASCAttributeUnitTest,
	"AshenOath.ASC.Unit.AttributeClamping",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenASCAttributeUnitTest::RunTest(const FString& Parameters)
{
	UAshenAbilitySystemComponent* ASC = NewObject<UAshenAbilitySystemComponent>();
	TestNotNull(TEXT("ASC allocated cleanly"), ASC);

	if (ASC)
	{
		TestEqual(TEXT("Initial Sanity is 100.0"), ASC->GetCurrentSanity(), 100.0f);
		TestEqual(TEXT("Initial Poise is 100.0"), ASC->GetCurrentPoise(), 100.0f);
		TestEqual(TEXT("Initial Stamina is 100.0"), ASC->GetCurrentStamina(), 100.0f);

		// Apply Sanity damage
		ASC->ApplySanityDamage(30.0f);
		TestEqual(TEXT("Sanity drops to 70.0"), ASC->GetCurrentSanity(), 70.0f);

		// Apply Poise strain with over-clamping
		ASC->ApplyPoiseStrain(150.0f);
		TestEqual(TEXT("Poise clamps at minimum 0.0"), ASC->GetCurrentPoise(), 0.0f);

		// Apply Stamina drain
		ASC->ApplyStaminaDrain(45.0f);
		TestEqual(TEXT("Stamina drains to 55.0"), ASC->GetCurrentStamina(), 55.0f);
	}

	return true;
}

// -----------------------------------------------------------------------------
// 2. INTEGRATION TEST: ASC Attribute Mutations Bridge to UAshenSoulPublisher
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenASCIntegrationTest,
	"AshenOath.ASC.Integration.SanityToSoulPublisher",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenASCIntegrationTest::RunTest(const FString& Parameters)
{
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("ASCTestWorld"));
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
			// Reset publisher state to pristine baseline
			FSoulStateVector Baseline;
			Baseline.Resolve = 0.80f;
			Baseline.Corruption = 0.0f;
			Baseline.IntegrationDebt = 0.0f;
			Baseline.Isolation = 0.0f;
			Baseline.GarrettTrust = 0.75f;
			Baseline.SerafinaTrust = 0.75f;
			Publisher->CommitStateDirect(Baseline);

			// Instantiate ASC in world context
			UAshenAbilitySystemComponent* ASC = NewObject<UAshenAbilitySystemComponent>(World);
			TestNotNull(TEXT("ASC created in world context"), ASC);

			if (ASC)
			{
				// Apply heavy Sanity damage (50.0)
				ASC->ApplySanityDamage(50.0f);

				const FSoulStateVector PostDamageState = Publisher->GetSoulState();
				TestTrue(TEXT("Sanity damage commits canonical Dysregulation (N/Isolation)"), PostDamageState.Isolation > 0.20f);
				TestTrue(TEXT("Sanity damage commits canonical Corruption (C)"), PostDamageState.Corruption > 0.15f);

				// Apply Poise strain (50.0)
				ASC->ApplyPoiseStrain(50.0f);
				const FSoulStateVector PostPoiseState = Publisher->GetSoulState();
				TestTrue(TEXT("Poise strain commits canonical Integration Debt (D)"), PostPoiseState.IntegrationDebt > 0.15f);
			}
		}
	}

	World->DestroyWorld(false);
	return true;
}

// -----------------------------------------------------------------------------
// 3. CONTRACT TEST: SSoT Boundary Reflection Audit
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenASCLifecycleContractTest,
	"AshenOath.ASC.Contract.SSoTBoundaries",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenASCLifecycleContractTest::RunTest(const FString& Parameters)
{
	// Ensure that IsolationPressure and ParasitePressure do NOT exist as persistent ASC attributes or fields
	const UClass* ASCClass = UAshenAbilitySystemComponent::StaticClass();
	TestNotNull(TEXT("UAshenAbilitySystemComponent class reflected"), ASCClass);

	if (ASCClass)
	{
		const FProperty* IsoProp = ASCClass->FindPropertyByName(FName("IsolationPressure"));
		TestNull(TEXT("IsolationPressure must NOT exist as persistent ASC property (Derived only)"), IsoProp);

		const FProperty* HungerProp = ASCClass->FindPropertyByName(FName("ParasitePressure"));
		TestNull(TEXT("ParasitePressure must NOT exist as persistent ASC property (Derived only)"), HungerProp);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
