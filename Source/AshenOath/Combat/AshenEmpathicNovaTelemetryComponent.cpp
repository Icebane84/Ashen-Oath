// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenEmpathicNovaTelemetryComponent.h"

UAshenEmpathicNovaTelemetryComponent::UAshenEmpathicNovaTelemetryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentFrictionFlow = 0.0f;
}
void UAshenEmpathicNovaTelemetryComponent::BeginPlay() { Super::BeginPlay(); }

float UAshenEmpathicNovaTelemetryComponent::EvaluateFrictionFlow(float KaelenTraumaRate, float SerafinaTransferenceRate)
{
	// Friction Flow = |KaelenTraumaRate - SerafinaTransferenceRate|
	CurrentFrictionFlow = FMath::Abs(KaelenTraumaRate - SerafinaTransferenceRate);

	UE_LOG(LogTemp, Log, TEXT("UAshenEmpathicNovaTelemetryComponent: Friction Flow: %.3f (Kaelen: %.2f, Serafina: %.2f)"),
		CurrentFrictionFlow, KaelenTraumaRate, SerafinaTransferenceRate);

	return CurrentFrictionFlow;
}

bool UAshenEmpathicNovaTelemetryComponent::IsInCriticalBurnout(float SerafinaBurnout) const
{
	return (SerafinaBurnout >= 0.75f);
}
