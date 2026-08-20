// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenStaggeredCrisisTimelineController.h"

UAshenStaggeredCrisisTimelineController::UAshenStaggeredCrisisTimelineController()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenStaggeredCrisisTimelineController::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenStaggeredCrisisTimelineController::InitiateCrisisTimeline()
{
	ProgressToCrisisStage(EAshenCrisisStage::TimeDilationStart);
	UE_LOG(LogTemp, Warning, TEXT("UAshenStaggeredCrisisTimelineController: Initiated staggered crisis timeline (Time Dilation: %f%%)."), TimeDilationScalar * 100.0f);
}

void UAshenStaggeredCrisisTimelineController::ProgressToCrisisStage(EAshenCrisisStage NewStage)
{
	if (CurrentCrisisStage != NewStage)
	{
		EAshenCrisisStage PrevStage = CurrentCrisisStage;
		CurrentCrisisStage = NewStage;
		if (OnCrisisStageShifted.IsBound())
		{
			OnCrisisStageShifted.Broadcast(PrevStage, CurrentCrisisStage);
		}
		UE_LOG(LogTemp, Log, TEXT("UAshenStaggeredCrisisTimelineController: Crisis stage shifted from %d to %d"), static_cast<int32>(PrevStage), static_cast<int32>(CurrentCrisisStage));
	}
}
