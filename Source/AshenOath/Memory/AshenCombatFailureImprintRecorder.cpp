// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Memory/AshenCombatFailureImprintRecorder.h"

UAshenCombatFailureImprintRecorder::UAshenCombatFailureImprintRecorder()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCombatFailureImprintRecorder::RecordCombatFailure(float DamageTaken, bool bWasFatal)
{
	FPsychologicalImprint Imprint;
	Imprint.Type = EImprintType::Combat;
	Imprint.Weight = bWasFatal ? 1.0f : FMath::Clamp(DamageTaken / 100.0f, 0.1f, 0.9f);
	Imprint.Timestamp = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0f;

	UE_LOG(LogTemp, Warning, TEXT("UAshenCombatFailureImprintRecorder: Combat failure recorded (Damage: %.1f, Fatal: %s, Weight: %.2f)"),
		DamageTaken, bWasFatal ? TEXT("TRUE") : TEXT("FALSE"), Imprint.Weight);
}
