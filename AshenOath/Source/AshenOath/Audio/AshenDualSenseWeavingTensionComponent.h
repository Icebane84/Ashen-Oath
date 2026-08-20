// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenMemoryWeavingTypes.h"
#include "AshenDualSenseWeavingTensionComponent.generated.h"

/**
 * UAshenDualSenseWeavingTensionComponent
 * Modulates DualSense adaptive trigger motorized pull-back force (0.1 to 1.0) and triggers sharp tactile snap pulses when threads break under load.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDualSenseWeavingTensionComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDualSenseWeavingTensionComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Haptics")
	float TriggerMotorResistance = 0.0f; // 0.0 to 1.0

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Haptics")
	void UpdateTriggerTension(float TensionScalar, EFilamentTensionState State);
};
