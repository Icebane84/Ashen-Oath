// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenBestiaryFinisherPostProcessAdapter.h"

UAshenBestiaryFinisherPostProcessAdapter::UAshenBestiaryFinisherPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenBestiaryFinisherPostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenBestiaryFinisherPostProcessAdapter::ApplyBestiaryFinisherPostProcess(EAshenPartyFinisherType FinisherType, float Intensity)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenBestiaryFinisherPostProcessAdapter: Postprocess applied for Finisher %d (Intensity: %.2f)"),
		(int32)FinisherType, Intensity);
}
