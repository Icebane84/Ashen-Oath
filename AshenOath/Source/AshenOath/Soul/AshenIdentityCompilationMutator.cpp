// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 633: Ashen Identity Compilation Mutator

#include "AshenIdentityCompilationMutator.h"

void UAshenIdentityCompilationMutator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ActiveIntegrationDebt = 0.5f;
	ActiveResolve = 0.8f;
	UE_LOG(LogTemp, Log, TEXT("UAshenIdentityCompilationMutator: Initialized — Identity Compilation Mutator ONLINE."));
}

void UAshenIdentityCompilationMutator::MutateSoulStateFromPassResult(bool bIntegrativePassSuccess, float DeltaWeight)
{
	if (bIntegrativePassSuccess)
	{
		ActiveIntegrationDebt = FMath::Clamp(ActiveIntegrationDebt - DeltaWeight, 0.0f, 1.0f);
		ActiveResolve = FMath::Clamp(ActiveResolve + DeltaWeight, 0.0f, 1.0f);
	}
	else
	{
		ActiveIntegrationDebt = FMath::Clamp(ActiveIntegrationDebt + DeltaWeight, 0.0f, 1.0f);
		ActiveResolve = FMath::Clamp(ActiveResolve - DeltaWeight, 0.0f, 1.0f);
	}

	OnIdentityMutated.Broadcast(ActiveIntegrationDebt, ActiveResolve);

	UE_LOG(LogTemp, Warning, TEXT("UAshenIdentityCompilationMutator: SOUL STATE MUTATED -> Integration Debt: %.2f | Resolve: %.2f (Pass Success: %s)."),
		ActiveIntegrationDebt, ActiveResolve, bIntegrativePassSuccess ? TEXT("TRUE") : TEXT("FALSE"));
}
