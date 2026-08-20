// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenSomaticIntrusionTotemActor.h"

AAshenSomaticIntrusionTotemActor::AAshenSomaticIntrusionTotemActor()
{
	PrimaryActorTick.bCanEverTick = false;
	ResonanceAuraRadius = 1500.0f;
	bIsTotemAwakened = false;
}
void AAshenSomaticIntrusionTotemActor::BeginPlay() { Super::BeginPlay(); }

bool AAshenSomaticIntrusionTotemActor::AwakenTotem(AActor* InstigatingPlayer)
{
	if (!InstigatingPlayer) return false;
	bIsTotemAwakened = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenSomaticIntrusionTotemActor: Somatic Intrusion Totem awakened (Radius: %.1fuu)!"),
		ResonanceAuraRadius);
	return true;
}
