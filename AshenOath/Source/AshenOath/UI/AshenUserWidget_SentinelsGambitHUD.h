// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Scenarios/AshenScenario2SentinelsGambitTypes.h"
#include "AshenUserWidget_SentinelsGambitHUD.generated.h"

/**
 * UAshenUserWidget_SentinelsGambitHUD
 * 
 * UMG widget displaying trap deployment slots, AI path utility disruption, and ravine funnel counter.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_SentinelsGambitHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_SentinelsGambitHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates the tactical HUD diagnostic counters */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Scenario2")
	void UpdateTacticalDiagnostics(int32 TrapsPlaced, float AIUtilityScore, int32 FunneledCount);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario2")
	int32 DisplayedTrapsPlaced = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario2")
	float DisplayedAIUtility = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario2")
	int32 DisplayedFunneledCount = 0;
};
