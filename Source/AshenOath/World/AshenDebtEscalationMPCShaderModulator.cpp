// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenDebtEscalationMPCShaderModulator.h"

void UAshenDebtEscalationMPCShaderModulator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenDebtEscalationMPCShaderModulator: MPC Shader Modulator initialized."));
}

void UAshenDebtEscalationMPCShaderModulator::Deinitialize() { Super::Deinitialize(); }

void UAshenDebtEscalationMPCShaderModulator::ModulateMPCShaderParameters(float DebtValue, EAshenIntegrationDebtStage Stage)
{
	ActiveNoiseIntensityScalar = FMath::Clamp(DebtValue, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenDebtEscalationMPCShaderModulator: MPC parameters updated — MPC_IntegrationDebt=%f, MPC_DebtStage=%d"),
		ActiveNoiseIntensityScalar, (int32)Stage);
}
