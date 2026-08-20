// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenCampfireRestGASAbility.generated.h"

/**
 * UAshenCampfireRestGASAbility
 * Regenerates health, stamina reserves, and clears transient cognitive dissonance while resting.
 */
UCLASS()
class ASHENOATH_API UAshenCampfireRestGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenCampfireRestGASAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Campfire GAS")
	float HealthRestorationRate = 25.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Campfire GAS")
	bool ActivateCampfireRestRegeneration();
};
