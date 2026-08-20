// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenGASMontageImprintModulatorComponent.generated.h"

/**
 * UAshenGASMontageImprintModulatorComponent
 * Modulates attack animation playback rate based on Resolve.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGASMontageImprintModulatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGASMontageImprintModulatorComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	float GetMontagePlayRateMultiplier() const { return PlayRateMultiplier; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Combat")
	float PlayRateMultiplier = 1.0f;
};
