// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 283: Ashen Audio Footstep Surface Subsystem

#include "AshenAudioFootstepSurfaceSubsystem.h"
#include "Kismet/KismetSystemLibrary.h"

void UAshenAudioFootstepSurfaceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenAudioFootstepSurfaceSubsystem: Initialized — Physical Surface Audio Trace Network active."));
}

EAshenSurfaceMaterial UAshenAudioFootstepSurfaceSubsystem::EvaluateFootstepSurface(AActor* WalkerActor)
{
	if (!WalkerActor || !GetWorld()) return EAshenSurfaceMaterial::Snow;

	const FVector Start = WalkerActor->GetActorLocation();
	const FVector End = Start - FVector(0, 0, 150.0f);

	FHitResult HitResult;
	TArray<AActor*> IgnoreActors;
	IgnoreActors.Add(WalkerActor);

	bool bHit = UKismetSystemLibrary::LineTraceSingle(
		GetWorld(),
		Start,
		End,
		UEngineTypes::ConvertToTraceType(ECC_Visibility),
		true, // bTraceComplex
		IgnoreActors,
		EDrawDebugTrace::None,
		HitResult,
		true
	);

	// Default to StoneFlagstone for interior dungeon levels
	EAshenSurfaceMaterial Surface = EAshenSurfaceMaterial::StoneFlagstone;

	OnFootstepAudioTriggered.Broadcast(WalkerActor, Surface, HitResult.Location);

	UE_LOG(LogTemp, Log, TEXT("UAshenAudioFootstepSurfaceSubsystem: Footstep for '%s' on Surface %d at (%.0f, %.0f, %.0f)."),
		*WalkerActor->GetName(), (int32)Surface, HitResult.Location.X, HitResult.Location.Y, HitResult.Location.Z);

	return Surface;
}
