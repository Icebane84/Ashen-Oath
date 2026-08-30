// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionTrustDialogueTreeAdapter.generated.h"

class UAshenSoulPublisher;

/**
 * UAshenCompanionTrustDialogueTreeAdapter
 * Adapter mapping companion trust scores into unlocked dialogue nodes,
 * automatically querying UAshenSoulPublisher SSoT.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionTrustDialogueTreeAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionTrustDialogueTreeAdapter();

	virtual void BeginPlay() override;

	/** Evaluates whether a dialogue node is unlocked from SSoT trust or manual override */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|Narrative")
	bool IsDialogueNodeUnlockedByTrust(FName CompanionID, FName NodeID, float ManualTrust = -1.0f);

	/** Returns minimum required trust threshold for a named dialogue node */
	UFUNCTION(BlueprintPure, Category = "Ashen Oath|Narrative")
	float GetRequiredTrustForNode(FName NodeID) const;

private:
	UAshenSoulPublisher* GetSoulPublisher() const;
};
