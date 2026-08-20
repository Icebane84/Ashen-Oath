// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenRICSandboxSubsystem.h"

void UAshenRICSandboxSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenRICSandboxSubsystem: Offline RIC Sandbox Subsystem Initialized."));
}

void UAshenRICSandboxSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

bool UAshenRICSandboxSubsystem::InjectMockImprint(const FPsychologicalImprint& MockImprint)
{
	MockImprints.Add(MockImprint);
	UE_LOG(LogTemp, Log, TEXT("UAshenRICSandboxSubsystem: Injected mock imprint (Type: %d, Weight: %.2f)"), (int32)MockImprint.Type, MockImprint.Weight);
	return true;
}

bool UAshenRICSandboxSubsystem::SimulateHeartstoneCompilation()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenRICSandboxSubsystem: Simulating Heartstone Compilation Ritual for %d imprints..."), MockImprints.Num());
	MockImprints.Empty();
	UE_LOG(LogTemp, Log, TEXT("UAshenRICSandboxSubsystem: Simulation Complete. Zero-Hallucination Firewall Passed."));
	return true;
}
