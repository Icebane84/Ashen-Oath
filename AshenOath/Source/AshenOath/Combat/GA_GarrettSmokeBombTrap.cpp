// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 207: GA_GarrettSmokeBombTrap

#include "GA_GarrettSmokeBombTrap.h"
#include "Kismet/KismetSystemLibrary.h"

UGA_GarrettSmokeBombTrap::UGA_GarrettSmokeBombTrap()
{
	TrapRadius = 350.0f;
	SlowPercentage = 0.40f;
	EffectDuration = 5.0f;
}

void UGA_GarrettSmokeBombTrap::ActivateAbility(
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

	const FVector Location = Owner->GetActorLocation();

	TArray<AActor*> OverlappingActors;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));

	UKismetSystemLibrary::SphereOverlapActors(
		Owner->GetWorld(),
		Location,
		TrapRadius,
		ObjectTypes,
		AActor::StaticClass(),
		TArray<AActor*>{ Owner },
		OverlappingActors
	);

	UE_LOG(LogTemp, Warning, TEXT("UGA_GarrettSmokeBombTrap: SMOKE BOMB TRAP DETONATED at (%.0f, %.0f, %.0f) — %.0f%% slow & blind applied to %d targets for %.0fs."),
		Location.X, Location.Y, Location.Z, SlowPercentage * 100.0f, OverlappingActors.Num(), EffectDuration);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
