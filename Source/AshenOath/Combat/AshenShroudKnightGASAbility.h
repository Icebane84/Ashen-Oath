// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenShroudKnightGASAbility.generated.h"

/**
 * UAshenShroudKnightGASAbility
 * GAS Ability triggering spectral phase dash and paranoia burst.
 */
UCLASS()
class ASHENOATH_API UAshenShroudKnightGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenShroudKnightGASAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Shroud GAS")
	float ParanoiaBurstAmount = 0.25f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Shroud GAS")
	bool TriggerShroudParanoiaBurst(AActor* TargetActor);
};
