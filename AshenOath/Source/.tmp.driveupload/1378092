// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenCombatStanceTypes.generated.h"

UENUM(BlueprintType)
enum class ECombatStance : uint8
{
	Flow     UMETA(DisplayName = "Flow (Balanced / Counter)"),
	Aegis    UMETA(DisplayName = "Aegis (Heavy Defense / Poise)"),
	Berserk  UMETA(DisplayName = "Berserk (High Velocity / Aggression)")
};

USTRUCT(BlueprintType)
struct FStanceModifiers
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Combat")
	float DamageMultiplier = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Combat")
	float AttackSpeedMultiplier = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Combat")
	float PoiseBonus = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Combat")
	float DamageTakenMultiplier = 1.0f;
};
