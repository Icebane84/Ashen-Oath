// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenSerafinaSanctuaryGASAbility.generated.h"

/**
 * UAshenSerafinaSanctuaryGASAbility
 * GAS Gameplay Ability manifesting the consecrated sanctuary ring.
 */
UCLASS()
class ASHENOATH_API UAshenSerafinaSanctuaryGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenSerafinaSanctuaryGASAbility();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | GAS")
	bool CastSanctuaryRing(FVector CastLocation);
};
