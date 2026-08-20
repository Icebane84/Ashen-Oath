// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 817: Ashen Diegetic Vein Creep Shader Component

#include "AshenDiegeticVeinCreepShaderComponent.h"

UAshenDiegeticVeinCreepShaderComponent::UAshenDiegeticVeinCreepShaderComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	ActiveVeinCoverage = 0.0f;
}

void UAshenDiegeticVeinCreepShaderComponent::UpdateVeinCreepCoverage(float ProgressNormalized)
{
	ActiveVeinCoverage = FMath::Clamp(ProgressNormalized, 0.0f, 1.0f);
	const float PulseFreq = 1.0f + (ActiveVeinCoverage * 2.0f);

	OnVeinCreepUpdated.Broadcast(ActiveVeinCoverage, PulseFreq);

	UE_LOG(LogTemp, Warning, TEXT("UAshenDiegeticVeinCreepShaderComponent: VEIN CREEP COVERAGE UPDATED -> Coverage: %.2f | Pulse Freq: %.2fx."),
		ActiveVeinCoverage, PulseFreq);
}
