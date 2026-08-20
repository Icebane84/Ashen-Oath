// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 792: Ashen Weapon Scuff Texture Visual Locus Actor

#include "AshenWeaponScuffTextureVisualLocusActor.h"

AAshenWeaponScuffTextureVisualLocusActor::AAshenWeaponScuffTextureVisualLocusActor()
{
	PrimaryActorTick.bCanEverTick = false;
	ActiveScuffMaskBlend = 0.0f;
}

void AAshenWeaponScuffTextureVisualLocusActor::UpdateScuffTextureBlend(float WearPercent)
{
	ActiveScuffMaskBlend = FMath::Clamp(WearPercent / 100.0f, 0.0f, 1.0f);
	const bool bWorn = (ActiveScuffMaskBlend >= 0.8f);

	OnScuffTextureUpdated.Broadcast(ActiveScuffMaskBlend, bWorn);

	UE_LOG(LogTemp, Warning, TEXT("AAshenWeaponScuffTextureVisualLocusActor: SCUFF TEXTURE BLEND UPDATED -> Blend: %.2f | Fully Worn: %s."),
		ActiveScuffMaskBlend, bWorn ? TEXT("TRUE") : TEXT("FALSE"));
}
