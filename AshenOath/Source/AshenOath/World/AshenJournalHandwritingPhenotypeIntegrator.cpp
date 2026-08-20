// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenJournalHandwritingPhenotypeIntegrator.h"

UAshenJournalHandwritingPhenotypeIntegrator::UAshenJournalHandwritingPhenotypeIntegrator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenJournalHandwritingPhenotypeIntegrator::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	HandwritingWobbleScalar = FMath::Clamp((1.0f - NewState.Resolve) * 0.8f + NewState.Corruption * 0.2f, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenJournalHandwritingPhenotypeIntegrator: Diegetic journal handwriting wobble scalar updated to %.2f"), HandwritingWobbleScalar);
}
