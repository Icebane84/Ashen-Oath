// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenSerafinaAuraResonanceVisualizerComponent.h"

UAshenSerafinaAuraResonanceVisualizerComponent::UAshenSerafinaAuraResonanceVisualizerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSerafinaAuraResonanceVisualizerComponent::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	AuraBrightness = FMath::Clamp(NewState.SerafinaTrust * 3.0f, 0.2f, 4.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenSerafinaAuraResonanceVisualizerComponent: Serafina aura brightness updated to %.2f"), AuraBrightness);
}
