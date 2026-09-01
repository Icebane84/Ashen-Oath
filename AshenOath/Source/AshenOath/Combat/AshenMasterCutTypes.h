// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AshenMasterCutTypes.generated.h"

UENUM(BlueprintType)
enum class EAshenMasterCutType : uint8
{
	Zornhau      UMETA(DisplayName = "Zornhau (Wrath Hew)"),
	Krumphau     UMETA(DisplayName = "Krumphau (Crooked Hew)"),
	Zwerchhau    UMETA(DisplayName = "Zwerchhau (Thwart Hew)"),
	Schielhau    UMETA(DisplayName = "Schielhau (Squinting Hew)"),
	Scheitelhau  UMETA(DisplayName = "Scheitelhau (Crown Hew)"),
	Mordhau      UMETA(DisplayName = "Mordhau (Pommel / Half-Sword Strike)")
};

USTRUCT(BlueprintType)
struct FAshenStrikeParameters
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat|Strike")
	EAshenMasterCutType StrikeType = EAshenMasterCutType::Zornhau;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat|Strike")
	float BaseDamage = 65.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat|Strike")
	float PoiseDamage = 40.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat|Strike")
	float ArmorPenetrationFraction = 0.20f; // 0.0 to 1.0

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat|Strike")
	float StaminaCost = 25.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat|Strike")
	FGameplayTag RequiredGuardTag = FGameplayTag::RequestGameplayTag(FName("State.Stance.VomTag"));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat|Strike")
	FGameplayTag NextGuardTag = FGameplayTag::RequestGameplayTag(FName("State.Stance.Pflug"));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat|Strike")
	float ApexTimeSeconds = 0.50f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat|Strike")
	float WindowDurationSeconds = 0.15f; // 115 BPM Invariant Window
};
