// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 288: Ashen Boss Aura Buff Controller Component

#include "AshenBossAuraBuffControllerComponent.h"
#include "AshenOath_HealthComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UAshenBossAuraBuffControllerComponent::UAshenBossAuraBuffControllerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	AuraDamagePerPulse = 25.0f;
	AuraRadius = 400.0f;
}

void UAshenBossAuraBuffControllerComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenBossAuraBuffControllerComponent::PulseAuraDamage()
{
	AActor* Owner = GetOwner();
	if (!Owner || !GetWorld()) return;

	const FVector Origin = Owner->GetActorLocation();

	TArray<AActor*> HitActors;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));

	UKismetSystemLibrary::SphereOverlapActors(
		GetWorld(),
		Origin,
		AuraRadius,
		ObjectTypes,
		AActor::StaticClass(),
		TArray<AActor*>{ Owner },
		HitActors
	);

	for (AActor* Target : HitActors)
	{
		if (!Target || Target == Owner) continue;

		UAshenOath_HealthComponent* HealthComp = Target->FindComponentByClass<UAshenOath_HealthComponent>();
		if (HealthComp)
		{
			HealthComp->ReceiveDamage(AuraDamagePerPulse, Owner);
		}
	}

	OnAuraPulse.Broadcast(AuraDamagePerPulse, AuraRadius);

	UE_LOG(LogTemp, Log, TEXT("UAshenBossAuraBuffControllerComponent: Boss Aura Pulsed — %.0f damage in %.0fu radius."),
		AuraDamagePerPulse, AuraRadius);
}
