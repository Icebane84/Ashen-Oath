// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenJournalTypes.h"
#include "AshenMultiAuthorMarginaliaEvaluator.generated.h"

class UAshenSoulPublisher;

/**
 * UAshenMultiAuthorMarginaliaEvaluator
 * 
 * Computes marginalia visibility gating and ink RGB values for Kaelen, Garrett,
 * and Serafina based on SSoT trust levels from UAshenSoulPublisher.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMultiAuthorMarginaliaEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMultiAuthorMarginaliaEvaluator();

	/** Evaluates whether an author's marginalia notes are visible given party trust or SSoT query */
	UFUNCTION(BlueprintPure, Category = "Ashen|Journal|Marginalia")
	bool IsAuthorMarginaliaUnlocked(EForensicMarginaliaAuthor Author, float TrustScore01 = -1.0f) const;

	/** Gets the canonical ink color for a given author */
	UFUNCTION(BlueprintPure, Category = "Ashen|Journal|Marginalia")
	FLinearColor GetAuthorInkColor(EForensicMarginaliaAuthor Author) const;

private:
	UAshenSoulPublisher* GetSoulPublisher() const;
};
