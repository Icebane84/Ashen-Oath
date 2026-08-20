// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 301: Ashen Soul State Vector Component (UMB-SYS-005)

#include "AshenSoulStateVectorComponent.h"

UAshenSoulStateVectorComponent::UAshenSoulStateVectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSoulStateVectorComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenSoulStateVectorComponent::UpdateSoulVector(const FAshenSoulStateVector& InVector)
{
	CurrentSoulVector = InVector;
	OnSoulStateVectorUpdated.Broadcast(CurrentSoulVector);

	UE_LOG(LogTemp, Log, TEXT("UAshenSoulStateVectorComponent: SoulVector Updated — IntegrationDebt: %.1f, Corruption: %.1f, Unchained: %.1f."),
		CurrentSoulVector.IntegrationDebt, CurrentSoulVector.CorruptionLevel, CurrentSoulVector.UnchainedVesselLevel);
}

void UAshenSoulStateVectorComponent::AccumulateIntegrationDebt(float DebtDelta)
{
	CurrentSoulVector.IntegrationDebt = FMath::Clamp(CurrentSoulVector.IntegrationDebt + DebtDelta, 0.0f, 100.0f);
	OnSoulStateVectorUpdated.Broadcast(CurrentSoulVector);

	UE_LOG(LogTemp, Warning, TEXT("UAshenSoulStateVectorComponent: INTEGRATION DEBT ACCUMULATED (+%.1f) -> Total: %.1f."),
		DebtDelta, CurrentSoulVector.IntegrationDebt);
}


