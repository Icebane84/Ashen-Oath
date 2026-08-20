// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenSemanticMentionCompletenessValidator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSemanticMentionValidatedSignature, FName, MentionedEntityID, bool, bIsCodifiedAsGraphEdge);

/**
 * UAshenSemanticMentionCompletenessValidator
 *
 * Validator verifying character and location mentions in narrative prose map to formal graph YAML frontmatter edges.
 */
UCLASS()
class ASHENOATH_API UAshenSemanticMentionCompletenessValidator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|SemanticValidator")
	bool ValidateSemanticMention(FName ProseMentionID, FName ExpectedEdgeID);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SemanticValidator|Events")
	FOnSemanticMentionValidatedSignature OnMentionValidated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|SemanticValidator")
	int32 TotalMentionsValidated = 0;
};
