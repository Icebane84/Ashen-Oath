// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenRelationalEcologyTypes.h"
#include "AshenFellowshipDialogueAdapter.generated.h"

/**
 * UAshenFellowshipDialogueAdapter
 * 
 * Governs wordless narrative behavior:
 * - Averted glances when trust is strained
 * - Hesitated combat barks during ActiveRupture
 * - Confident synchronized acknowledgements during RememberedReconciliation
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenFellowshipDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenFellowshipDialogueAdapter();

	/** Evaluates whether companion should hesitate before delivering tactical bark */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Fellowship")
	bool ShouldHesitateBark(ERelationalRuptureState RuptureState, float TrustLevel) const;

	/** Gets recommended head-look gaze weight for companion towards Kaelen */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Fellowship")
	float GetCompanionGazeWeight(ERelationalRuptureState RuptureState, float TrustLevel) const;
};
