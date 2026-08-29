// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Combat/AshenRunicForgeTypes.h"
#include "AshenUserWidget_RunicForgeHUD.generated.h"

/**
 * UAshenUserWidget_RunicForgeHUD
 * 
 * Renders the Campfire Anvil Runic Forge UI: 5-Tier Oathbringer evolution badge, 4 Guard Sigil Socket rings, and Flow Resonance preview.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_RunicForgeHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_RunicForgeHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates the forge UI */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|RunicForge")
	void UpdateForgeHUD(
		EOathbringerAscensionTier Tier,
		ESigilResonanceEffect VomTagSigil,
		ESigilResonanceEffect PflugSigil,
		ESigilResonanceEffect OchsSigil,
		ESigilResonanceEffect MordhauSigil);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|RunicForge")
	EOathbringerAscensionTier DisplayedTier = EOathbringerAscensionTier::Tier1_DullNightsteel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|RunicForge")
	ESigilResonanceEffect DisplayedVomTag = ESigilResonanceEffect::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|RunicForge")
	ESigilResonanceEffect DisplayedPflug = ESigilResonanceEffect::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|RunicForge")
	ESigilResonanceEffect DisplayedOchs = ESigilResonanceEffect::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|RunicForge")
	ESigilResonanceEffect DisplayedMordhau = ESigilResonanceEffect::None;
};
