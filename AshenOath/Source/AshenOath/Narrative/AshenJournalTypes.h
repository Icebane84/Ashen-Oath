// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenJournalTypes.generated.h"

UENUM(BlueprintType)
enum class EJournalEventType : uint8
{
	NewEntryCompiled,
	CompanionMarginaliaAdded,
	MemoryRevisitedAndReframed,
	PsychologicalDistortionApplied
};

USTRUCT(BlueprintType)
struct FJournalPerspective
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Journal")
	FName AuthorName; // "Kaelen", "Garrett", "Serafina"

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Journal")
	FText InterpretationText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Journal")
	float EmotionalStateValence = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Journal")
	FName TrustContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Journal")
	FDateTime Timestamp;
};

USTRUCT(BlueprintType)
struct FJournalEvent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Journal")
	FGuid SourceImprintGuid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Journal")
	FName MemoryNodeID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Journal")
	EJournalEventType EventType = EJournalEventType::NewEntryCompiled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Journal")
	FText CanonicalFactText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Journal")
	TArray<FJournalPerspective> Perspectives;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Journal")
	uint8 ActiveLensIndex = 0; // 0: Accountability, 1: Grace, 2: Utility

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Journal")
	float KaelenSanityAtTimeOfWriting = 1.0f;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnJournalEventDispatched, const FJournalEvent&, JournalEvent);
