// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenDynamicDialogueConsequenceSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMoralConsequenceRecordedSignature, FName, ChoiceID, float, AlignmentShift);

/**
 * UAshenDynamicDialogueConsequenceSubsystem
 *
 * World Subsystem tracking long-term moral choices and altering future dialogue choices across all NPCs.
 */
UCLASS()
class ASHENOATH_API UAshenDynamicDialogueConsequenceSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|DialogueConsequence")
	void RecordMoralChoiceConsequence(FName ChoiceID, float AlignmentShift);

	UFUNCTION(BlueprintPure, Category = "AshenOath|DialogueConsequence")
	float GetGlobalMoralAlignment() const { return GlobalAlignment; }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|DialogueConsequence|Events")
	FOnMoralConsequenceRecordedSignature OnMoralConsequenceRecorded;

private:
	float GlobalAlignment = 0.0f; // Range: -100 (Ruthless) to +100 (Altruistic)
};
