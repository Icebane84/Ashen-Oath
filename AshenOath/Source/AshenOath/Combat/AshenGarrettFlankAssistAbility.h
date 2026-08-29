// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenGarrettFlankAssistAbility.generated.h"

/**
 * UAshenGarrettFlankAssistAbility
 * Activated via Assist input tag (E).
 * Motion-warps to target rear transform; deals 1.8x stagger multiplier against enemies in Recovery state
 * and accumulates companion fatigue.
 */
UCLASS()
class ASHENOATH_API UAshenGarrettFlankAssistAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenGarrettFlankAssistAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Flank")
	float BaseDamage = 120.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Flank")
	float BaseStaggerDamage = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Flank")
	float RecoveryStaggerMultiplier = 1.8f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Flank")
	FVector LastWarpDestination = FVector::ZeroVector;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Flank")
	bool ExecuteFlankAssist(AActor* TargetActor, bool bTargetInRecoveryState);
};
