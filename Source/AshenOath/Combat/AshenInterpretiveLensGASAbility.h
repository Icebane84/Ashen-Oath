// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenSoulConstellationTypes.h"
#include "AshenInterpretiveLensGASAbility.generated.h"

/**
 * UAshenInterpretiveLensGASAbility
 * GAS ability channeling the active philosophical lens into empowered combat passives and resonance aura.
 */
UCLASS()
class ASHENOATH_API UAshenInterpretiveLensGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenInterpretiveLensGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Lenses")
	float LensAuraRadius = 900.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Lenses")
	bool ActivateLensResonance(AActor* InstigatorActor, EInterpretiveLens Lens);
};
