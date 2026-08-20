// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenEchoReclamationGASAbility.generated.h"

/**
 * UAshenEchoReclamationGASAbility
 * GAS ability executing psychological echo reclamation ritual upon defeating inner phantoms.
 */
UCLASS()
class ASHENOATH_API UAshenEchoReclamationGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenEchoReclamationGASAbility();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | GAS")
	bool ExecuteEchoReclamationRitual();
};
