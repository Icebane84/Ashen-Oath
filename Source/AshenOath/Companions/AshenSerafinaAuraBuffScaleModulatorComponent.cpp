// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenSerafinaAuraBuffScaleModulatorComponent.h"

UAshenSerafinaAuraBuffScaleModulatorComponent::UAshenSerafinaAuraBuffScaleModulatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSerafinaAuraBuffScaleModulatorComponent::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	BuffPotency = FMath::Clamp(NewState.SerafinaTrust * 2.0f, 0.2f, 2.5f);
	UE_LOG(LogTemp, Log, TEXT("UAshenSerafinaAuraBuffScaleModulatorComponent: Serafina aura buff potency updated to %.2f"), BuffPotency);
}
