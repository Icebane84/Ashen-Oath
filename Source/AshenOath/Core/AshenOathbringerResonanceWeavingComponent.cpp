// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 321: Ashen Oathbringer Resonance Weaving Component

#include "AshenOathbringerResonanceWeavingComponent.h"
#include "AshenOath_HealthComponent.h"

UAshenOathbringerResonanceWeavingComponent::UAshenOathbringerResonanceWeavingComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenOathbringerResonanceWeavingComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenOathbringerResonanceWeavingComponent::ExecuteResonanceFinisher(EAshenFinisherResonance FinisherType, AActor* TargetActor)
{
	const float BaseFinisherDamage = (FinisherType == EAshenFinisherResonance::RadiantFlameFinisher) ? 240.0f : 310.0f;

	if (TargetActor)
	{
		UAshenOath_HealthComponent* HealthComp = TargetActor->FindComponentByClass<UAshenOath_HealthComponent>();
		if (HealthComp)
		{
			HealthComp->ReceiveDamage(BaseFinisherDamage, GetOwner());
		}
	}

	OnResonanceFinisherExecuted.Broadcast(FinisherType, BaseFinisherDamage);

	UE_LOG(LogTemp, Warning, TEXT("UAshenOathbringerResonanceWeavingComponent: RESONANCE FINISHER %d EXECUTED — Dealt %.0f Damage to '%s'."),
		(int32)FinisherType, BaseFinisherDamage, TargetActor ? *TargetActor->GetName() : TEXT("Unknown"));
}
