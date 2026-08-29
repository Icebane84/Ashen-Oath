// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenAlchemicalSlagTypes.h"
#include "AshenAlchemicalSlagHapticBridge.generated.h"

/**
 * UAshenAlchemicalSlagHapticBridge
 * 
 * Maps DualSense haptic motor feedback for coating applications and chemical reactions (Conflagration 0.95 heavy blast, Thermal Shock sharp crackle).
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAlchemicalSlagHapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenAlchemicalSlagHapticBridge();

	/** Evaluates DualSense haptic motor gains */
	UFUNCTION(BlueprintPure, Category = "Ashen|AlchemicalSlag|Haptics")
	void EvaluateReactionHaptics(
		EThermalReactionType Reaction,
		float& OutHeavyMotorGain,
		float& OutLightMotorGain);
};
