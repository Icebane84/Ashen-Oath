// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenDialogueChoiceMoralityEvaluator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnMoralityVectorEvaluatedSignature, FName, ChoiceID, float, WhiteFlameVector, float, CorruptionVector);

/**
 * UAshenDialogueChoiceMoralityEvaluator
 *
 * Subsystem mapping Kaelen's dialogue choices to non-binary moral state vectors (PRS-001 Combat Blueprint / Act 01).
 */
UCLASS()
class ASHENOATH_API UAshenDialogueChoiceMoralityEvaluator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|MoralityEvaluator")
	void EvaluateDialogueChoice(FName ChoiceID, float WhiteFlameDelta, float CorruptionDelta);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|MoralityEvaluator|Events")
	FOnMoralityVectorEvaluatedSignature OnMoralityEvaluated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|MoralityEvaluator")
	float ActiveWhiteFlameVector = 50.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|MoralityEvaluator")
	float ActiveCorruptionVector = 50.0f;
};
