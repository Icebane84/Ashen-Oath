// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDualSenseAdaptiveTriggerComponent.generated.h"

/**
 * UAshenDualSenseAdaptiveTriggerComponent
 * Modulates hardware L2/R2 trigger resistance based on Serafina's Empathic Burnout and Transference strain.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDualSenseAdaptiveTriggerComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDualSenseAdaptiveTriggerComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Haptics")
	float L2TriggerResistanceScalar = 0.0f; // 0.0 (Free) to 1.0 (Stiff / Heavy Resistance)

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Haptics")
	void UpdateTriggerResistance(float SerafinaBurnoutScalar);
};
