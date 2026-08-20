// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 828: Ashen Somatic Intrusion Panic Evaluator

#include "AshenSomaticIntrusionPanicEvaluator.h"

void UAshenSomaticIntrusionPanicEvaluator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ActivePulseRateBPM = 70.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenSomaticIntrusionPanicEvaluator: Initialized — Somatic Intrusion Panic Evaluator ONLINE."));
}

void UAshenSomaticIntrusionPanicEvaluator::EvaluateSomaticPanic(float HealthPercent)
{
	ActivePulseRateBPM = 70.0f + ((100.0f - HealthPercent) * 1.1f); // Escalates up to 180 BPM at zero HP
	const float TunnelVision = FMath::Clamp((100.0f - HealthPercent) / 100.0f, 0.0f, 0.85f);

	OnPanicEvaluated.Broadcast(TunnelVision, ActivePulseRateBPM);

	UE_LOG(LogTemp, Warning, TEXT("UAshenSomaticIntrusionPanicEvaluator: SOMATIC PANIC EVALUATED -> Health: %.1f%% | Pulse Rate: %.0f BPM | Tunnel Vision: %.0f%%."),
		HealthPercent, ActivePulseRateBPM, TunnelVision * 100.0f);
}
