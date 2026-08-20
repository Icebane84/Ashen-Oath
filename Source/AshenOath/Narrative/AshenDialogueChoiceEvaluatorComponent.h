// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDialogueChoiceEvaluatorComponent.generated.h"

/**
 * UAshenDialogueChoiceEvaluatorComponent
 * Context-aware companion dialogue scoring based on pairwise trust and emotional resonance.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDialogueChoiceEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDialogueChoiceEvaluatorComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Dialogue")
	float EvaluateDialogueOptionTrustScore(FName CompanionID, float BaseTrustMultiplier) const;
};
