// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Combat/AshenAlchemicalSlagTypes.h"
#include "AshenUserWidget_AlchemicalSlagHUD.generated.h"

/**
 * UAshenUserWidget_AlchemicalSlagHUD
 * 
 * Renders the circular soot battery gauge (0-100%), active alchemical coating badge, remaining strike charges, and superheated slag flare alerts.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_AlchemicalSlagHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_AlchemicalSlagHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates the displayed soot and coating telemetry */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|AlchemicalSlag")
	void UpdateSlagHUD(
		float SootPercent,
		EOathbringerBladeSurfaceState SurfaceState,
		EAlchemicalBladeCoating Coating,
		int32 RemainingCharges);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|AlchemicalSlag")
	float DisplayedSoot = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|AlchemicalSlag")
	EOathbringerBladeSurfaceState DisplayedSurfaceState = EOathbringerBladeSurfaceState::PolishedResolve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|AlchemicalSlag")
	EAlchemicalBladeCoating DisplayedCoating = EAlchemicalBladeCoating::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|AlchemicalSlag")
	int32 DisplayedCharges = 0;
};
