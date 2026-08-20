// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenRehabilitationGASAbility.generated.h"

/**
 * UAshenRehabilitationGASAbility
 * GAS Gameplay Ability channeling identity synthesis ritual energy.
 */
UCLASS()
class ASHENOATH_API UAshenRehabilitationGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenRehabilitationGASAbility();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | GAS")
	bool ChannelRehabilitationRitual();
};
