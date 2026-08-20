// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AshenGameplayAbility.generated.h"

/**
 * UAshenGameplayAbility
 *
 * Base Gameplay Ability class for Ashen Oath GAS abilities.
 */
UCLASS()
class ASHENOATH_API UAshenGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenGameplayAbility();
};
