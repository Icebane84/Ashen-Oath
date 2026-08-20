// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenDiegeticTinnitusAudioModulatorComponent.generated.h"

/**
 * UAshenDiegeticTinnitusAudioModulatorComponent
 * Modulates audio tinnitus volume based on Corruption.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticTinnitusAudioModulatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticTinnitusAudioModulatorComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Audio")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Audio")
	float GetTinnitusWhineVolume() const { return TinnitusWhineVolume; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Audio")
	float TinnitusWhineVolume = 0.0f;
};
