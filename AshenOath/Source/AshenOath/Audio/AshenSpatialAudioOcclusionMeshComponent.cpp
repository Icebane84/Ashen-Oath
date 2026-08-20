// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 402: Ashen Spatial Audio Occlusion Mesh Component

#include "AshenSpatialAudioOcclusionMeshComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UAshenSpatialAudioOcclusionMeshComponent::UAshenSpatialAudioOcclusionMeshComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSpatialAudioOcclusionMeshComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenSpatialAudioOcclusionMeshComponent::CalculateSpatialOcclusion(FVector SoundOrigin, FVector ListenerPosition)
{
	AActor* Owner = GetOwner();
	if (!Owner) return;

	FHitResult Hit;
	bool bOccluded = UKismetSystemLibrary::LineTraceSingle(
		Owner->GetWorld(),
		SoundOrigin,
		ListenerPosition,
		UEngineTypes::ConvertToTraceType(ECC_Visibility),
		false,
		TArray<AActor*>{ Owner },
		EDrawDebugTrace::None,
		Hit,
		true
	);

	const float Loss = bOccluded ? 18.0f : 0.0f;
	const float Cutoff = bOccluded ? 1200.0f : 20000.0f;

	OnOcclusionCalculated.Broadcast(Loss, Cutoff);

	UE_LOG(LogTemp, Log, TEXT("UAshenSpatialAudioOcclusionMeshComponent: SPATIAL OCCLUSION -> Loss: %.1f dB, Cutoff: %.0f Hz."),
		Loss, Cutoff);
}
