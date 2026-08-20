// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenShadowSeepagePostProcessAdapter.h"

UAshenShadowSeepagePostProcessAdapter::UAshenShadowSeepagePostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenShadowSeepagePostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenShadowSeepagePostProcessAdapter::ApplySeepagePostProcess(EShadowSeepagePhase Phase, float Corruption)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenShadowSeepagePostProcessAdapter: Applied Seepage Post-Process -> Phase: %d, Corruption: %.2f"),
		static_cast<int32>(Phase), Corruption);
}
