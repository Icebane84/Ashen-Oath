// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenFinisherGASPostProcessAdapter.h"

UAshenFinisherGASPostProcessAdapter::UAshenFinisherGASPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenFinisherGASPostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenFinisherGASPostProcessAdapter::ApplyCharacterFinisherPostProcess(FName AbilityName, float Intensity)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenFinisherGASPostProcessAdapter: Applied Finisher PostProcess for '%s' (Intensity: %.2f)"),
		*AbilityName.ToString(), Intensity);
}
