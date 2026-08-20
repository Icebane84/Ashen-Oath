// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 514: GA_SerafinaLorekeeperInsightExecution

#include "GA_SerafinaLorekeeperInsightExecution.h"
#include "AshenOath_HealthComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UGA_SerafinaLorekeeperInsightExecution::UGA_SerafinaLorekeeperInsightExecution()
{
	SanityRestored = 300.0f;
}

void UGA_SerafinaLorekeeperInsightExecution::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		return;
	}

	AActor* Owner = ActorInfo->OwnerActor.Get();
	if (!Owner)
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		return;
	}

	const FVector Origin = Owner->GetActorLocation();

	TArray<AActor*> HitActors;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));

	UKismetSystemLibrary::SphereOverlapActors(
		Owner->GetWorld(),
		Origin,
		600.0f,
		ObjectTypes,
		AActor::StaticClass(),
		TArray<AActor*>{},
		HitActors
	);

	int32 InsightCount = 0;
	for (AActor* Target : HitActors)
	{
		if (!Target) continue;

		UAshenOath_HealthComponent* TargetHealth = Target->FindComponentByClass<UAshenOath_HealthComponent>();
		if (TargetHealth)
		{
			TargetHealth->Heal(150.0f);
			InsightCount++;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_SerafinaLorekeeperInsightExecution: LOREKEEPER INSIGHT — Imprints Decrypted for %d allies (Sanity Restored: %.0f)."),
		InsightCount, SanityRestored);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
