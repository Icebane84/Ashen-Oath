// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenJournalTypes.h"
#include "AshenCampfireContemplationDirectorComponent.generated.h"

class UAshenSoulPublisher;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCampfireRestCompletedSignature, float, SanityRestored, ECampfireReflectionMood, NewMood);

/**
 * UAshenCampfireContemplationDirectorComponent
 * 
 * Coordinates campfire rest cycles, mood transitions, and SSoT state healing.
 * Commits sanity restoration, dysregulation purge, and fatigue reset to UAshenSoulPublisher.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCampfireContemplationDirectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCampfireContemplationDirectorComponent();

	virtual void BeginPlay() override;

	/** Transitions the campfire mood based on SSoT soul state or optional parameters */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Journal|Campfire")
	ECampfireReflectionMood EvaluateCampfireMood(float TrustScore01 = -1.0f, float Debt01 = -1.0f);

	/** Performs campfire rest, committing canonical sanity/dysregulation healing to UAshenSoulPublisher */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Journal|Campfire")
	float RestAtCampfire(float RestDurationSeconds);

	UFUNCTION(BlueprintPure, Category = "Ashen|Journal|Campfire")
	ECampfireReflectionMood GetCurrentMood() const { return CurrentMood; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Journal|Campfire|Events")
	FOnCampfireRestCompletedSignature OnCampfireRestCompleted;

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Journal|Campfire")
	ECampfireReflectionMood CurrentMood = ECampfireReflectionMood::TemperedResolve;

private:
	UAshenSoulPublisher* GetSoulPublisher() const;
};
