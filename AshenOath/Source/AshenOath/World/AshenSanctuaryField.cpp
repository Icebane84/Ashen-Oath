// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenSanctuaryField.h"
#include "Components/SphereComponent.h"
#include "Combat/AshenOath_StaminaComponent.h"
#include "GameFramework/Character.h"

AAshenSanctuaryField::AAshenSanctuaryField()
{
	PrimaryActorTick.bCanEverTick = false;

	FieldSphere = CreateDefaultSubobject<USphereComponent>(TEXT("FieldSphere"));
	FieldSphere->InitSphereRadius(FieldRadius);
	FieldSphere->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	FieldSphere->SetGenerateOverlapEvents(true);
	RootComponent = FieldSphere;
}

void AAshenSanctuaryField::BeginPlay()
{
	Super::BeginPlay();

	FieldSphere->SetSphereRadius(FieldRadius);
	FieldSphere->OnComponentBeginOverlap.AddDynamic(this, &AAshenSanctuaryField::OnFieldBeginOverlap);
	FieldSphere->OnComponentEndOverlap.AddDynamic(this, &AAshenSanctuaryField::OnFieldEndOverlap);

	if (LifetimeSeconds > 0.0f)
	{
		SetLifeSpan(LifetimeSeconds);
	}

	UE_LOG(LogTemp, Log, TEXT("AAshenSanctuaryField: Spawned sacred barrier field (Radius: %.1f, Multiplier: %.1fx)."),
		FieldRadius, StaminaAccelerationMultiplier);
}

void AAshenSanctuaryField::OnFieldBeginOverlap(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this && !OverlappingAllies.Contains(OtherActor))
	{
		OverlappingAllies.Add(OtherActor);

		// Boost stamina regeneration rate on ally stamina component
		if (UAshenOath_StaminaComponent* StaminaComp = OtherActor->FindComponentByClass<UAshenOath_StaminaComponent>())
		{
			StaminaComp->SetRegenRate(StaminaComp->GetRegenRate() * StaminaAccelerationMultiplier);
		}

		UE_LOG(LogTemp, Log, TEXT("AAshenSanctuaryField: Ally %s entered sanctuary field (+250%% stamina acceleration active)."),
			*OtherActor->GetName());
	}
}

void AAshenSanctuaryField::OnFieldEndOverlap(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	if (OtherActor && OverlappingAllies.Contains(OtherActor))
	{
		OverlappingAllies.Remove(OtherActor);

		// Restore stamina regeneration rate
		if (UAshenOath_StaminaComponent* StaminaComp = OtherActor->FindComponentByClass<UAshenOath_StaminaComponent>())
		{
			StaminaComp->SetRegenRate(StaminaComp->GetRegenRate() / StaminaAccelerationMultiplier);
		}

		UE_LOG(LogTemp, Log, TEXT("AAshenSanctuaryField: Ally %s exited sanctuary field."), *OtherActor->GetName());
	}
}

bool AAshenSanctuaryField::IsActorProtectedBySanctuary(const AActor* ActorToCheck) const
{
	return ActorToCheck && OverlappingAllies.Contains(ActorToCheck);
}
