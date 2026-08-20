// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenMapTypes.generated.h"

UENUM(BlueprintType)
enum class EAshenMapZoomLevel : uint8
{
	WorldMap,
	Province,
	Region,
	Roads,
	Memories,
	Constellation
};

UENUM(BlueprintType)
enum class EAshenMapRenderPassType : uint8
{
	GeographyBase,
	ExpeditionTemporal,
	ResonanceMemory,
	WorldviewOverlays
};

USTRUCT(BlueprintType)
struct FAshenMapPin
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Map")
	FGuid PinGuid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Map")
	FVector2D NormalizedCoordinates = FVector2D::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Map")
	FText PinTitle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Map")
	FName AuthorName; // e.g., "Kaelen", "Garrett", "Serafina"

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Map")
	FDateTime DatePlaced;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMapZoomLevelChanged, EAshenMapZoomLevel, PreviousLevel, EAshenMapZoomLevel, NewLevel);
