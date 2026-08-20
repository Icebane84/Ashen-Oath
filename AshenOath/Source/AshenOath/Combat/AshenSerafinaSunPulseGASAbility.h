// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenSerafinaSunPulseGASAbility.generated.h"

/**
 * UAshenSerafinaSunPulseGASAbility
 * Serafina's emergency containment ability emitting a high-intensity white light flash that disorients and interrupts Unchained Kaelen for 3.0s.
 */
UCLASS()
class ASHENOATH_API UAshenSerafinaSunPulseGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenSerafinaSunPulseGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Containment")
	float DisorientDurationSeconds = 3.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Containment")
	bool CastSunPulseFlash(AActor* CasterActor, AActor* TargetUnchainedActor);
};
