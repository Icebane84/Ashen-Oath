// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 743: Ashen Whispering Void Erosion Volume

#include "AshenWhisperingVoidErosionVolume.h"

AAshenWhisperingVoidErosionVolume::AAshenWhisperingVoidErosionVolume()
{
	PrimaryActorTick.bCanEverTick = false;
	ActiveErosionRate = 5.0f;
}

void AAshenWhisperingVoidErosionVolume::ApplyVoidErosionToActor(AActor* TargetActor, float ErosionRate)
{
	if (!TargetActor) return;

	ActiveErosionRate = ErosionRate;
	OnVoidErosionApplied.Broadcast(TargetActor, ActiveErosionRate);

	UE_LOG(LogTemp, Warning, TEXT("AAshenWhisperingVoidErosionVolume: VOID EROSION APPLIED -> Actor '%s' | Erosion Rate: +%.1f%%/sec."),
		*TargetActor->GetName(), ActiveErosionRate);
}
