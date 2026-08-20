// AshenDialogueTypes.h
// Copyright Ashen Oath. All rights reserved.
// PHOENIX CODEX: ENGINE-SPEC-001 (DEFINITIVE CANON) Section 7 & Pillar III
// Data structures for Lens-gated node graph dialogue trees.
#pragma once

#include "CoreMinimal.h"
#include "AshenSoulStateVector.h"
#include "AshenDialogueTypes.generated.h"

// ---------------------------------------------------------------------------
// LENS GATE OPTION
// Determines if a node requires a specific Lens, or any lens.
// ---------------------------------------------------------------------------
UENUM(BlueprintType)
enum class EDialogueLensGate : uint8
{
	Any             UMETA(DisplayName = "Any Lens"),
	Accountability  UMETA(DisplayName = "Accountability Required"),
	Grace           UMETA(DisplayName = "Grace Required"),
	Utility         UMETA(DisplayName = "Utility Required"),
};

// ---------------------------------------------------------------------------
// DIALOGUE CHOICE RECORD
// A selectable player response choice attached to a dialogue node.
// ---------------------------------------------------------------------------
USTRUCT(BlueprintType)
struct ASHENOATH_API FDialogueChoiceRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
	FText ChoiceText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
	FName TargetNodeID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
	EDialogueLensGate RequiredLens = EDialogueLensGate::Any;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
	float MinTrustRequired = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
	float MinResolveRequired = 0.0f;
};

// ---------------------------------------------------------------------------
// DIALOGUE NODE RECORD
// A single node within a UAshenDialogueGraph DataAsset.
// ---------------------------------------------------------------------------
USTRUCT(BlueprintType)
struct ASHENOATH_API FDialogueNodeRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
	FName NodeID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
	FText SpeakerName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
	FText DialogueText;

	/** Voice audio asset played for this node (optional). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
	TSoftObjectPtr<USoundBase> VoiceAudio;

	/** Lens gate requirement for this node. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
	EDialogueLensGate RequiredLens = EDialogueLensGate::Any;

	/** Minimum Serafina/Garrett trust required (0.0 to 1.0). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
	float MinTrustRequired = 0.0f;

	/** Minimum Kaelen Resolve required (0.0 to 1.0). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
	float MinResolveRequired = 0.0f;

	/** Player choice options originating from this node. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
	TArray<FDialogueChoiceRecord> Choices;
};
