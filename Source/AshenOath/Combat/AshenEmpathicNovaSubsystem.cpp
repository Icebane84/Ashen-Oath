// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenEmpathicNovaSubsystem.h"

void UAshenEmpathicNovaSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	CurrentFinisherState = ENovaFinisherState::Inactive;
	CurrentMetrics.MutualTrust = 0.50f;
	CurrentMetrics.IntegrationDebt = 0.0f;
	CurrentMetrics.SerafinaBurnout = 0.0f;
	CurrentMetrics.KaelenCorruption = 0.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenEmpathicNovaSubsystem: Empathic Nova Subsystem initialized."));
}
void UAshenEmpathicNovaSubsystem::Deinitialize() { Super::Deinitialize(); }

bool UAshenEmpathicNovaSubsystem::CanInitiateNova(float MutualTrust, float SerafinaBurnout) const
{
	// Gated by Mutual Trust >= 0.70 and Serafina Burnout < 0.90
	const bool bCanInitiate = (MutualTrust >= 0.70f) && (SerafinaBurnout < 0.90f);
	return bCanInitiate;
}

bool UAshenEmpathicNovaSubsystem::TriggerNovaExecution()
{
	if (CurrentFinisherState == ENovaFinisherState::Executing) return false;

	CurrentFinisherState = ENovaFinisherState::Executing;
	UE_LOG(LogTemp, Warning, TEXT("UAshenEmpathicNovaSubsystem: EMPATHIC CONDUIT NOVA EXECUTING!"));
	return true;
}

void UAshenEmpathicNovaSubsystem::InvalidateAndResetSubsystems()
{
	CurrentFinisherState = ENovaFinisherState::Recovery;
	CurrentMetrics.IntegrationDebt = 0.0f;
	UE_LOG(LogTemp, Warning, TEXT("UAshenEmpathicNovaSubsystem: Fired InvalidateSubsystems() pulse. Reset Imprint Buffer & re-evaluating Behavioral Profiles."));
}
