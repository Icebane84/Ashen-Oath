// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 384: Ashen Companion Divergence Resolution Component

#include "AshenCompanionDivergenceResolutionComponent.h"

UAshenCompanionDivergenceResolutionComponent::UAshenCompanionDivergenceResolutionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCompanionDivergenceResolutionComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenCompanionDivergenceResolutionComponent::ResolveCompanionDivergence(FName CompanionID, bool bReconcileSuccess)
{
	OnDivergenceResolved.Broadcast(CompanionID, bReconcileSuccess);

	UE_LOG(LogTemp, Warning, TEXT("UAshenCompanionDivergenceResolutionComponent: COMPANION DIVERGENCE RESOLVED FOR '%s' — Result: %s."),
		*CompanionID.ToString(), bReconcileSuccess ? TEXT("RECONCILED (Oathbond Restored)") : TEXT("PARTED WAYS / HOSTILE"));
}
