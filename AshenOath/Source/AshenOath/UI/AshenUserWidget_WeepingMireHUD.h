// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Scenarios/AshenScenario5WeepingMireTypes.h"
#include "AshenUserWidget_WeepingMireHUD.generated.h"

/**
 * UAshenUserWidget_WeepingMireHUD
 * 
 * UMG widget displaying Unchained frenzy duration, heart palpitation BPM, and mire mud movement penalty indicators.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_WeepingMireHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_WeepingMireHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates the Weeping Mire skirmish diagnostics */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Scenario5")
	void UpdateSkirmishHUD(EUnchainedVesselPhase Phase, float HeartBPM, float FrenzyRemaining, int32 GasPocketsDetonated);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario5")
	EUnchainedVesselPhase DisplayedPhase = EUnchainedVesselPhase::Dormant;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario5")
	float DisplayedHeartBPM = 80.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario5")
	float DisplayedFrenzyRemaining = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Scenario5")
	int32 DisplayedGasDetonations = 0;
};
