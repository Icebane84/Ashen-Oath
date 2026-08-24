// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Scenarios/AshenScenario9Types.h"
#include "AshenUserWidget_Scenario9CitadelHUD.generated.h"

/**
 * UAshenUserWidget_Scenario9CitadelHUD
 * 
 * UMG widget displaying current gravity scale, wind anemometer, bridge stability meter, and altitude.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_Scenario9CitadelHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_Scenario9CitadelHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates the Citadel Floating Archipelago HUD display */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Scenario9")
	void UpdateCitadelHUD(
		float GravityScale,
		float WindSpeedMps,
		const FVector& WindDirection,
		float BridgeStability01,
		EVoidGravityZoneTier GravityTier,
		EWindShearGustState WindState);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario9")
	float DisplayedGravityScale = 0.35f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario9")
	float DisplayedWindSpeedMps = 15.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario9")
	FVector DisplayedWindDirection = FVector(1.0f, 0.0f, 0.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario9")
	float DisplayedBridgeStability = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario9")
	EVoidGravityZoneTier DisplayedGravityTier = EVoidGravityZoneTier::LowVoidGravity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario9")
	EWindShearGustState DisplayedWindState = EWindShearGustState::CalmBreeze;
};
