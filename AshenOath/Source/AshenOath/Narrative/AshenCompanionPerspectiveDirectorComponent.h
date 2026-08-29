// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenCSEQuestBoardTypes.h"
#include "AshenCompanionPerspectiveDirectorComponent.generated.h"

/**
 * UAshenCompanionPerspectiveDirectorComponent
 * 
 * Tracks companion psychological vectors, trust divergence, and ideological conviction tiers.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionPerspectiveDirectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionPerspectiveDirectorComponent();

	/** Gets active companion perspective state */
	UFUNCTION(BlueprintPure, Category = "Ashen|CSE|Companion")
	FCognitiveStateVector GetCompanionPerspective() const { return PerspectiveVector; }

	/** Adjusts ideological weights */
	UFUNCTION(BlueprintCallable, Category = "Ashen|CSE|Companion")
	void AdjustWeights(float DeltaPragmatism, float DeltaDogma, float DeltaTruth);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|CSE|Companion")
	FCognitiveStateVector PerspectiveVector;
};
