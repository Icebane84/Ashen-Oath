// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenLivingCodexTypes.generated.h"

UENUM(BlueprintType)
enum class ECodexFaction : uint8
{
	Oathsworn        UMETA(DisplayName = "The Oathsworn Order"),
	Voidcult         UMETA(DisplayName = "The Voidcult & Ashen Brood"),
	SunderedOrder    UMETA(DisplayName = "The Sundered Order"),
	PrimordialEchoes UMETA(DisplayName = "Primordial Echoes & Titans")
};

UENUM(BlueprintType)
enum class EPsychologicalTone : uint8
{
	Resolute         UMETA(DisplayName = "Resolute (High Resolve)"),
	Cynical          UMETA(DisplayName = "Cynical (High Isolation)"),
	Despairing       UMETA(DisplayName = "Despairing (High Corruption)"),
	Enlightened      UMETA(DisplayName = "Enlightened (Balanced / Transcendent)")
};

USTRUCT(BlueprintType)
struct FCodexEntryData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Codex")
	FName EntryID = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Codex")
	ECodexFaction Faction = ECodexFaction::Oathsworn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Codex")
	FString Title = TEXT("");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Codex")
	FString LoreContent = TEXT("");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Codex")
	bool bIsUnlocked = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Codex")
	bool bHasBeenRead = false;
};
