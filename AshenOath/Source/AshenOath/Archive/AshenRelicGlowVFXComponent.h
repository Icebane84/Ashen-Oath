// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Archive/AshenCodexArchiveTypes.h"
#include "AshenRelicGlowVFXComponent.generated.h"

/**
 * UAshenRelicGlowVFXComponent
 * 
 * Smooths and modulates relic emissive intensity during 3D examination mode.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRelicGlowVFXComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenRelicGlowVFXComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Sets target glow intensity */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Archive|VFX")
	void SetTargetGlow(float NewGlow);

	UFUNCTION(BlueprintPure, Category = "Ashen|Archive|VFX")
	float GetCurrentGlow() const { return CurrentGlow; }

private:
	float CurrentGlow = 0.0f;
	float DesiredGlow = 0.0f;
};
