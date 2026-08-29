// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "World/AshenSanctuaryField.h"
#include "AshenSerafinaSacredBarrierGASAbility.generated.h"

/**
 * UAshenSerafinaSacredBarrierGASAbility
 * GAS ability executing Serafina's Sacred Barrier, dynamically spawning AAshenSanctuaryField
 * and accumulating companion fatigue.
 */
UCLASS()
class ASHENOATH_API UAshenSerafinaSacredBarrierGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSerafinaSacredBarrierGASAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Barrier")
	TSubclassOf<AAshenSanctuaryField> SanctuaryFieldClass;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Barrier")
	AAshenSanctuaryField* SpawnSacredBarrier(FVector TargetLocation);
};
