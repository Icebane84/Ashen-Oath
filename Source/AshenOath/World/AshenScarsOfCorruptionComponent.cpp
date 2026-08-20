// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 338: Ashen Scars Of Corruption Component

#include "AshenScarsOfCorruptionComponent.h"

UAshenScarsOfCorruptionComponent::UAshenScarsOfCorruptionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	ScarCount = 0;
	TotalMaxSanityPenalty = 0.0f;
}

void UAshenScarsOfCorruptionComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenScarsOfCorruptionComponent::IncurCorruptionScar(float PenaltyAmount)
{
	ScarCount++;
	TotalMaxSanityPenalty += PenaltyAmount;

	OnScarIncurred.Broadcast(ScarCount, TotalMaxSanityPenalty);

	UE_LOG(LogTemp, Warning, TEXT("UAshenScarsOfCorruptionComponent: CORRUPTION SCAR INCURRED (#%d) — Total Max Sanity Penalty: -%.1f."),
		ScarCount, TotalMaxSanityPenalty);
}
