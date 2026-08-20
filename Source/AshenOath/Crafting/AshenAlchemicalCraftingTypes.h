// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenAlchemicalCraftingTypes.generated.h"

UENUM(BlueprintType)
enum class EAlchemicalReagent : uint8
{
	GloomwoodSap    UMETA(DisplayName = "Distilled Gloomwood Sap"),
	Ghostbloom      UMETA(DisplayName = "Ghostbloom Petals"),
	SulfurDust      UMETA(DisplayName = "Sulfur Dust")
};

UENUM(BlueprintType)
enum class EAlchemicalItemType : uint8
{
	GloomwoodTripwire UMETA(DisplayName = "Gloomwood Tripwire"),
	FrostVial         UMETA(DisplayName = "Alchemical Frost Vial"),
	SmokeBomb         UMETA(DisplayName = "Ash Smoke Bomb"),
	DazeCanister      UMETA(DisplayName = "Sulfur Daze Canister")
};

USTRUCT(BlueprintType)
struct FAlchemicalRecipe
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Crafting")
	EAlchemicalItemType ItemType = EAlchemicalItemType::GloomwoodTripwire;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Crafting")
	int32 RequiredGloomwoodSap = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Crafting")
	int32 RequiredGhostbloom = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Crafting")
	int32 RequiredSulfurDust = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Crafting")
	int32 OutputQuantity = 1;
};
