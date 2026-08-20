// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenInnerWorldTypes.generated.h"

UENUM(BlueprintType)
enum class EAshenInnerWorldLandscapeState : uint8
{
	SunDappledGlade,     // High Hope
	ShadowedRuinedHamlet, // High Despair / Trauma
	CrumblingFortress,    // Critical Static Noise
	SacredMemorialGlade   // Attuned / Integrated
};

UENUM(BlueprintType)
enum class EAshenMemoryBattleOutcome : uint8
{
	Pending,
	VictoryIntegrated,
	DefeatShadowCorruption
};

USTRUCT(BlueprintType)
struct FAshenMemoryBattleDefinition
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|InnerWorld")
	FName MemoryID; // e.g. "Memory_EldrinsGrace", "Memory_ParentalProtection"

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|InnerWorld")
	FText MemoryTitle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|InnerWorld")
	FName UnlockedAbilityTag;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInnerWorldLandscapeShifted, EAshenInnerWorldLandscapeState, PrevState, EAshenInnerWorldLandscapeState, NewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMemoryBattleCompleted, FName, MemoryID, EAshenMemoryBattleOutcome, Outcome);
