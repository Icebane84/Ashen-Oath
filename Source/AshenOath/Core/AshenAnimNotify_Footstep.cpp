// Copyright Phoenix Protocol. All rights reserved.

#include "AshenAnimNotify_Footstep.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "AshenOath_GameEventSubsystem.h"
#include "Engine/World.h"

UAshenAnimNotify_Footstep::UAshenAnimNotify_Footstep()
{
	FootSocketName = TEXT("foot_r");
	TraceRange = 50.0f;
	FootstepSound = nullptr;
}

void UAshenAnimNotify_Footstep::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if (!MeshComp || !MeshComp->GetWorld()) return;

	FVector StartLoc = MeshComp->GetSocketLocation(FootSocketName);
	FVector EndLoc = StartLoc - (FVector::UpVector * TraceRange);

	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(MeshComp->GetOwner());

	bool bHit = MeshComp->GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLoc,
		EndLoc,
		ECC_Visibility,
		Params
	);

	// Fallback to playing at the socket location if no floor is hit immediately underneath
	FVector PlayLocation = bHit ? HitResult.ImpactPoint : StartLoc;
	FVector PlayNormal = bHit ? HitResult.ImpactNormal : FVector::UpVector;

	if (FootstepSound)
	{
		float RandomPitch = FMath::RandRange(0.85f, 1.15f);
		UGameplayStatics::PlaySoundAtLocation(
			MeshComp->GetWorld(),
			FootstepSound,
			PlayLocation,
			1.0f,
			RandomPitch
		);
	}

	// Dispatch event to global event bus for VFX or decals
	if (UGameInstance* GI = MeshComp->GetWorld()->GetGameInstance())
	{
		if (UAshenOath_GameEventSubsystem* GameEvents = GI->GetSubsystem<UAshenOath_GameEventSubsystem>())
		{
			GameEvents->BroadcastFootstepOccurred(PlayLocation, PlayNormal);
		}
	}
}
