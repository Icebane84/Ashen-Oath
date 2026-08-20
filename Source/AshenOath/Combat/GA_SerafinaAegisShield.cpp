// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 202: GA_SerafinaAegisShield

#include "GA_SerafinaAegisShield.h"
#include "Kismet/KismetSystemLibrary.h"

UGA_SerafinaAegisShield::UGA_SerafinaAegisShield()
{
	ShieldAmount = 300.0f;
	ShieldRadius = 500.0f;
	ShieldDuration = 8.0f;
}

void UGA_SerafinaAegisShield::ActivateAbility(
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

	TArray<AActor*> OverlappingActors;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));

	UKismetSystemLibrary::SphereOverlapActors(
		Owner->GetWorld(),
		Origin,
		ShieldRadius,
		ObjectTypes,
		AActor::StaticClass(),
		TArray<AActor*>(),
		OverlappingActors
	);

	UE_LOG(LogTemp, Warning, TEXT("UGA_SerafinaAegisShield: RADIANT AEGIS SHIELD (%.0f HP, %.0fs) applied to %d allies in %.0fu radius."),
		ShieldAmount, ShieldDuration, OverlappingActors.Num(), ShieldRadius);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
