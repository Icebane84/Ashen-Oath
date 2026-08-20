// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenEpistemicConsequenceTypes.h"
#include "AshenEpistemicPostProcessAdapter.generated.h"

/**
 * UAshenEpistemicPostProcessAdapter
 * Manages post-process temporal bloom and chromatic flares when Tier III Milestone convergence events trigger.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenEpistemicPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenEpistemicPostProcessAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void TriggerMilestoneConvergencePostProcess(bool bIsSynarchy);
};
