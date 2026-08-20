// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AI/AshenCombatEcosystemTypes.h"
#include "AshenUserWidget_BossPhasePuzzleHUD.generated.h"

/**
 * UAshenUserWidget_BossPhasePuzzleHUD
 * Non-intrusive somatic HUD tracking 3-phase puzzle progress (Observation Stalemate -> Breakthrough -> Resonance Synthesis).
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_BossPhasePuzzleHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	EBossPuzzlePhase DisplayedBossPhase = EBossPuzzlePhase::Phase1_ObservationStalemate;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateBossPhaseHUD(EBossPuzzlePhase NewPhase);
};
