// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 639: Ashen Semantic Mention Completeness Validator

#include "AshenSemanticMentionCompletenessValidator.h"

void UAshenSemanticMentionCompletenessValidator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalMentionsValidated = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenSemanticMentionCompletenessValidator: Initialized — Semantic Mention Completeness Validator ONLINE."));
}

bool UAshenSemanticMentionCompletenessValidator::ValidateSemanticMention(FName ProseMentionID, FName ExpectedEdgeID)
{
	TotalMentionsValidated++;
	const bool bValid = (ProseMentionID == ExpectedEdgeID);
	OnMentionValidated.Broadcast(ProseMentionID, bValid);

	UE_LOG(LogTemp, Log, TEXT("UAshenSemanticMentionCompletenessValidator: MENTION VALIDATED -> Prose Mention '%s' == Graph Edge '%s' -> %s."),
		*ProseMentionID.ToString(), *ExpectedEdgeID.ToString(), bValid ? TEXT("VALID") : TEXT("INVALID"));

	return bValid;
}
