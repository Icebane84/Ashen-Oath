// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenHallucinationSanctuarySuppressionAdapter.h"

UAshenHallucinationSanctuarySuppressionAdapter::UAshenHallucinationSanctuarySuppressionAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenHallucinationSanctuarySuppressionAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenHallucinationSanctuarySuppressionAdapter::SetSanctuarySuppression(bool bSuppressed)
{
	bIsSuppressedBySanctuary = bSuppressed;
	UE_LOG(LogTemp, Log, TEXT("UAshenHallucinationSanctuarySuppressionAdapter: Hallucination distortions %s by Consecrated Sanctuary Ring."),
		bIsSuppressedBySanctuary ? TEXT("SUPPRESSED") : TEXT("ACTIVE"));
}
