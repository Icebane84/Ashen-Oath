// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 543: Ashen Consecrated Circle Actor

#include "AshenConsecratedCircleActor.h"
#include "AshenOath_HealthComponent.h"
#include "Kismet/KismetSystemLibrary.h"

AAshenConsecratedCircleActor::AAshenConsecratedCircleActor()
{
	PrimaryActorTick.bCanEverTick = false;
	CircleRadius = 600.0f;
	HealPerPulse = 80.0f;
	BurnDamagePerPulse = 120.0f;
}

void AAshenConsecratedCircleActor::PulseConsecratedCircle()
{
	const FVector Origin = GetActorLocation();

	TArray<AActor*> HitActors;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));

	UKismetSystemLibrary::SphereOverlapActors(
		GetWorld(),
		Origin,
		CircleRadius,
		ObjectTypes,
		AActor::StaticClass(),
		TArray<AActor*>{ this },
		HitActors
	);

	for (AActor* Target : HitActors)
	{
		if (!Target || Target == this) continue;

		UAshenOath_HealthComponent* TargetHealth = Target->FindComponentByClass<UAshenOath_HealthComponent>();
		if (TargetHealth)
		{
			TargetHealth->Heal(HealPerPulse);
		}
	}

	OnCirclePulse.Broadcast(Origin, CircleRadius);

	UE_LOG(LogTemp, Log, TEXT("AAshenConsecratedCircleActor: CONSECRATED CIRCLE PULSED at (%s) — Radius: %.0fu | Heal: %.0f HP."),
		*Origin.ToString(), CircleRadius, HealPerPulse);
}
