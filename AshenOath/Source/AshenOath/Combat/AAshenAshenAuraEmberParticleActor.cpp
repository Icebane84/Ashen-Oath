// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AAshenAshenAuraEmberParticleActor.h"

AAshenAshenAuraEmberParticleActor::AAshenAshenAuraEmberParticleActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenAshenAuraEmberParticleActor::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	EmberSpawnRateMultiplier = (NewState.Corruption > 0.5f) ? ((NewState.Corruption - 0.5f) * 4.0f) : 0.0f;
	UE_LOG(LogTemp, Log, TEXT("AAshenAshenAuraEmberParticleActor: Ember spawn rate multiplier set to %.2f"), EmberSpawnRateMultiplier);
}
