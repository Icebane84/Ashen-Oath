// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenEpistemicConsequenceTypes.h"
#include "AshenEpistemicAIDirectorComponent.generated.h"

/**
 * UAshenEpistemicAIDirectorComponent
 * AI Director orchestrating companion tactical behavior shifts based on resolved consequence tiers.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenEpistemicAIDirectorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenEpistemicAIDirectorComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	void AdaptTacticalState(EConsequenceProfileTier Tier, bool bIsSynarchy);
};
