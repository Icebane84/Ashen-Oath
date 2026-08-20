// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenCanonicalPromiseTypes.h"
#include "AshenSemanticContextMatcherComponent.generated.h"

/**
 * UAshenSemanticContextMatcherComponent
 * 
 * Compares real-time crisis context tags against registered promises to trigger reactivations.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSemanticContextMatcherComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSemanticContextMatcherComponent();

	/** Evaluates whether promise context matches current crisis */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Promise")
	bool MatchesCrisisContext(
		const FCanonicalPromiseRecord& Promise,
		FGameplayTag CurrentCrisisTag,
		FName ActiveCompanion) const;
};
