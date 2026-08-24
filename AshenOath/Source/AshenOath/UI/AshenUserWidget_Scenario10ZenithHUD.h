// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Scenarios/AshenScenario10Types.h"
#include "AshenUserWidget_Scenario10ZenithHUD.generated.h"

/**
 * UAshenUserWidget_Scenario10ZenithHUD
 * 
 * UMG widget displaying the Apotheosis Resonance gauge, tri-soul attunement, combo damage multiplier, and consequence ending.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_Scenario10ZenithHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_Scenario10ZenithHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates the Zenith HUD display */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Scenario10")
	void UpdateZenithHUD(
		float Resonance01,
		float TrustScore01,
		float Debt01,
		float DamageMultiplier,
		EApotheosisResonanceStage Stage,
		EZenithConsequenceEnding Ending);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario10")
	float DisplayedResonance = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario10")
	float DisplayedTrust = 0.85f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario10")
	float DisplayedDebt = 0.20f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario10")
	float DisplayedDamageMultiplier = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario10")
	EApotheosisResonanceStage DisplayedStage = EApotheosisResonanceStage::DormantLatent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario10")
	EZenithConsequenceEnding DisplayedEnding = EZenithConsequenceEnding::RadiantTransfiguration;
};
