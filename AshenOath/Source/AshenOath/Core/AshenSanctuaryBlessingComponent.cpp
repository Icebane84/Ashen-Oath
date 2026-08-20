// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenSanctuaryBlessingComponent.h"
#include "AshenOath_HealthComponent.h"
#include "AshenOath_SanityComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GameFramework/Pawn.h"

UAshenSanctuaryBlessingComponent::UAshenSanctuaryBlessingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	HealingRate = 5.0f;
	SanityRestorationRate = 5.0f;
	BlessingRadius = 400.0f;
}

void UAshenSanctuaryBlessingComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenSanctuaryBlessingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* OwnerActor = GetOwner();
	if (!OwnerActor || !GetWorld()) return;

	FVector Origin = OwnerActor->GetActorLocation();
	TArray<AActor*> OverlappedActors;
	TArray<AActor*> IgnoreActors;

	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));

	UKismetSystemLibrary::SphereOverlapActors(
		GetWorld(),
		Origin,
		BlessingRadius,
		ObjectTypes,
		APawn::StaticClass(),
		IgnoreActors,
		OverlappedActors
	);

	float HealedThisTick = HealingRate * DeltaTime;
	float SanityThisTick = SanityRestorationRate * DeltaTime;

	for (AActor* Ally : OverlappedActors)
	{
		if (!Ally) continue;

		if (UAshenOath_HealthComponent* Health = Ally->FindComponentByClass<UAshenOath_HealthComponent>())
		{
			Health->Heal(HealedThisTick);
		}

		if (UAshenOath_SanityComponent* Sanity = Ally->FindComponentByClass<UAshenOath_SanityComponent>())
		{
			Sanity->HealSanity(SanityThisTick);
		}
	}

	OnBlessingApplied.Broadcast(HealedThisTick, SanityThisTick);
}
