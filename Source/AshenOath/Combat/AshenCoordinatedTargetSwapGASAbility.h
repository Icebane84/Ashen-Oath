// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenCoordinatedTargetSwapGASAbility.generated.h"

/**
 * UAshenCoordinatedTargetSwapGASAbility
 * Tactical coordination ability allowing Garrett and Kaelen to swap targets, cleaving the Shade and exploiting the Bastion's vulnerable joints.
 */
UCLASS()
class ASHENOATH_API UAshenCoordinatedTargetSwapGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenCoordinatedTargetSwapGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float BonusJointDamage = 850.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool ExecuteTargetSwap(AActor* KaelenActor, AActor* GarrettActor);
};
