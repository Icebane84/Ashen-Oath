// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenEcosystemCompanionReactionAdapter.h"

UAshenEcosystemCompanionReactionAdapter::UAshenEcosystemCompanionReactionAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenEcosystemCompanionReactionAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenEcosystemCompanionReactionAdapter::ApplySomaticBodyLanguage(FName CompanionID, float SeverityImpact)
{
	if (SeverityImpact >= 0.50f)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenEcosystemCompanionReactionAdapter: Companion %s somatic tic triggered -> Furrowed brow / Guarded body posture (Severity: %.2f)"),
			*CompanionID.ToString(), SeverityImpact);
	}
}
