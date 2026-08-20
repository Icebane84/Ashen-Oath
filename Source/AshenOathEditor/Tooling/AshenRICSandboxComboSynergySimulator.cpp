// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenRICSandboxComboSynergySimulator.h"

void UAshenRICSandboxComboSynergySimulator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenRICSandboxComboSynergySimulator: RIC Sandbox Combo Synergy Simulator initialized."));
}

float UAshenRICSandboxComboSynergySimulator::SimulateComboSynergyOutput(float GarrettTrust, float SerafinaTrust) const
{
	float SynergyValue = (GarrettTrust * 0.5f) + (SerafinaTrust * 0.5f);
	UE_LOG(LogTemp, Log, TEXT("UAshenRICSandboxComboSynergySimulator: Simulated combo synergy output: %.2f"), SynergyValue);
	return SynergyValue;
}
