// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenBossStaggerTelemetryComponent.h"

UAshenBossStaggerTelemetryComponent::UAshenBossStaggerTelemetryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	StaggerWindowRemainingSeconds = 0.0f;
	bIsStaggerWindowOpen = false;
}
void UAshenBossStaggerTelemetryComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenBossStaggerTelemetryComponent::OpenStaggerWindow(float Duration)
{
	StaggerWindowRemainingSeconds = Duration;
	bIsStaggerWindowOpen = true;
	UE_LOG(LogTemp, Warning, TEXT("UAshenBossStaggerTelemetryComponent: TRIAL OF WILL STAGGER WINDOW OPEN (%.2fs)!"), Duration);
}

bool UAshenBossStaggerTelemetryComponent::ExecuteStaggerFinisher(EStaggerExecutionType FinisherType, float& OutExecutionDamage)
{
	if (!bIsStaggerWindowOpen)
	{
		OutExecutionDamage = 0.0f;
		return false;
	}

	bIsStaggerWindowOpen = false;

	switch (FinisherType)
	{
	case EStaggerExecutionType::SoloMartyrStrike:
		OutExecutionDamage = 1100.0f;
		break;
	case EStaggerExecutionType::TripartiteResonantCleave:
		OutExecutionDamage = 2500.0f;
		break;
	case EStaggerExecutionType::WhitePyreDisintegration:
		OutExecutionDamage = 3500.0f;
		break;
	}

	UE_LOG(LogTemp, Error, TEXT("UAshenBossStaggerTelemetryComponent: *** STAGGER FINISHER EXECUTED: Type %d (%.1f DMG) ***!"),
		static_cast<int32>(FinisherType), OutExecutionDamage);
	return true;
}
