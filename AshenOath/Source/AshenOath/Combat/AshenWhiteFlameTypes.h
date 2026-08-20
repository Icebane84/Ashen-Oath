// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenWhiteFlameTypes.generated.h"

UENUM(BlueprintType)
enum class EWhiteFlameState : uint8
{
	Inactive   UMETA(DisplayName = "Inactive (Standard Soul State)"),
	Primed     UMETA(DisplayName = "Primed (Resolve >= 0.90 & Burnout >= 0.65)"),
	Active     UMETA(DisplayName = "Active (White Pyre-Aether Transmutation)"),
	Cooldown   UMETA(DisplayName = "Cooldown (Exhausted Radiance)")
};

UENUM(BlueprintType)
enum class ECatharsisPhase : uint8
{
	Ignition   UMETA(DisplayName = "Ignition (Exothermic Sap Conversion)"),
	Radiance   UMETA(DisplayName = "Radiance (Pure White Pyre Cleaves)"),
	Sanctified UMETA(DisplayName = "Sanctified (Ground Consecration Complete)")
};

USTRUCT(BlueprintType)
struct FWhiteFlameResolutionPayload
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | WhiteFlame")
	float DurationRemainingSeconds = 12.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | WhiteFlame")
	float EradicatedDebtAmount = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | WhiteFlame")
	float BurnoutReliefPercentage = 0.50f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | WhiteFlame")
	EWhiteFlameState State = EWhiteFlameState::Inactive;
};

USTRUCT(BlueprintType)
struct FSanctifiedGroundZone
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | WhiteFlame")
	FVector CenterLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | WhiteFlame")
	float RadiusUnits = 800.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | WhiteFlame")
	float StaminaBuffMultiplier = 1.20f;
};
