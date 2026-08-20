// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 458: Ashen Party Stat Synergy Subsystem

#include "AshenPartyStatSynergySubsystem.h"
#include "Kismet/KismetSystemLibrary.h"

void UAshenPartyStatSynergySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	CurrentSynergyMultiplier = 1.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenPartyStatSynergySubsystem: Initialized — Party Stat Synergy Subsystem ONLINE."));
}

float UAshenPartyStatSynergySubsystem::EvaluatePartyProximitySynergy(AActor* KaelenActor, float ProximityRadius)
{
	if (!KaelenActor) return 1.0f;

	TArray<AActor*> NearbyActors;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));

	UKismetSystemLibrary::SphereOverlapActors(
		KaelenActor->GetWorld(),
		KaelenActor->GetActorLocation(),
		ProximityRadius,
		ObjectTypes,
		AActor::StaticClass(),
		TArray<AActor*>{ KaelenActor },
		NearbyActors
	);

	int32 CompanionCount = FMath::Min(NearbyActors.Num(), 2);
	CurrentSynergyMultiplier = 1.0f + (CompanionCount * 0.15f);

	OnPartySynergyUpdated.Broadcast(CurrentSynergyMultiplier, CompanionCount);

	UE_LOG(LogTemp, Warning, TEXT("UAshenPartyStatSynergySubsystem: PROXIMITY SYNERGY EVALUATED -> %d Companions nearby (Synergy Multiplier: %.2fx)."),
		CompanionCount, CurrentSynergyMultiplier);

	return CurrentSynergyMultiplier;
}
