// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenJournalInkBleedMPCModulator.h"

UAshenJournalInkBleedMPCModulator::UAshenJournalInkBleedMPCModulator()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenJournalInkBleedMPCModulator::BeginPlay() { Super::BeginPlay(); }

void UAshenJournalInkBleedMPCModulator::UpdateJournalInkBleedMaterial(float DebtLevel)
{
	const float CrawlingVeinIntensity = FMath::Clamp(DebtLevel * 3.5f, 0.0f, 5.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenJournalInkBleedMPCModulator: %s set to %.2f (Crawling black vein soot-stains on parchment)"),
		*InkBleedParameterName.ToString(), CrawlingVeinIntensity);
}
