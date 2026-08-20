// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 818: Ashen Forearm Runic Input Etch Visual Locus Actor

#include "AshenForearmRunicInputEtchVisualLocusActor.h"

AAshenForearmRunicInputEtchVisualLocusActor::AAshenForearmRunicInputEtchVisualLocusActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsInputEtched = false;
}

void AAshenForearmRunicInputEtchVisualLocusActor::TriggerForearmRunicInputEtch(float Intensity)
{
	bIsInputEtched = true;
	OnRunicInputEtched.Broadcast(GetActorLocation(), Intensity);

	UE_LOG(LogTemp, Warning, TEXT("AAshenForearmRunicInputEtchVisualLocusActor: FOREARM RUNIC INPUT ETCHED IN-WORLD -> Location: (%s) | Inputs: [LT + RT] | Pulse Intensity: %.2fx."),
		*GetActorLocation().ToString(), Intensity);
}
