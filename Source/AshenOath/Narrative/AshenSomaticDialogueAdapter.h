// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenSomaticDialogueAdapter.generated.h"

/**
 * UAshenSomaticDialogueAdapter
 * 
 * Narrative dialogue branch adapter evaluating action congruence resistance,
 * mapping >= 0.85 to the 100% mechanical trigger lock, and handling dialogue outcomes.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSomaticDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSomaticDialogueAdapter();

	/** Prepares a dialogue choice branch and evaluates required physical will resistance */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Narrative|Dialogue")
	FActionCongruenceResult PrepareDialogueBranch(
		const FCanonicalSoulStateVector& SoulState,
		const FCanonicalRelationalMatrix& RelationalState,
		FGameplayTag ChoiceTag,
		EOntologicalLens ChoiceLens,
		float MemorySeverity,
		FName CompanionTargetName);

	/** Determines whether the branch requires the 100% mechanical hard-stop lockout */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Dialogue")
	bool RequiresMechanicalLockout(float ResistanceSomatic) const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Narrative|Dialogue")
	float MechanicalLockoutThreshold = 0.85f;

private:
	UPROPERTY()
	FActionCongruenceResult LastBranchResult;
};
