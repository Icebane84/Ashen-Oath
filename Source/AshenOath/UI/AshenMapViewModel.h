// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenMapViewModel.generated.h"

UENUM(BlueprintType)
enum class EAshenWorldviewFilter : uint8
{
	Kaelen     UMETA(DisplayName = "Kaelen's Lens"),
	Garrett    UMETA(DisplayName = "Garrett's Lens"),
	Serafina   UMETA(DisplayName = "Serafina's Lens")
};

USTRUCT(BlueprintType)
struct ASHENOATH_API FAshenMapRenderData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Map Render Data")
	float ParchmentSootAlpha = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Map Render Data")
	float InkBleedIntensity = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Map Render Data")
	float VignetteDesaturation = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Map Render Data")
	bool bTriggerShadowMarginalia = false;

	UPROPERTY(BlueprintReadOnly, Category = "Map Render Data")
	bool bNavigationalSanctityMaintained = true;

	UPROPERTY(BlueprintReadOnly, Category = "Map Render Data")
	FText ActiveLocationHeader;

	UPROPERTY(BlueprintReadOnly, Category = "Map Render Data")
	TArray<FText> FormattedMarginaliaEntries;
};

UCLASS(BlueprintType)
class ASHENOATH_API UAshenMapViewModel : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void EvaluateSoulState(const FSoulStateVector& StateVector, EAshenWorldviewFilter ActiveFilter);

	UFUNCTION(BlueprintPure, Category = "Ashen Oath | UI")
	const FAshenMapRenderData& GetMapRenderData() const { return CachedRenderData; }

private:
	UPROPERTY()
	FAshenMapRenderData CachedRenderData;
};
