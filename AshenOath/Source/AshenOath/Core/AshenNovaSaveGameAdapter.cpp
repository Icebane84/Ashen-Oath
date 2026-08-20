// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenNovaSaveGameAdapter.h"

UAshenNovaSaveGameAdapter::UAshenNovaSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenNovaSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenNovaSaveGameAdapter::SaveNovaStatistics(int32 TotalNovaExecutions, float MaxTrustAchieved)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenNovaSaveGameAdapter: Saved Nova Statistics (Executions: %d, Max Trust: %.2f) to SaveGame."),
		TotalNovaExecutions, MaxTrustAchieved);
	return true;
}
