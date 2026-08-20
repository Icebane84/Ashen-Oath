// AshenDialogueGraph.h
// Copyright Ashen Oath. All rights reserved.
// PHOENIX CODEX: ENGINE-SPEC-001 (DEFINITIVE CANON)
// DataAsset containing Lens-gated dialogue conversation trees.
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AshenDialogueTypes.h"
#include "AshenDialogueGraph.generated.h"

/**
 * @class UAshenDialogueGraph
 * @brief DataAsset container for dialogue conversation trees.
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenDialogueGraph : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	FName ConversationID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	FName StartNodeID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	TArray<FDialogueNodeRecord> Nodes;

	/** Find a node by ID. Returns nullptr if not found. */
	const FDialogueNodeRecord* FindNode(FName NodeID) const;
};
