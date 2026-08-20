// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenTrialOfWillPostProcessAdapter.h"

UAshenTrialOfWillPostProcessAdapter::UAshenTrialOfWillPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenTrialOfWillPostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenTrialOfWillPostProcessAdapter::ApplyStaggerDilationPostProcess(bool bActive)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenTrialOfWillPostProcessAdapter: Radial Dilation Post-Process: %s"),
		bActive ? TEXT("ACTIVE") : TEXT("DISABLED"));
}
