// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenLensPostProcessAdapter.h"

UAshenLensPostProcessAdapter::UAshenLensPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenLensPostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenLensPostProcessAdapter::ApplyLensColorGrading(EInterpretiveLens Lens)
{
	FString GradeName = TEXT("Amber Warmth (Grace)");
	if (Lens == EInterpretiveLens::Accountability) GradeName = TEXT("Steel Blue (Accountability)");
	else if (Lens == EInterpretiveLens::Utility) GradeName = TEXT("High Contrast Monochrome (Utility)");

	UE_LOG(LogTemp, Log, TEXT("UAshenLensPostProcessAdapter: Applied Color Grading: %s."), *GradeName);
}
