// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenControllerFrictionTypes.generated.h"

UENUM(BlueprintType)
enum class EStrugglePhase : uint8
{
	Phase1_DiscordantHum      UMETA(DisplayName = "Phase 1: The Discordant Hum (Resisting Whispers)"),
	Phase2_MartyrsPivot       UMETA(DisplayName = "Phase 2: The Martyr's Pivot (Protective Intercept)"),
	Phase3_ReclamationCrash   UMETA(DisplayName = "Phase 3: The Reclamation Crash (Resetting the Bone)")
};

USTRUCT(BlueprintType)
struct FTriggerLockState
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Friction")
	float L2Travel = 0.0f; // 0.0 to 1.0 (Inner Flame)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Friction")
	float R2Travel = 0.0f; // 0.0 to 1.0 (Nightsteel Weight)

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Friction")
	bool bIsWithinFiftyPercentTolerance = false;
};

USTRUCT(BlueprintType)
struct FBreathingRhythmCadence
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Friction")
	bool bExpectingInhale = true; // Alternates True (Cross: Inhale) -> False (Square: Exhale)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Friction")
	float BreathBPM = 45.0f; // Rapid, strained breath cadence

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Friction")
	int32 ConsecutiveSuccessfulBreaths = 0;
};
