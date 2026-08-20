// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenDiegeticArmorCrackleAudioModulator.generated.h"

/**
 * UAshenDiegeticArmorCrackleAudioModulator
 * Modulates metal armor scraping audio volume based on Corruption.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticArmorCrackleAudioModulator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticArmorCrackleAudioModulator();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Audio")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Audio")
	float GetArmorCrackleVolumeMultiplier() const { return ArmorCrackleVolumeMultiplier; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Audio")
	float ArmorCrackleVolumeMultiplier = 1.0f;
};
