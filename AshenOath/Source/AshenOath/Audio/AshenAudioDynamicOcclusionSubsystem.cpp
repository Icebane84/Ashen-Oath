// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 223: Ashen Audio Dynamic Occlusion Subsystem

#include "AshenAudioDynamicOcclusionSubsystem.h"
#include "Kismet/KismetSystemLibrary.h"

void UAshenAudioDynamicOcclusionSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	MaxCutoffFrequency = 20000.0f;
	MinCutoffFrequency = 800.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenAudioDynamicOcclusionSubsystem: Initialized — Dynamic Audio Raycast Occlusion active."));
}

float UAshenAudioDynamicOcclusionSubsystem::CalculateOcclusionFrequency(AActor* Listener, AActor* SoundSource)
{
	if (!Listener || !SoundSource || !GetWorld()) return MaxCutoffFrequency;

	const FVector Start = Listener->GetActorLocation();
	const FVector End = SoundSource->GetActorLocation();

	FHitResult HitResult;
	TArray<AActor*> IgnoreActors;
	IgnoreActors.Add(Listener);
	IgnoreActors.Add(SoundSource);

	bool bBlocked = UKismetSystemLibrary::LineTraceSingle(
		GetWorld(),
		Start,
		End,
		UEngineTypes::ConvertToTraceType(ECC_Visibility),
		false,
		IgnoreActors,
		EDrawDebugTrace::None,
		HitResult,
		true
	);

	const float FinalFrequency = bBlocked ? MinCutoffFrequency : MaxCutoffFrequency;
	OnAudioOcclusionUpdated.Broadcast(SoundSource, FinalFrequency);

	UE_LOG(LogTemp, Log, TEXT("UAshenAudioDynamicOcclusionSubsystem: Sound source '%s' occlusion check — %s (Frequency: %.0f Hz)."),
		*SoundSource->GetName(), bBlocked ? TEXT("OCCLUDED") : TEXT("CLEAR"), FinalFrequency);

	return FinalFrequency;
}
