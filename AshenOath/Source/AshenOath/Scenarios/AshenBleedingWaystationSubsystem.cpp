// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenBleedingWaystationSubsystem.h"

UAshenBleedingWaystationSubsystem::UAshenBleedingWaystationSubsystem()
{
	InitializeRunMode(EWaystationRunMode::RunA_ShadowHarvest);
}

void UAshenBleedingWaystationSubsystem::InitializeRunMode(EWaystationRunMode Mode)
{
	CurrentRunContext.RunMode = Mode;

	switch (Mode)
	{
	case EWaystationRunMode::RunA_ShadowHarvest:
		CurrentRunContext.ScoutDecision = EScoutCatalystDecision::HarvestResidualTaint;
		CurrentRunContext.SerafinaFormationDistanceUU = 1000.0f;
		CurrentRunContext.StateTreeHesitationLatencyMS = 300.0f;
		CurrentRunContext.GarrettResponse = EGarrettDualWieldBenchmarkResponse::DaggerFlankPeel;
		CurrentRunContext.IntegrationDebt = 0.20f;
		break;

	case EWaystationRunMode::RunB_PureGrace:
		CurrentRunContext.ScoutDecision = EScoutCatalystDecision::MercifulCleanDeath;
		CurrentRunContext.SerafinaFormationDistanceUU = 300.0f;
		CurrentRunContext.StateTreeHesitationLatencyMS = 0.0f;
		CurrentRunContext.GarrettResponse = EGarrettDualWieldBenchmarkResponse::TwinBladeXLockDeflect;
		CurrentRunContext.IntegrationDebt = 0.15f;
		break;

	case EWaystationRunMode::RunC_TheSpiral:
		CurrentRunContext.ScoutDecision = EScoutCatalystDecision::PanicInvoluntarySlain;
		CurrentRunContext.SerafinaFormationDistanceUU = 1200.0f;
		CurrentRunContext.StateTreeHesitationLatencyMS = 600.0f;
		CurrentRunContext.GarrettResponse = EGarrettDualWieldBenchmarkResponse::DefensiveBladeAbort;
		CurrentRunContext.IntegrationDebt = 0.85f;
		break;

	case EWaystationRunMode::RunD_AvoidantMercy:
		CurrentRunContext.ScoutDecision = EScoutCatalystDecision::MercifulCleanDeath;
		CurrentRunContext.SerafinaFormationDistanceUU = 750.0f;
		CurrentRunContext.StateTreeHesitationLatencyMS = 150.0f;
		CurrentRunContext.GarrettResponse = EGarrettDualWieldBenchmarkResponse::HesitantGuardedHold;
		CurrentRunContext.IntegrationDebt = 0.80f;
		break;
	}

	OnWaystationRunSelected.Broadcast(CurrentRunContext.RunMode, CurrentRunContext.ScoutDecision);
	OnFormationSpacingShifted.Broadcast(CurrentRunContext.SerafinaFormationDistanceUU, 400.0f);
}

void UAshenBleedingWaystationSubsystem::TriggerKnockedToKneeBenchmark()
{
	ESerafinaSupportState SerafinaAction = ESerafinaSupportState::InstantTransferenceAura;
	if (CurrentRunContext.RunMode == EWaystationRunMode::RunA_ShadowHarvest)
	{
		SerafinaAction = ESerafinaSupportState::HesitantDelayedBuff;
	}
	else if (CurrentRunContext.RunMode == EWaystationRunMode::RunC_TheSpiral)
	{
		SerafinaAction = ESerafinaSupportState::TerrifiedSeveredAura;
	}
	else if (CurrentRunContext.RunMode == EWaystationRunMode::RunD_AvoidantMercy)
	{
		SerafinaAction = ESerafinaSupportState::TentativeGuardedAura;
	}

	OnKnockedToKneeBenchmarkTriggered.Broadcast(CurrentRunContext.GarrettResponse, SerafinaAction);
}
