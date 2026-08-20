// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "GA_KaelenUnchainedBerserk.h"
#include "AshenOath_SanityComponent.h"
#include "AshenOath_StaminaComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Kismet/KismetSystemLibrary.h"
#include "TimerManager.h"

UGA_KaelenUnchainedBerserk::UGA_KaelenUnchainedBerserk()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	CorruptionThreshold = 0.70f;
	BerserkDuration = 8.0f;
	CorruptionSpike = 0.15f;
	CollateralSanityDamage = 15.0f;
	PsychicBleedRadius = 500.0f;
}

bool UGA_KaelenUnchainedBerserk::CanActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayTagContainer* SourceTags,
	const FGameplayTagContainer* TargetTags,
	OUT FGameplayTagContainer* OptionalRelevantTags) const
{
	if (!Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags))
	{
		return false;
	}

	// Verify corruption threshold gate via tracked berserk state
	return bCorruptionGateOpen;
}

void UGA_KaelenUnchainedBerserk::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	AActor* Avatar = ActorInfo ? ActorInfo->AvatarActor.Get() : nullptr;
	if (!Avatar)
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("GA_KaelenUnchainedBerserk: UNCHAINED activated! Glass Shield Protocol broken."));

	// 1. Surge Stamina to max — represents brief frenzy energy release
	if (UAshenOath_StaminaComponent* Stamina = Avatar->FindComponentByClass<UAshenOath_StaminaComponent>())
	{
		Stamina->SetCurrentStamina(Stamina->GetMaxStamina());
		UE_LOG(LogTemp, Log, TEXT("GA_KaelenUnchainedBerserk: Stamina surge to max (%.1f)"), Stamina->GetMaxStamina());
	}

	// 2. Collateral psychic bleed — inflict Sanity damage on nearby Pawn actors in PsychicBleedRadius
	TArray<AActor*> OverlappedActors;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn));

	UKismetSystemLibrary::SphereOverlapActors(
		Avatar->GetWorld(),
		Avatar->GetActorLocation(),
		PsychicBleedRadius,
		ObjectTypes,
		AActor::StaticClass(),
		TArray<AActor*>{ Avatar },
		OverlappedActors);

	for (AActor* Nearby : OverlappedActors)
	{
		if (UAshenOath_SanityComponent* NearbySanity = Nearby->FindComponentByClass<UAshenOath_SanityComponent>())
		{
			NearbySanity->SufferMentalDamage(CollateralSanityDamage);
			UE_LOG(LogTemp, Log, TEXT("GA_KaelenUnchainedBerserk: Psychic bleed hit %s for %.1f Sanity damage"), *Nearby->GetName(), CollateralSanityDamage);
		}
	}

	// 3. Schedule berserk end after BerserkDuration
	FTimerDelegate EndDelegate;
	EndDelegate.BindUObject(this, &UGA_KaelenUnchainedBerserk::EndBerserkState, Handle, ActorInfo, ActivationInfo);
	Avatar->GetWorld()->GetTimerManager().SetTimer(BerserkEndTimerHandle, EndDelegate, BerserkDuration, false);
}

void UGA_KaelenUnchainedBerserk::EndBerserkState(FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, FGameplayAbilityActivationInfo ActivationInfo)
{
	UE_LOG(LogTemp, Log, TEXT("GA_KaelenUnchainedBerserk: Berserk state ended after %.1fs"), BerserkDuration);
	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
