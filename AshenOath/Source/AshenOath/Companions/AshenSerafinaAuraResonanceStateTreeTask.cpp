// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenSerafinaAuraResonanceStateTreeTask.h"

UAshenSerafinaAuraResonanceStateTreeTask::UAshenSerafinaAuraResonanceStateTreeTask()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenSerafinaAuraResonanceStateTreeTask::CalculateAuraPulseRadius(float SerafinaTrust) const
{
	float AuraRadius = 400.0f + (SerafinaTrust * 400.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenSerafinaAuraResonanceStateTreeTask: Calculated Serafina aura pulse radius: %.1f units"), AuraRadius);
	return AuraRadius;
}
