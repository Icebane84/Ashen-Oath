// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenEmpathicConduitNovaGASAbility.h"
#include "Combat/AshenCombatCharacter.h"
#include "Combat/AshenOath_HealthComponent.h"
#include "Combat/AshenOath_PoiseComponent.h"
#include "Companions/AshenDevilsBargainTrustAtrophyDirector.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Engine/OverlapResult.h"
#include "CollisionQueryParams.h"

UAshenEmpathicConduitNovaGASAbility::UAshenEmpathicConduitNovaGASAbility()
{
	BaseNovaDamage = 1200.0f;
	BasePoiseDamage = 300.0f;
	NovaRadius = 1400.0f;
	MinTrustRequired = 0.70f;
}

bool UAshenEmpathicConduitNovaGASAbility::UnleashEmpathicNova(AActor* InstigatorActor, float OverrideTrust)
{
	if (!InstigatorActor)
	{
		return false;
	}

	UWorld* World = InstigatorActor->GetWorld();
	if (!World)
	{
		return false;
	}

	// 1. Resolve active trust
	float ActiveTrust = OverrideTrust;
	if (ActiveTrust < 0.0f)
	{
		ActiveTrust = 1.0f;
		if (UGameInstance* GI = World->GetGameInstance())
		{
			if (UAshenDevilsBargainTrustAtrophyDirector* TrustDirector = GI->GetSubsystem<UAshenDevilsBargainTrustAtrophyDirector>())
			{
				ActiveTrust = TrustDirector->ActivePartyTrustLevel / 100.0f;
			}
		}
	}

	// 2. Validate trust threshold
	if (ActiveTrust < MinTrustRequired)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenEmpathicConduitNovaGASAbility: Rejected invocation - Active trust (%.2f) below minimum required (%.2f)."),
			ActiveTrust, MinTrustRequired);
		return false;
	}

	const float ScaledDamage = BaseNovaDamage * ActiveTrust;
	const FVector Origin = InstigatorActor->GetActorLocation();

	// 3. Overlap surrounding entities within 1400uu radius
	TArray<FOverlapResult> Overlaps;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(InstigatorActor);

	World->OverlapMultiByChannel(
		Overlaps,
		Origin,
		FQuat::Identity,
		ECC_Pawn,
		FCollisionShape::MakeSphere(NovaRadius),
		QueryParams
	);

	for (const FOverlapResult& Overlap : Overlaps)
	{
		if (AActor* HitActor = Overlap.GetActor())
		{
			// Apply health damage
			if (UAshenOath_HealthComponent* TargetHealth = HitActor->FindComponentByClass<UAshenOath_HealthComponent>())
			{
				TargetHealth->ReceiveDamage(ScaledDamage, InstigatorActor);
			}

			// Apply posture poise damage
			if (UAshenOath_PoiseComponent* TargetPoise = HitActor->FindComponentByClass<UAshenOath_PoiseComponent>())
			{
				TargetPoise->ApplyPoiseDamage(BasePoiseDamage);
			}
		}
	}

	// 4. Modulate weapon fuller emissives to pure Golden Conduit Radiance
	if (AAshenCombatCharacter* CombatChar = Cast<AAshenCombatCharacter>(InstigatorActor))
	{
		CombatChar->HandleRunicSeamColorUpdated(FLinearColor(1.0f, 0.92f, 0.5f, 1.0f), 8.0f);
	}

	if (OnEmpathicNovaUnleashed.IsBound())
	{
		OnEmpathicNovaUnleashed.Broadcast(ScaledDamage, NovaRadius, ActiveTrust);
	}

	UE_LOG(LogTemp, Error, TEXT("UAshenEmpathicConduitNovaGASAbility: *** EMPATHIC CONDUIT NOVA UNLEASHED *** (Damage: %.1f | Poise: %.1f | Radius: %.0fuu | Trust: %.2f)!"),
		ScaledDamage, BasePoiseDamage, NovaRadius, ActiveTrust);

	return true;
}
