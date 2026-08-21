// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenTripartiteResonanceTypes.h"
#include "AshenComboChainEvaluatorComponent.generated.h"

/**
 * UAshenComboChainEvaluatorComponent
 * 
 * Evaluates the 3-step Tripartite Combo progression and timing windows.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenComboChainEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenComboChainEvaluatorComponent();

	/** Starts Step 1 */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Trio")
	FTripartiteComboState StartCombo(float WindowSeconds);

	/** Progresses to Step 2 if Garrett is nearby */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Trio")
	FTripartiteComboState ProgressToStep2(bool bGarrettNear);

	/** Progresses to Step 3 / FinisherReady if Serafina is nearby */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Trio")
	FTripartiteComboState ProgressToStep3(bool bSerafinaNear);

	/** Resets the combo state */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Trio")
	void ResetCombo();

	UFUNCTION(BlueprintPure, Category = "Ashen|Combat|Trio")
	FTripartiteComboState GetCurrentState() const { return CurrentState; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Combat|Trio")
	FTripartiteComboState CurrentState;
};
