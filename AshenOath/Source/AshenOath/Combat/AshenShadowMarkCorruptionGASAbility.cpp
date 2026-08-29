// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenShadowMarkCorruptionGASAbility.h"
#include "Combat/AshenCombatCharacter.h"
#include "Combat/AshenOath_HealthComponent.h"
#include "Companions/AshenDevilsBargainTrustAtrophyDirector.h"
#include "VFX/AshenNyxBileSeepageEvaluatorComponent.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Engine/OverlapResult.h"
#include "CollisionQueryParams.h"

UAshenShadowMarkCorruptionGASAbility::UAshenShadowMarkCorruptionGASAbility()
{
	BurstAoEDamage = 250.0f;
	BurstRadiusUnits = 600.0f;
	CompanionTrustPenalty = 15.0f;
}

bool UAshenShadowMarkCorruptionGASAbility::ActivateShadowMarkBurst(AActor* InstigatorActor)
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

	const FVector Origin = InstigatorActor->GetActorLocation();

	// 1. Calculate dynamic bile spawn rate via NyxBileSeepageEvaluatorComponent
	float BileRate = 35.0f;
	if (UAshenNyxBileSeepageEvaluatorComponent* BileEvaluator = InstigatorActor->FindComponentByClass<UAshenNyxBileSeepageEvaluatorComponent>())
	{
		BileRate = BileEvaluator->CalculateBileSpawnRate(1.0f);
	}

	// 2. Apply 250.0 Dark/Void AoE damage to surrounding entities
	TArray<FOverlapResult> Overlaps;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(InstigatorActor);

	World->OverlapMultiByChannel(
		Overlaps,
		Origin,
		FQuat::Identity,
		ECC_Pawn,
		FCollisionShape::MakeSphere(BurstRadiusUnits),
		QueryParams
	);

	for (const FOverlapResult& Overlap : Overlaps)
	{
		if (AActor* HitActor = Overlap.GetActor())
		{
			if (UAshenOath_HealthComponent* TargetHealth = HitActor->FindComponentByClass<UAshenOath_HealthComponent>())
			{
				TargetHealth->ReceiveDamage(BurstAoEDamage, InstigatorActor);
			}
		}
	}

	// 3. Update dynamic material instances on Kaelen
	if (AAshenCombatCharacter* CombatChar = Cast<AAshenCombatCharacter>(InstigatorActor))
	{
		CombatChar->HandleRunicSeamColorUpdated(FLinearColor(0.1f, 0.02f, 0.25f, 1.0f), 4.0f);
	}

	// 4. Inflict Companion Trust penalty due to Void corruption manifestation
	if (UGameInstance* GI = World->GetGameInstance())
	{
		if (UAshenDevilsBargainTrustAtrophyDirector* TrustDirector = GI->GetSubsystem<UAshenDevilsBargainTrustAtrophyDirector>())
		{
			TrustDirector->ApplyDevilsBargainTrustAtrophy(CompanionTrustPenalty);
		}
	}

	if (OnShadowMarkBurstActivated.IsBound())
	{
		OnShadowMarkBurstActivated.Broadcast(BurstAoEDamage, BileRate, CompanionTrustPenalty);
	}

	UE_LOG(LogTemp, Warning, TEXT("UAshenShadowMarkCorruptionGASAbility: *** SHADOW MARK CORRUPTION BURST ACTIVATED *** (Damage: %.1f | Radius: %.0fuu | Trust Penalty: -%.1f%%)!"),
		BurstAoEDamage, BurstRadiusUnits, CompanionTrustPenalty);

	return true;
}
