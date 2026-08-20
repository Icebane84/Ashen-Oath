// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "GA_GarrettSmokeWarp.h"
#include "AshenOath_HealthComponent.h"
#include "AshenVFXPoolSubsystem.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GameFramework/Character.h"

UGA_GarrettSmokeWarp::UGA_GarrettSmokeWarp()
{
	WarpDamage = 220.0f;
	WarpRange = 600.0f;
}

void UGA_GarrettSmokeWarp::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (!ActorInfo || !ActorInfo->AvatarActor.IsValid())
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
		return;
	}

	AActor* Avatar = ActorInfo->AvatarActor.Get();
	FVector StartLoc = Avatar->GetActorLocation();

	TArray<AActor*> OverlappedActors;
	TArray<AActor*> IgnoreActors;
	IgnoreActors.Add(Avatar);

	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));

	UKismetSystemLibrary::SphereOverlapActors(
		Avatar->GetWorld(),
		StartLoc,
		WarpRange,
		ObjectTypes,
		APawn::StaticClass(),
		IgnoreActors,
		OverlappedActors
	);

	for (AActor* Target : OverlappedActors)
	{
		if (Target && Target != Avatar)
		{
			FVector TargetLoc = Target->GetActorLocation();
			FVector TargetBack = TargetLoc - (Target->GetActorForwardVector() * 100.0f);

			// Teleport Garrett behind target
			Avatar->SetActorLocation(TargetBack);

			if (UAshenOath_HealthComponent* Health = Target->FindComponentByClass<UAshenOath_HealthComponent>())
			{
				Health->ReceiveDamage(WarpDamage, Avatar);
			}

			if (GetWorld())
			{
				if (UAshenVFXPoolSubsystem* VFXPool = GetWorld()->GetSubsystem<UAshenVFXPoolSubsystem>())
				{
					VFXPool->SpawnPooledVFX(FName("VFX_SmokePuffExplosion"), TargetBack, FRotator::ZeroRotator);
				}
			}

			OnWarpExecuted.Broadcast(Target, TargetBack, WarpDamage);
			UE_LOG(LogTemp, Warning, TEXT("UGA_GarrettSmokeWarp: Garrett warp struck '%s' for %.1f critical damage!"), *Target->GetName(), WarpDamage);

			break; // Warp strike first valid target
		}
	}

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
