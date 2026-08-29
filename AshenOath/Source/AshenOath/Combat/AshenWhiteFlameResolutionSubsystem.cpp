// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenWhiteFlameResolutionSubsystem.h"
#include "Memory/AshenIntegrationDebtAccumulatorSubsystem.h"
#include "Companions/AshenCompanionFatigueSubsystem.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

void UAshenWhiteFlameResolutionSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	CurrentResolutionPayload.DurationRemainingSeconds = 12.0f;
	CurrentResolutionPayload.EradicatedDebtAmount = 0.0f;
	CurrentResolutionPayload.BurnoutReliefPercentage = 0.50f;
	CurrentResolutionPayload.State = EWhiteFlameState::Inactive;
	UE_LOG(LogTemp, Log, TEXT("UAshenWhiteFlameResolutionSubsystem: White Flame Resolution Subsystem Initialized."));
}

void UAshenWhiteFlameResolutionSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

bool UAshenWhiteFlameResolutionSubsystem::EvaluateResolutionReadiness(float KaelenResolve, float SerafinaBurnout)
{
	const bool bIsPrimed = (KaelenResolve >= 0.90f && SerafinaBurnout >= 0.65f);
	CurrentResolutionPayload.State = bIsPrimed ? EWhiteFlameState::Primed : EWhiteFlameState::Inactive;

	if (bIsPrimed)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenWhiteFlameResolutionSubsystem: WHITE FLAME RESOLUTION PRIMED! (Resolve: %.2f, Burnout: %.2f)"),
			KaelenResolve, SerafinaBurnout);
	}
	return bIsPrimed;
}

bool UAshenWhiteFlameResolutionSubsystem::ActivateWhiteFlameResolution(float CurrentIntegrationDebt, float& OutClearedDebt)
{
	if (CurrentResolutionPayload.State != EWhiteFlameState::Primed && CurrentResolutionPayload.State != EWhiteFlameState::Active)
	{
		OutClearedDebt = 0.0f;
		return false;
	}

	CurrentResolutionPayload.State = EWhiteFlameState::Active;
	CurrentResolutionPayload.DurationRemainingSeconds = 12.0f;
	CurrentResolutionPayload.EradicatedDebtAmount = CurrentIntegrationDebt;
	OutClearedDebt = CurrentIntegrationDebt; // 100% eradication

	if (OnWhiteFlameResolutionActivated.IsBound())
	{
		OnWhiteFlameResolutionActivated.Broadcast(OutClearedDebt, CurrentResolutionPayload.DurationRemainingSeconds);
	}

	UE_LOG(LogTemp, Error, TEXT("UAshenWhiteFlameResolutionSubsystem: *** THE WHITE FLAME RESOLUTION IS ACTIVE *** (Eradicated %.2f Integration Debt)!"),
		OutClearedDebt);
	return true;
}

bool UAshenWhiteFlameResolutionSubsystem::ActivateWhiteFlameWithWorldContext(UWorld* WorldContext, float& OutClearedDebt)
{
	OutClearedDebt = 0.0f;
	if (!WorldContext)
	{
		return false;
	}

	float CurrentDebt = 0.0f;
	if (UAshenIntegrationDebtAccumulatorSubsystem* DebtSubsystem = WorldContext->GetSubsystem<UAshenIntegrationDebtAccumulatorSubsystem>())
	{
		CurrentDebt = DebtSubsystem->GetIntegrationDebt();
	}

	if (!ActivateWhiteFlameResolution(CurrentDebt, OutClearedDebt))
	{
		return false;
	}

	// 1. Eradicate Integration Debt
	if (UAshenIntegrationDebtAccumulatorSubsystem* DebtSubsystem = WorldContext->GetSubsystem<UAshenIntegrationDebtAccumulatorSubsystem>())
	{
		DebtSubsystem->ClearAllDebt();
	}

	// 2. Relieve Serafina's Burnout by 50%
	if (UGameInstance* GI = WorldContext->GetGameInstance())
	{
		if (UAshenCompanionFatigueSubsystem* FatigueSubsystem = GI->GetSubsystem<UAshenCompanionFatigueSubsystem>())
		{
			FatigueSubsystem->RelieveSerafinaBurnout(0.50f);
		}
	}

	return true;
}
