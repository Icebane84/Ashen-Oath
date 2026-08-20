// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenCollapseAudioVisualDistorterComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Actor.h"

UAshenCollapseAudioVisualDistorterComponent::UAshenCollapseAudioVisualDistorterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentDistortionIntensity = 0.0f;
	CurrentAudioLowPassFreq = 20000.0f;
}

void UAshenCollapseAudioVisualDistorterComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenCollapseAudioVisualDistorterComponent::UpdateCollapseDistortion(int32 CollapseStage)
{
	int32 ClampedStage = FMath::Clamp(CollapseStage, 0, 4);

	switch (ClampedStage)
	{
	case 1:
		CurrentDistortionIntensity = 0.2f;
		CurrentAudioLowPassFreq = 14000.0f;
		break;
	case 2:
		CurrentDistortionIntensity = 0.45f;
		CurrentAudioLowPassFreq = 8000.0f;
		break;
	case 3:
		CurrentDistortionIntensity = 0.65f;
		CurrentAudioLowPassFreq = 3000.0f;
		break;
	case 4:
		CurrentDistortionIntensity = 0.85f;
		CurrentAudioLowPassFreq = 800.0f;
		break;
	default:
		CurrentDistortionIntensity = 0.0f;
		CurrentAudioLowPassFreq = 20000.0f;
		break;
	}

	OnDistortionUpdated.Broadcast(CurrentDistortionIntensity, CurrentAudioLowPassFreq);
	UE_LOG(LogTemp, Warning, TEXT("UAshenCollapseAudioVisualDistorterComponent: Collapse stage %d distorter active (Intensity: %.2f, LPF: %.0fHz)."),
		ClampedStage, CurrentDistortionIntensity, CurrentAudioLowPassFreq);
}
