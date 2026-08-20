// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenCompanionDisagreementPhenotypeIntegrator.h"

UAshenCompanionDisagreementPhenotypeIntegrator::UAshenCompanionDisagreementPhenotypeIntegrator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCompanionDisagreementPhenotypeIntegrator::RecordDisagreementImprint(FName CompanionID, float Severity)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenCompanionDisagreementPhenotypeIntegrator: Relational disagreement imprint recorded for %s (Severity: %.2f)"),
		*CompanionID.ToString(), Severity);
}
