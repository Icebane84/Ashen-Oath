// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Narrative/AshenMapTypes.h"
#include "AshenCartographerMapViewModel.generated.h"

/**
 * UAshenCartographerMapViewModel
 * MVVM ViewModel evaluating C++ Soul State Vector data, filtering 4 render pass layers, and computing PBR MPC parameters.
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenCartographerMapViewModel : public UObject
{
	GENERATED_BODY()

public:
	UAshenCartographerMapViewModel();

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath|Map")
	FOnMapZoomLevelChanged OnMapZoomLevelChanged;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Map")
	EAshenMapZoomLevel CurrentZoomLevel = EAshenMapZoomLevel::WorldMap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Map")
	float ParchmentSootCoverage = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Map")
	float InkBleedIntensity = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|Map")
	void SetZoomLevel(EAshenMapZoomLevel NewZoomLevel);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|Map")
	void EvaluateSoulStateVectorParameters(float IntegrationDebt, float CorruptionAmount);
};
