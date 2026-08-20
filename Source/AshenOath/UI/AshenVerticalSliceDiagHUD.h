// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AshenVerticalSliceDiagHUD.generated.h"

/**
 * AAshenVerticalSliceDiagHUD
 *
 * Vertical slice playtest diagnostic HUD overlay.
 * Renders real-time combat subsystem state using DrawDebugCanvas:
 *
 *   ROW 1 — Core Resources: Health | Stamina | Mana | Sanity
 *   ROW 2 — Corruption: KaelenC (bar) | WhisperIntensity | WhisperVolume
 *   ROW 3 — Companion AI: CompanionState | EncounterTier | ResolutionState
 *   ROW 4 — Enemy: NearbyGhoulCount | TraumaMatrix Target | AdversarialArg
 *   ROW 5 — GAS: Active tags list
 *
 * Toggle via console command: `Ashen.DiagHUD 1/0`
 */
UCLASS()
class ASHENOATH_API AAshenVerticalSliceDiagHUD : public AHUD
{
	GENERATED_BODY()

public:
	AAshenVerticalSliceDiagHUD();

	virtual void DrawHUD() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|DiagHUD")
	bool bEnabled = false;

	UFUNCTION(Exec)
	void AshenDiagHUD(int32 EnableValue);

private:
	void DrawRow(const FString& Label, const FString& Value, float& YOffset, FLinearColor Color = FLinearColor::White);
	void DrawProgressBar(float X, float Y, float Width, float Height, float Fraction, FLinearColor BarColor);
	FString GetCompanionStateName(uint8 State) const;
};
