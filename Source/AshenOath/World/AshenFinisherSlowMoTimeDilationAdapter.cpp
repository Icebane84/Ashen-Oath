// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenFinisherSlowMoTimeDilationAdapter.h"

UAshenFinisherSlowMoTimeDilationAdapter::UAshenFinisherSlowMoTimeDilationAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenFinisherSlowMoTimeDilationAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenFinisherSlowMoTimeDilationAdapter::ApplySlowMoTimeDilation(float DilationFactor, float DurationSeconds)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenFinisherSlowMoTimeDilationAdapter: Time dilation set to %.2fx for %.2fs"), DilationFactor, DurationSeconds);
}
