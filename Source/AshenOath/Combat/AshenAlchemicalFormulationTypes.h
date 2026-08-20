// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenAlchemicalFormulationTypes.generated.h"

UENUM(BlueprintType)
enum class EAlchemicalMatrixType : uint8
{
	BurningSteelOil      UMETA(DisplayName = "Burning Steel Oil (Thermal Armor-Melter)"),
	GloomwoodDampener    UMETA(DisplayName = "Gloomwood Dampener (Shadow Suppressant)"),
	SulfurousSmokeBalm   UMETA(DisplayName = "Sulfurous Smoke Balm (Tactical Obfuscator)"),
	GhostbloomFlashFlare UMETA(DisplayName = "Ghostbloom Flash Flare (Luminescent Stun)")
};

USTRUCT(BlueprintType)
struct FGarrettAlchemicalRecipe
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Alchemy")
	EAlchemicalMatrixType MatrixType = EAlchemicalMatrixType::BurningSteelOil;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Alchemy")
	FName BaseMaterial = TEXT("Refined_Oil_Base");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Alchemy")
	FName ActiveCatalyst = TEXT("Sulfur_Carbon_Dust");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Alchemy")
	int32 CraftedQuantity = 3;
};

USTRUCT(BlueprintType)
struct FAlchemicalInventoryPouch
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Alchemy")
	int32 BurningSteelOilVials = 4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Alchemy")
	int32 GloomwoodDampenerNeedles = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Alchemy")
	int32 SmokeBalmCharges = 2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Alchemy")
	int32 GhostbloomFlares = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Alchemy")
	int32 CaltropSupply = 5;
};
