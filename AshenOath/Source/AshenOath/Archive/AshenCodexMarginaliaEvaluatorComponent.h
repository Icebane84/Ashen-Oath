// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Archive/AshenCodexArchiveTypes.h"
#include "AshenCodexMarginaliaEvaluatorComponent.generated.h"

/**
 * UAshenCodexMarginaliaEvaluatorComponent
 * 
 * Generates companion handwritten margin annotations for unlocked codex pages.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCodexMarginaliaEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCodexMarginaliaEvaluatorComponent();

	/** Formats companion handwritten margin text */
	UFUNCTION(BlueprintPure, Category = "Ashen|Archive")
	FText EvaluateMarginaliaText(
		const FName& EntryId,
		const FName& CompanionId,
		float FellowshipTrust) const;
};
