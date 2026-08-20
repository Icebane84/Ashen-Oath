// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_GarrettSentinelsEclipse.generated.h"

/**
 * UGA_GarrettSentinelsEclipse
 * Garrett's pinnacle cooperative execution ability.
 * Vaults behind target, forces 4.0x threat redirection, and applies 2.5x Flank Multiplier weakspot for Kaelen.
 */
UCLASS()
class ASHENOATH_API UGA_GarrettSentinelsEclipse : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UGA_GarrettSentinelsEclipse();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Sentinel | Mechanics")
	float MaxGrappleRange = 1000.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Sentinel | Mechanics")
	float WarpLungeSpeed = 1600.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Sentinel | Mechanics")
	float ThreatGenerationMultiplier = 4.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Sentinel | Mechanics")
	float FlankingDamageMultiplier = 2.5f;

	UFUNCTION(BlueprintCallable, Category = "Sentinel | Execution")
	bool ExecuteSentinelVault(AActor* GarrettActor, AActor* TargetEnemy);
};
