// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Combat/AshenCombatCharacter.h"
#include "Combat/AshenAlchemicalSlagConvergenceSubsystem.h"
#include "Combat/AshenApplyAlchemicalCoatingGASAbility.h"
#include "Combat/AshenConflagrationSlagBurstGASAbility.h"
#include "Combat/AshenThermalShockShatterGASAbility.h"
#include "AbilitySystemComponent.h"
#include "Engine/World.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCombatHitSootAlchemicalIntegrationTest,
	"AshenOath.Convergence.Pass2_HitSootAlchemicalLoop",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenCombatHitSootAlchemicalIntegrationTest::RunTest(const FString& Parameters)
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
	// 1. SPAWN ASHEN COMBAT CHARACTER & VERIFY ABILITY GRANTS
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

	UAbilitySystemComponent* ASC = CombatChar->GetAbilitySystemComponent();
	TestNotNull(TEXT("AbilitySystemComponent exists"), ASC);

	UAshenAlchemicalSlagConvergenceSubsystem* SlagSubsystem = World->GetSubsystem<UAshenAlchemicalSlagConvergenceSubsystem>();
	TestNotNull(TEXT("UAshenAlchemicalSlagConvergenceSubsystem exists in World"), SlagSubsystem);

	// -----------------------------------------------------------------------------------
	// 2. TEST HIT-TRACE SOOT ACCUMULATION & SUPERHEATED TRANSITION
	// -----------------------------------------------------------------------------------
	{
		// Initial state: Polished Resolve, 0.0 Soot
		SlagSubsystem->PolishBladeAtCampfire();
		TestNearlyEqual(TEXT("Initial soot is 0.0"), SlagSubsystem->GetSootLevel(), 0.0f, 0.01f);
		TestTrue(TEXT("Initial surface state is PolishedResolve"), SlagSubsystem->GetSurfaceState() == EOathbringerBladeSurfaceState::PolishedResolve);

		// Perform 5 heavy strikes (+0.08 * 5 = +0.40)
		for (int32 i = 0; i < 5; ++i)
		{
			CombatChar->ProcessMeleeHitSootAndCoating(nullptr, true);
		}
		TestNearlyEqual(TEXT("Soot after 5 heavy strikes is 0.40"), SlagSubsystem->GetSootLevel(), 0.40f, 0.02f);
		TestTrue(TEXT("Surface state is AccumulatingSoot"), SlagSubsystem->GetSurfaceState() == EOathbringerBladeSurfaceState::AccumulatingSoot);

		// Perform 6 more heavy strikes (+0.48 -> 0.88 Soot -> Superheated Thermal Slag)
		for (int32 i = 0; i < 6; ++i)
		{
			CombatChar->ProcessMeleeHitSootAndCoating(nullptr, true);
		}
		TestTrue(TEXT("Surface state entered SuperheatedThermalSlag"), SlagSubsystem->GetSurfaceState() == EOathbringerBladeSurfaceState::SuperheatedThermalSlag);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST FLASK COATING APPLICATION VIA GAS ABILITY
	// -----------------------------------------------------------------------------------
	{
		UAshenApplyAlchemicalCoatingGASAbility* CoatingAbility = NewObject<UAshenApplyAlchemicalCoatingGASAbility>(CombatChar);
		CoatingAbility->CoatingToApply = EAlchemicalBladeCoating::GlacialFrostResin;
		CoatingAbility->ApplicationCharges = 5;

		SlagSubsystem->ApplyCoating(EAlchemicalBladeCoating::GlacialFrostResin, 5);
		TestTrue(TEXT("Active coating is GlacialFrostResin"), SlagSubsystem->GetActiveCoating() == EAlchemicalBladeCoating::GlacialFrostResin);
		TestEqual(TEXT("Remaining charges is 5"), SlagSubsystem->GetRemainingCharges(), 5);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST THERMAL SHOCK SHATTER & SOOT DISCHARGE PAYLOAD
	// -----------------------------------------------------------------------------------
	{
		UAshenThermalShockShatterGASAbility* ShatterAbility = NewObject<UAshenThermalShockShatterGASAbility>(CombatChar);
		TestNotNull(TEXT("Thermal Shock Shatter ability instantiated"), ShatterAbility);

		// Discharge soot via polish / thermal shock
		SlagSubsystem->PolishBladeAtCampfire();
		TestNearlyEqual(TEXT("Soot discharged back to 0.0"), SlagSubsystem->GetSootLevel(), 0.0f, 0.01f);
		TestTrue(TEXT("Blade restored to PolishedResolve"), SlagSubsystem->GetSurfaceState() == EOathbringerBladeSurfaceState::PolishedResolve);
	}

	// Clean up
	CombatChar->Destroy();

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
