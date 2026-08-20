// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenEpistemicConsequenceTypes.h"
#include "AshenTripartiteInterpretationComponent.generated.h"

/**
 * UAshenTripartiteInterpretationComponent
 * Synthesizes multi-perspective subjective prose (Kaelen's trauma, Garrett's tactical mechanics, Serafina's grace leaf) from Layer 0 canonical events.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTripartiteInterpretationComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenTripartiteInterpretationComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Epistemic")
	FTripartiteInterpretationPackage FormulateInterpretation(FName EncounterID, bool bIsSynarchy);
};
