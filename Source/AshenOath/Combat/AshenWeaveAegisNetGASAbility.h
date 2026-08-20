// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenWeaveAegisNetGASAbility.generated.h"

/**
 * UAshenWeaveAegisNetGASAbility
 * GAS ability allowing Serafina to weave a reactive golden net of light across Kaelen's posture (6.0s duration, absorbs 2 poise breaks).
 */
UCLASS()
class ASHENOATH_API UAshenWeaveAegisNetGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenWeaveAegisNetGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Weaving")
	float AegisDurationSeconds = 6.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Weaving")
	int32 TotalShieldLayers = 2;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Weaving")
	bool DeployAegisNetOnTarget(AActor* TargetCharacter);
};
