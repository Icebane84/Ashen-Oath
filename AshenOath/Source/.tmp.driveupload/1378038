// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenFlameBladeEmissiveResonanceActor.generated.h"

/**
 * AAshenFlameBladeEmissiveResonanceActor
 * World actor scaling Flame Blade particle intensity based on Corruption.
 */
UCLASS()
class ASHENOATH_API AAshenFlameBladeEmissiveResonanceActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenFlameBladeEmissiveResonanceActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|VFX")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|VFX")
	float GetFlameEmissiveIntensity() const { return FlameEmissiveIntensity; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|VFX")
	float FlameEmissiveIntensity = 1.0f;
};
