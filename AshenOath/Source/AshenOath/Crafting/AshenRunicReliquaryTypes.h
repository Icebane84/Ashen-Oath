// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenRunicReliquaryTypes.generated.h"

/**
 * ERunicSocketType
 * 
 * Defines the classification of runic sockets on soul-forged weaponry.
 */
UENUM(BlueprintType)
enum class ERunicSocketType : uint8
{
	None UMETA(DisplayName = "None"),
	BladeCore UMETA(DisplayName = "Blade Core (Kinetic/Poise)"),
	HiltRelic UMETA(DisplayName = "Hilt Relic (Somatic/Stamina)"),
	GuardInscription UMETA(DisplayName = "Guard Inscription (Resonance/Defense)"),
	UmbralMatrix UMETA(DisplayName = "Umbral Matrix (Shadow Transmutation)")
};

/**
 * ESoulForgeAttunementTier
 * 
 * Defines the quality tier and resonance power of a soul-forged runic socket.
 */
UENUM(BlueprintType)
enum class ESoulForgeAttunementTier : uint8
{
	Dormant UMETA(DisplayName = "Dormant (Unsocketed)"),
	Resonant UMETA(DisplayName = "Resonant (Tier 1)"),
	Overcharged UMETA(DisplayName = "Overcharged (Tier 2)"),
	MasterForged UMETA(DisplayName = "Master Forged (Tier 3 - Boss Core)")
};

/**
 * FRunicSocketEntry
 * 
 * Data representation of a single socketed rune on a weapon.
 */
USTRUCT(BlueprintType)
struct FRunicSocketEntry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Reliquary")
	FName RuneId = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Reliquary")
	ERunicSocketType SocketType = ERunicSocketType::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Reliquary")
	ESoulForgeAttunementTier AttunementTier = ESoulForgeAttunementTier::Dormant;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Reliquary")
	float MassModifierKg = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Reliquary")
	float PoiseMultiplier = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Reliquary")
	float StaminaCostScalar = 1.0f;
};

/**
 * FSoulForgeWeaponState
 * 
 * State representing a fully socketed weapon's aggregated weight and resonance.
 */
USTRUCT(BlueprintType)
struct FSoulForgeWeaponState
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Reliquary")
	FName WeaponId = FName(TEXT("NightsteelGreatsword"));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Reliquary")
	float BaseMassKg = 120.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Reliquary")
	float EffectiveMassKg = 120.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Reliquary")
	float TotalPoiseMultiplier = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Reliquary")
	int32 ActiveSocketCount = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Reliquary")
	bool bHasBossCoreInfusion = false;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRuneSocketed, const FName&, WeaponId, const FRunicSocketEntry&, SocketEntry);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRuneUnsocketed, const FName&, WeaponId, ERunicSocketType, SocketType);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWeaponAttunementUpdated, const FSoulForgeWeaponState&, NewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRunicForgeCompleted, bool, bSuccess);
