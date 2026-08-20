// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenDualityTypes.generated.h"

UENUM(BlueprintType)
enum class EAshenDualityState : uint8
{
	LightMode,      // Baseline opacity 0.05-0.15 mark, clean metal
	TransitionPhase1, // 0.00 -> 0.55: Shadow mark darkens, seam grime accumulates
	TransitionPhase2, // 0.35 -> 1.00: Total armor soot, tabard tears, wolf pommel glowing crimson
	FullDarkMode     // Fully transformed dark mode
};

USTRUCT(BlueprintType)
struct FAshenCorruptionMaskValues
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Duality")
	float ArmorSootR = 0.0f; // Red Channel: Soot Mask

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Duality")
	float SeamGrimeG = 0.0f; // Green Channel: Seam Grime

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Duality")
	float TabardRaggednessB = 0.0f; // Blue Channel: Cloth Char/Tearing

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Duality")
	float EyeBladeEmissiveA = 0.0f; // Alpha Channel: Eye & Rune Emissive
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDualityStateShifted, EAshenDualityState, PreviousState, EAshenDualityState, NewState);
