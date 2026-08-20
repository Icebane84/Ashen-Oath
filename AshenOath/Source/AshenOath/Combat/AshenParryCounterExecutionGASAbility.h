// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenParryCounterExecutionGASAbility.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnParrySuccessful, AActor*, Attacker, bool, bIsExecutionWindowOpened);

/**
 * UAshenParryCounterExecutionGASAbility
 * Frame-accurate parry window, slow-mo dilation (0.2x), direction deflection, and counter-execution montage trigger.
 */
UCLASS()
class ASHENOATH_API UAshenParryCounterExecutionGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenParryCounterExecutionGASAbility();

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Combat")
	FOnParrySuccessful OnParrySuccessful;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Combat")
	float ParryWindowDuration = 0.15f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Combat")
	float SlowMoTimeDilation = 0.20f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool TriggerParryWindow();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool ResolveParryHit(AActor* AttackerActor, float IncomingPoiseDamage);
};
