// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenOathbringerMindscapePostProcessAdapter.h"

UAshenOathbringerMindscapePostProcessAdapter::UAshenOathbringerMindscapePostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenOathbringerMindscapePostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenOathbringerMindscapePostProcessAdapter::ApplyMindscapePostProcess(EAshenSwordMorphState MorphState, float Intensity)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenOathbringerMindscapePostProcessAdapter: Mindscape PostProcess applied for Morph State %d (Intensity: %.2f)"),
		(int32)MorphState, Intensity);
}
