// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenSanctuaryHeartstoneLuminescenceModulatorActor.h"

AAshenSanctuaryHeartstoneLuminescenceModulatorActor::AAshenSanctuaryHeartstoneLuminescenceModulatorActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenSanctuaryHeartstoneLuminescenceModulatorActor::ModulateHearthLuminescence(const FSoulStateVector& Vector)
{
	UE_LOG(LogTemp, Log, TEXT("AAshenSanctuaryHeartstoneLuminescenceModulatorActor: Heartstone hearth luminescence modulated (Resolve: %.2f, Corruption: %.2f)"),
		Vector.Resolve, Vector.Corruption);
}
