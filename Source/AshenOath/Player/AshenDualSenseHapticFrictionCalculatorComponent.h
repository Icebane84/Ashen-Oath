// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenEmpathicNovaTypes.h"
#include "AshenDualSenseHapticFrictionCalculatorComponent.generated.h"

/**
 * UAshenDualSenseHapticFrictionCalculatorComponent
 * Calculates dual-trigger physical resistance (180-255) and asymmetric dual-channel haptic frequencies (20-40Hz Left vs 150-200Hz Right).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDualSenseHapticFrictionCalculatorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDualSenseHapticFrictionCalculatorComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Haptics")
	FHapticFrictionProfile ComputeHapticFriction(float KaelenCorruption, float SerafinaBurnout, float ExecutionProgress) const;
};
