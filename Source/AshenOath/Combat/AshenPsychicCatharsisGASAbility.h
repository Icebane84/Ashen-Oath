// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenPsychicCatharsisGASAbility.generated.h"

/**
 * UAshenPsychicCatharsisGASAbility
 * GAS ability purging stored psychological trauma into a 600.0 radial damage burst while restoring +30.0 Resolve.
 */
UCLASS()
class ASHENOATH_API UAshenPsychicCatharsisGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenPsychicCatharsisGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float CatharsisBaseDamage = 600.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float ResolveRestored = 30.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float BlastRadius = 900.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool UnleashPsychicCatharsis(AActor* InstigatorActor);
};
