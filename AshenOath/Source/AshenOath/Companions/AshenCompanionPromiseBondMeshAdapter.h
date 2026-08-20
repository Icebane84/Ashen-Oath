// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenCanonicalPromiseTypes.h"
#include "AshenCompanionPromiseBondMeshAdapter.generated.h"

/**
 * UAshenCompanionPromiseBondMeshAdapter
 * 
 * Modulates companion posture blendspaces (resolute stance, hand-on-chest)
 * when a sacred vow is active or recalled.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionPromiseBondMeshAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionPromiseBondMeshAdapter();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Sets target vow bond weight */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Companions|Vow")
	void SetVowBondWeight(float TargetWeight);

	UFUNCTION(BlueprintPure, Category = "Ashen|Companions|Vow")
	float GetCurrentVowBondWeight() const { return CurrentWeight; }

private:
	float CurrentWeight = 0.0f;
	float DesiredWeight = 0.0f;
};
