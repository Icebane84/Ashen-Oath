// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenJournalTypes.h"
#include "AshenCampfireContemplationDirectorComponent.generated.h"

/**
 * UAshenCampfireContemplationDirectorComponent
 * 
 * Coordinates campfire rest cycles, mood transitions, and multi-author marginalia debate triggers.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCampfireContemplationDirectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCampfireContemplationDirectorComponent();

	/** Transitions the campfire mood based on average party trust */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Journal|Campfire")
	ECampfireReflectionMood EvaluateCampfireMood(float TrustScore01, float Debt01);

	/** Records contemplation duration and returns sanity restored */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Journal|Campfire")
	float RestAtCampfire(float RestDurationSeconds);

	UFUNCTION(BlueprintPure, Category = "Ashen|Journal|Campfire")
	ECampfireReflectionMood GetCurrentMood() const { return CurrentMood; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Journal|Campfire")
	ECampfireReflectionMood CurrentMood = ECampfireReflectionMood::TemperedResolve;
};
