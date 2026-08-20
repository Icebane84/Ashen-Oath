// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenNPCReactivityPhenotypeIntegrator.h"

UAshenNPCReactivityPhenotypeIntegrator::UAshenNPCReactivityPhenotypeIntegrator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenNPCReactivityPhenotypeIntegrator::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	NPCFearFactor = FMath::Clamp(NewState.Corruption * 0.9f, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenNPCReactivityPhenotypeIntegrator: NPC fear factor updated to %.2f"), NPCFearFactor);
}
