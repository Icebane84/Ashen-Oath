// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenEpistemicConsequenceTypes.h"
#include "AshenEpistemicCompanionReactionAdapter.generated.h"

/**
 * UAshenEpistemicCompanionReactionAdapter
 * Modulates companion camp idle animations and distance spacing based on historical Milestone resolutions.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenEpistemicCompanionReactionAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenEpistemicCompanionReactionAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	void UpdateCompanionCampAttitude(EConsequenceProfileTier Tier, bool bIsSynarchy);
};
