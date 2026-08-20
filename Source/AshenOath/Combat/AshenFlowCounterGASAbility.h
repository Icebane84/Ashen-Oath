// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenFlowCounterGASAbility.generated.h"

/**
 * UAshenFlowCounterGASAbility
 * Precision counter ability triggering 0.35x world time-dilation window for 1.5s upon incoming strike.
 */
UCLASS()
class ASHENOATH_API UAshenFlowCounterGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenFlowCounterGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float TimeDilationFactor = 0.35f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float DilationDuration = 1.5f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool TriggerFlowCounter(AActor* InstigatorActor);
};
