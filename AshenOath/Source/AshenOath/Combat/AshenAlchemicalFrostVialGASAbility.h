// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenAlchemicalFrostVialGASAbility.generated.h"

/**
 * UAshenAlchemicalFrostVialGASAbility
 * GAS ability throwing an alchemical frost canister inflicting -60% movement slow and 250.0 frost damage in a 600uu radius.
 */
UCLASS()
class ASHENOATH_API UAshenAlchemicalFrostVialGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenAlchemicalFrostVialGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float FrostDamage = 250.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float BlastRadius = 600.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float SlowMultiplier = 0.40f; // -60% speed

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float SlowDuration = 6.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool ThrowFrostVial(AActor* InstigatorActor, const FVector& TargetLocation);
};
