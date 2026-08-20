// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenNarrativeChoiceGraphSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnNarrativeChoiceCommittedSignature, FName, NodeID, int32, ChoiceIndex);

/**
 * UAshenNarrativeChoiceGraphSubsystem
 *
 * World Subsystem managing branching quest choice trees and long-term narrative consequences.
 */
UCLASS()
class ASHENOATH_API UAshenNarrativeChoiceGraphSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|NarrativeGraph")
	bool CommitNarrativeChoice(FName NodeID, int32 ChoiceIndex);

	UFUNCTION(BlueprintPure, Category = "AshenOath|NarrativeGraph")
	int32 GetChoiceHistoryCount() const { return ChoiceHistory.Num(); }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|NarrativeGraph|Events")
	FOnNarrativeChoiceCommittedSignature OnChoiceCommitted;

private:
	TMap<FName, int32> ChoiceHistory;
};
