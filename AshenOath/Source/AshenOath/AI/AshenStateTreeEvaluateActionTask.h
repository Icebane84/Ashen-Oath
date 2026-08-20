// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "AshenStateTreeEvaluateActionTask.generated.h"

/**
 * UAshenStateTreeEvaluateActionTask
 * Task component executing Markovian utility and stamina-gated input reading evaluation for StateTree action selection.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenStateTreeEvaluateActionTask : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenStateTreeEvaluateActionTask();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Cognitive Task")
	FGameplayTag ActionTypeTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Cognitive Task")
	float BaseUtility = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Cognitive Task")
	float PreferredRange = 300.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Cognitive Task")
	float CalculatedUtility = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Cognitive Task")
	float EvaluateActionUtility(AActor* TargetActor, float CurrentStamina);
};
