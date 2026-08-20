// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenJournalPerspectiveEvaluatorComponent.h"

UAshenJournalPerspectiveEvaluatorComponent::UAshenJournalPerspectiveEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenJournalPerspectiveEvaluatorComponent::BeginPlay() { Super::BeginPlay(); }

EJournalPerspectiveType UAshenJournalPerspectiveEvaluatorComponent::EvaluateResolutionPerspective(bool bUsedSyncFinisher, float MutualTrust, float Corruption)
{
	if (bUsedSyncFinisher && MutualTrust >= 0.60f)
	{
		return EJournalPerspectiveType::TripartiteSynarchy;
	}
	return EJournalPerspectiveType::SolitaryMartyrdom;
}
