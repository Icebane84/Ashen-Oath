// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Tactics/AshenSquadTacticalTypes.h"
#include "AshenTacticalReticleVFXComponent.generated.h"

/**
 * UAshenTacticalReticleVFXComponent
 * 
 * Modulates tactical holographic beam opacity and pulse rates during squad aiming.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTacticalReticleVFXComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTacticalReticleVFXComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Sets target reticle opacity */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Tactics|VFX")
	void SetReticleOpacity(float TargetOpacity);

	UFUNCTION(BlueprintPure, Category = "Ashen|Tactics|VFX")
	float GetCurrentOpacity() const { return CurrentOpacity; }

private:
	float CurrentOpacity = 0.0f;
	float DesiredOpacity = 0.0f;
};
