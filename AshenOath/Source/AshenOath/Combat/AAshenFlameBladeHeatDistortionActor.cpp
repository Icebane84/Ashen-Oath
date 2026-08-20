// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AAshenFlameBladeHeatDistortionActor.h"

AAshenFlameBladeHeatDistortionActor::AAshenFlameBladeHeatDistortionActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenFlameBladeHeatDistortionActor::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	HeatHazeStrength = 1.0f + (NewState.Corruption * 2.0f);
	UE_LOG(LogTemp, Log, TEXT("AAshenFlameBladeHeatDistortionActor: Heat haze strength set to %.2f"), HeatHazeStrength);
}
