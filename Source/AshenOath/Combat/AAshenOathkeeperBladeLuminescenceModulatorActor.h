// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Soul/AshenSoulStateVector.h"
#include "AAshenOathkeeperBladeLuminescenceModulatorActor.generated.h"

/**
 * AAshenOathkeeperBladeLuminescenceModulatorActor
 * World actor driving Oathkeeper blade emissive pulse during combat finish.
 */
UCLASS()
class ASHENOATH_API AAshenOathkeeperBladeLuminescenceModulatorActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenOathkeeperBladeLuminescenceModulatorActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|VFX")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|VFX")
	float GetBladeEmissivePulseIntensity() const { return BladeEmissivePulseIntensity; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|VFX")
	float BladeEmissivePulseIntensity = 1.0f;
};
