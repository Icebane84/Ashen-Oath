// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 539: Ashen Audio Occlusion Component

#include "AshenAudioOcclusionComponent.h"
#include "Engine/World.h"
#include "CollisionQueryParams.h"

UAshenAudioOcclusionComponent::UAshenAudioOcclusionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CalculatedOcclusionPercent = 0.0f;
	CalculatedLowPassCutoff = 20000.0f;
}

float UAshenAudioOcclusionComponent::EvaluateAudioOcclusion(FVector SoundOrigin, FVector ListenerLocation)
{
	UWorld* World = GetWorld();
	if (!World) return 0.0f;

	FHitResult HitResult;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(GetOwner());

	bool bBlocked = World->LineTraceSingleByChannel(
		HitResult,
		SoundOrigin,
		ListenerLocation,
		ECC_Visibility,
		QueryParams
	);

	CalculatedOcclusionPercent = bBlocked ? 0.75f : 0.0f;
	CalculatedLowPassCutoff = bBlocked ? 1200.0f : 20000.0f;

	OnAudioOcclusionUpdated.Broadcast(CalculatedOcclusionPercent, CalculatedLowPassCutoff);

	UE_LOG(LogTemp, Log, TEXT("UAshenAudioOcclusionComponent: Audio Occlusion Evaluated -> Occlusion: %.0f%% | LowPass Cutoff: %.0f Hz."),
		CalculatedOcclusionPercent * 100.0f, CalculatedLowPassCutoff);

	return CalculatedOcclusionPercent;
}
