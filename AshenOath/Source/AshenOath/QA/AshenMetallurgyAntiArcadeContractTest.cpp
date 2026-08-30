// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Combat/AshenOathbringerLifecycleComponent.h"
#include "Combat/AshenOathbringerMetallurgyTypes.h"
#include "Soul/AshenSoulPublisher.h"
#include "Soul/AshenSoulTypes.h"
#include "Soul/AshenSoulStateVector.h"

#if WITH_DEV_AUTOMATION_TESTS

// -----------------------------------------------------------------------------
// 1. CONTRACT TEST: The Anti-Arcade Law (Zero Neon Emissive)
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMetallurgyAntiArcadeContractTest,
	"AshenOath.Metallurgy.Contract.ZeroNeonEmissive",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMetallurgyAntiArcadeContractTest::RunTest(const FString& Parameters)
{
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("MetallurgyContractWorld"));
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
			UAshenOathbringerLifecycleComponent* WeaponLifecycle = NewObject<UAshenOathbringerLifecycleComponent>(World);
			TestNotNull(TEXT("Weapon Lifecycle Component created"), WeaponLifecycle);

			if (WeaponLifecycle)
			{
				// Test 1: Tier 1 Burdened Iron -> EmissiveIntensity == 0.0f
				FSoulStateVector Tier1State;
				Tier1State.Resolve = 0.20f;
				Tier1State.Corruption = 0.10f;
				Publisher->CommitStateDirect(Tier1State);
				WeaponLifecycle->EvaluateWeaponLifecycle();

				TestEqual(TEXT("Tier 1 active"), WeaponLifecycle->GetCurrentMetallurgicalTier(), EOathbringerMetallurgicalTier::BurdenedIron);
				TestEqual(TEXT("Tier 1 Emissive is 0.0"), WeaponLifecycle->GetActiveMaterialParameters().EmissiveIntensity, 0.0f);
				TestEqual(TEXT("Tier 1 Roughness is 0.65 (grimy iron)"), WeaponLifecycle->GetActiveMaterialParameters().Roughness, 0.65f);
				TestEqual(TEXT("Tier 1 Mass is 120kg"), WeaponLifecycle->GetEffectiveWeaponMass(), 120.0f);

				// Test 2: Tier 3 The Scribed Vow -> EmissiveIntensity == 0.0f, Silver Chime active
				FSoulStateVector Tier3State;
				Tier3State.Resolve = 0.75f;
				Tier3State.Corruption = 0.10f;
				Publisher->CommitStateDirect(Tier3State);
				WeaponLifecycle->EvaluateWeaponLifecycle();

				TestEqual(TEXT("Tier 3 active"), WeaponLifecycle->GetCurrentMetallurgicalTier(), EOathbringerMetallurgicalTier::ScribedVow);
				TestEqual(TEXT("Tier 3 Emissive is 0.0 (Zero Neon Law)"), WeaponLifecycle->GetActiveMaterialParameters().EmissiveIntensity, 0.0f);
				TestEqual(TEXT("Tier 3 Roughness is 0.15 (mirror Damascus)"), WeaponLifecycle->GetActiveMaterialParameters().Roughness, 0.15f);
				TestEqual(TEXT("Tier 3 Silver Chime is 2.4s"), WeaponLifecycle->GetActiveAcousticProfile().SilverChimeDecaySeconds, 2.4f);

				// Test 3: Tier 4 Devouring Nightsteel -> LightAbsorption 2.0", Retroreflection 1.0, Emissive 0.0
				FSoulStateVector Tier4State;
				Tier4State.Corruption = 0.80f;
				Publisher->CommitStateDirect(Tier4State);
				WeaponLifecycle->EvaluateWeaponLifecycle();

				TestEqual(TEXT("Tier 4 active"), WeaponLifecycle->GetCurrentMetallurgicalTier(), EOathbringerMetallurgicalTier::DevouringNightsteel);
				TestEqual(TEXT("Tier 4 Light Absorption is 2.0 inches"), WeaponLifecycle->GetActiveMaterialParameters().LightAbsorptionRadius, 2.0f);
				TestEqual(TEXT("Tier 4 Wolf Eye Retroreflection is 1.0"), WeaponLifecycle->GetActiveMaterialParameters().TapetumLucidumRetroreflection, 1.0f);
				TestEqual(TEXT("Tier 4 Emissive is 0.0 (No purple fire)"), WeaponLifecycle->GetActiveMaterialParameters().EmissiveIntensity, 0.0f);
				TestEqual(TEXT("Tier 4 forward pull impulse is +400uu/s"), WeaponLifecycle->GetForwardPullImpulse(), 400.0f);

				// Test 4: Tier 5 Cold Monolith -> Absolute Acoustic Isolation / Silence
				FSoulStateVector Tier5State;
				Tier5State.Resolve = 0.95f;
				Tier5State.Corruption = 0.05f;
				Publisher->CommitStateDirect(Tier5State);
				WeaponLifecycle->EvaluateWeaponLifecycle();

				TestEqual(TEXT("Tier 5 active"), WeaponLifecycle->GetCurrentMetallurgicalTier(), EOathbringerMetallurgicalTier::ColdMonolith);
				TestTrue(TEXT("Tier 5 Dead Acoustic Isolation enabled"), WeaponLifecycle->GetActiveAcousticProfile().bDeadAcousticIsolation);
				TestEqual(TEXT("Tier 5 Roughness is 0.05 (surgical 2D edge)"), WeaponLifecycle->GetActiveMaterialParameters().Roughness, 0.05f);
				TestEqual(TEXT("Tier 5 Mass is 35kg"), WeaponLifecycle->GetEffectiveWeaponMass(), 35.0f);
			}
		}
	}

	World->DestroyWorld(false);
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
