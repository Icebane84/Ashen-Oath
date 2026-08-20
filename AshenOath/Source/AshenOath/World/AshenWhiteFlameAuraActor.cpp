// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenWhiteFlameAuraActor.h"

AAshenWhiteFlameAuraActor::AAshenWhiteFlameAuraActor()
{
	PrimaryActorTick.bCanEverTick = false;
	AuraIncandescenceGlow = 4.0f;
}
void AAshenWhiteFlameAuraActor::BeginPlay() { Super::BeginPlay(); }

void AAshenWhiteFlameAuraActor::SetAuraActive(bool bActive)
{
	UE_LOG(LogTemp, Log, TEXT("AAshenWhiteFlameAuraActor: White Flame Volumetric Aura: %s (Glow: %.1f)"),
		bActive ? TEXT("ACTIVE") : TEXT("INACTIVE"), AuraIncandescenceGlow);
}
