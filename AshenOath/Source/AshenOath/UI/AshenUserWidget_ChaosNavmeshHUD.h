// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "World/AshenChaosNavmeshTypes.h"
#include "AshenUserWidget_ChaosNavmeshHUD.generated.h"

/**
 * UAshenUserWidget_ChaosNavmeshHUD
 * 
 * UMG widget displaying active Chaos fracture severity, navmesh obstruction states, and acoustic impact frequencies.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_ChaosNavmeshHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_ChaosNavmeshHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates the Chaos Navmesh HUD displays */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Chaos")
	void UpdateChaosNavmeshHUD(
		EChaosFractureSeverity Severity,
		ENavmeshObstructionState Obstruction,
		float DebrisMassKg,
		float BlockingRadiusUU,
		float AcousticFreqHz);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Chaos")
	EChaosFractureSeverity DisplayedSeverity = EChaosFractureSeverity::IntactSolid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Chaos")
	ENavmeshObstructionState DisplayedObstruction = ENavmeshObstructionState::ClearPath;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Chaos")
	float DisplayedDebrisMass = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Chaos")
	float DisplayedBlockingRadius = 150.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Chaos")
	float DisplayedAcousticFrequency = 450.0f;
};
