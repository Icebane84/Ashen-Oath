// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenShadowMarkCorruptionGASAbility.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnShadowMarkBurstActivatedSignature, float, AoEDamage, float, BileSpawnRate, float, TrustPenalty);

/**
 * UAshenShadowMarkCorruptionGASAbility
 * GAS ability triggering Shadow Mark max saturation burst, dealing 250 Void AoE damage,
 * modulating Nyxian bile seepage shader parameters, and inflicting companion trust atrophy.
 */
UCLASS()
class ASHENOATH_API UAshenShadowMarkCorruptionGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenShadowMarkCorruptionGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | ShadowMark")
	float BurstAoEDamage = 250.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | ShadowMark")
	float BurstRadiusUnits = 600.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | ShadowMark")
	float CompanionTrustPenalty = 15.0f;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | ShadowMark|Events")
	FOnShadowMarkBurstActivatedSignature OnShadowMarkBurstActivated;

	/** Executes the Shadow Mark corruption burst payload */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | ShadowMark")
	bool ActivateShadowMarkBurst(AActor* InstigatorActor);
};
