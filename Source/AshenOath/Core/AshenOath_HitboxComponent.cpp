// Fill out your copyright notice in the Description page of Project Settings.


#include "AshenOath_HitboxComponent.h"
#include "AshenOath_HurtboxComponent.h"
#include "AshenCombatCharacter.h"
#include "AshenOath_SanityComponent.h"

UAshenOath_HitboxComponent::UAshenOath_HitboxComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	Damage = 10.0f;
	PoiseDamage = 20.0f;
	TeamId = 0;

	SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	SetGenerateOverlapEvents(true);
}

void UAshenOath_HitboxComponent::BeginPlay()
{
	Super::BeginPlay();

	OnComponentBeginOverlap.AddDynamic(this, &UAshenOath_HitboxComponent::OnOverlapBegin);
}

void UAshenOath_HitboxComponent::ActivateOneShot()
{
	SetCollisionEnabled(ECollisionEnabled::QueryOnly);

	TArray<UPrimitiveComponent*> LocalOverlappingComponents;
	GetOverlappingComponents(LocalOverlappingComponents);

	for (UPrimitiveComponent* OverlappedComp : LocalOverlappingComponents)
	{
		if (UAshenOath_HurtboxComponent* Hurtbox = Cast<UAshenOath_HurtboxComponent>(OverlappedComp))
		{
			if (Hurtbox->GetTeamId() != TeamId)
			{
				Hurtbox->ReceiveDamage(Damage, PoiseDamage, GetOwner());
				OnHitRegistered.Broadcast(GetComponentLocation(), Damage, PoiseDamage);

				// If owner is a weapon actor and its owner is the combat character, apply impact triggers
				if (AActor* WeaponActor = GetOwner())
				{
					if (AActor* CharActor = WeaponActor->GetOwner())
					{
						if (AAshenCombatCharacter* CombatChar = Cast<AAshenCombatCharacter>(CharActor))
						{
							CombatChar->TriggerStrikeImpact();

							// Recover a fraction of sanity on hit
							if (UAshenOath_SanityComponent* Sanity = IAshenCharacterInterface::Execute_GetSanityComponent(CombatChar))
							{
								Sanity->HealSanity(3.5f);
							}
						}
					}
				}
			}
		}
	}

	SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void UAshenOath_HitboxComponent::OnOverlapBegin(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult
)
{
	if (!OtherComp) return;

	UAshenOath_HurtboxComponent* Hurtbox = Cast<UAshenOath_HurtboxComponent>(OtherComp);
	if (Hurtbox)
	{
		if (Hurtbox->GetTeamId() != TeamId)
		{
			Hurtbox->ReceiveDamage(Damage, PoiseDamage, GetOwner());
			OnHitRegistered.Broadcast(GetComponentLocation(), Damage, PoiseDamage);

			// If owner is a weapon actor and its owner is the combat character, apply impact triggers
			if (AActor* WeaponActor = GetOwner())
			{
				if (AActor* CharActor = WeaponActor->GetOwner())
				{
					if (AAshenCombatCharacter* CombatChar = Cast<AAshenCombatCharacter>(CharActor))
					{
						CombatChar->TriggerStrikeImpact();

						// Recover a fraction of sanity on hit
						if (UAshenOath_SanityComponent* Sanity = IAshenCharacterInterface::Execute_GetSanityComponent(CombatChar))
						{
							Sanity->HealSanity(3.5f);
						}
					}
				}
			}
		}
	}
}
