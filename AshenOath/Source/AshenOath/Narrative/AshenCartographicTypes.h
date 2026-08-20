// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenCartographicTypes.generated.h"

UENUM(BlueprintType)
enum class ECartographicPinType : uint8
{
	SanctuaryCampfire  UMETA(DisplayName = "Sanctuary Campfire (Safe Haven)"),
	MemoryEcho         UMETA(DisplayName = "Memory Echo (Trauma Site)"),
	AlchemicalHarvest  UMETA(DisplayName = "Alchemical Harvest (Flora / Reagents)"),
	AbyssalRift        UMETA(DisplayName = "Abyssal Rift (Null-Zone Incursion)")
};

UENUM(BlueprintType)
enum class EParchmentPencilStyle : uint8
{
	CharcoalSketch     UMETA(DisplayName = "Charcoal Sketch (Raw & Unrefined)"),
	GoldenThreadStitch UMETA(DisplayName = "Golden Thread Stitch (Resonant & Purified)"),
	SootStainedWash    UMETA(DisplayName = "Soot Stained Wash (Trauma Corrupted)")
};

UENUM(BlueprintType)
enum class ECompassResonanceState : uint8
{
	Dormant            UMETA(DisplayName = "Dormant (No Active Beacon)"),
	Attuned            UMETA(DisplayName = "Attuned (Sanctuary Beacon Locked)"),
	Disrupted          UMETA(DisplayName = "Disrupted (Null-Zone Magnetic Interference)")
};

USTRUCT(BlueprintType)
struct FJournalMapPin
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Cartography")
	FGuid PinId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Cartography")
	FVector WorldLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Cartography")
	FString PinLabel = TEXT("Discovered Landmark");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Cartography")
	ECartographicPinType PinType = ECartographicPinType::SanctuaryCampfire;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Cartography")
	EParchmentPencilStyle ScribeStyle = EParchmentPencilStyle::CharcoalSketch;
};

USTRUCT(BlueprintType)
struct FCartographicRegionData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Cartography")
	FName RegionName = FName(TEXT("Shadowfen_Basin"));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Cartography")
	float ExplorationPercentage = 0.0f; // 0.0 to 1.0

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Cartography")
	bool bIsFullyInked = false;
};
