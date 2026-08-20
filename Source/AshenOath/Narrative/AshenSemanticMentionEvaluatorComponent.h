// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSemanticMentionEvaluatorComponent.generated.h"

/**
 * UAshenSemanticMentionEvaluatorComponent
 * Evaluates semantic proximity (800uu) and active quest/codex tokens to trigger ambient narrative callouts and psychic whispers.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSemanticMentionEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenSemanticMentionEvaluatorComponent();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Semantic")
	float MaxMentionTriggerRadius = 800.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Semantic")
	bool EvaluateSemanticMention(const FVector& PlayerLocation, const FVector& SemanticTargetLocation, FName TopicID, float& OutProximityRatio) const;
};
