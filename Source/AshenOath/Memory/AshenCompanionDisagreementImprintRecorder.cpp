// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Memory/AshenCompanionDisagreementImprintRecorder.h"

UAshenCompanionDisagreementImprintRecorder::UAshenCompanionDisagreementImprintRecorder()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCompanionDisagreementImprintRecorder::RecordDisagreement(FName CompanionID, float Severity)
{
	FPsychologicalImprint Imprint;
	Imprint.Type = EImprintType::Relationship;
	Imprint.Weight = FMath::Clamp(Severity, 0.1f, 1.0f);
	Imprint.Timestamp = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0f;

	UE_LOG(LogTemp, Warning, TEXT("UAshenCompanionDisagreementImprintRecorder: Disagreement recorded with companion %s (Severity: %.2f)"),
		*CompanionID.ToString(), Severity);
}
