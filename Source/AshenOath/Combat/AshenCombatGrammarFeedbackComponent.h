// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCombatGrammarFeedbackComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCombatGrammarTriggeredSignature, FName, GrammarTypeTag, float, FeedbackIntensity);

/**
 * UAshenCombatGrammarFeedbackComponent
 *
 * Component broadcasting cross-discipline feedback tags for White Flame (Disciplined), Shadow (Unchained), and Synchronization (Flow State) (PRS-001 Combat Blueprint V5.0).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCombatGrammarFeedbackComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCombatGrammarFeedbackComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|CombatGrammar")
	void TriggerGrammarFeedback(FName GrammarTag, float Intensity = 1.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|CombatGrammar|Events")
	FOnCombatGrammarTriggeredSignature OnGrammarTriggered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|CombatGrammar")
	FName ActiveGrammarState = FName(TEXT("Grammar.WhiteFlame"));
};
