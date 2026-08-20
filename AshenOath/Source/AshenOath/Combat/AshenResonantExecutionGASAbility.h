// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenResonantExecutionGASAbility.generated.h"

/**
 * UAshenResonantExecutionGASAbility
 * Execution stance ability triggering cinematic time-dilation (0.15x) and kinetic force transfer during the Nova impact window.
 */
UCLASS()
class ASHENOATH_API UAshenResonantExecutionGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenResonantExecutionGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Nova")
	float CinematicTimeDilation = 0.15f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Nova")
	float ImpactHoldDuration = 2.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Nova")
	bool InitiateResonantExecution(AActor* InstigatorActor);
};
