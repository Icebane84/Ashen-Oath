// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenTransferenceBurnoutTypes.h"
#include "AshenSerafinaBurnoutReceiverComponent.generated.h"

/**
 * UAshenSerafinaBurnoutReceiverComponent
 * 
 * Tracks Serafina's cumulative burnout, applying progressive recovery delay penalties
 * and dimming aura stability.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaBurnoutReceiverComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSerafinaBurnoutReceiverComponent();

	/** Absorbs trauma and returns updated snapshot */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Companions|Serafina")
	FTransferenceBurdenSnapshot AbsorbTraumaPayload(float RawTrauma);

	/** Resets burnout at campfire rest */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Companions|Serafina")
	void ResetBurnoutAtCampfire();

	UFUNCTION(BlueprintPure, Category = "Ashen|Companions|Serafina")
	float GetCumulativeBurnout() const { return CumulativeBurnout; }

	UFUNCTION(BlueprintPure, Category = "Ashen|Companions|Serafina")
	EBurnoutSeverityTier GetBurnoutTier() const { return CurrentTier; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Companions|Serafina")
	float CumulativeBurnout = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Companions|Serafina")
	EBurnoutSeverityTier CurrentTier = EBurnoutSeverityTier::Nominal;
};
