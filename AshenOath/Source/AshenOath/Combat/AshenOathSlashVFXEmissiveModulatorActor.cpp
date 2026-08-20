// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenOathSlashVFXEmissiveModulatorActor.h"

AAshenOathSlashVFXEmissiveModulatorActor::AAshenOathSlashVFXEmissiveModulatorActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenOathSlashVFXEmissiveModulatorActor::ModulateSlashEmissive(float Corruption)
{
	UE_LOG(LogTemp, Log, TEXT("AAshenOathSlashVFXEmissiveModulatorActor: Oath Slash particle emissive brightness modulated (Corruption: %.2f)"), Corruption);
}
