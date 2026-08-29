// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Narrative/AshenCSEQuestBoardTypes.h"
#include "AshenUserWidget_DissonanceQuestBoardHUD.generated.h"

/**
 * UAshenUserWidget_DissonanceQuestBoardHUD
 * 
 * Interactive diegetic Quest Board interface displaying active psychological contracts and the 3-axis cognitive alignment triangle.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_DissonanceQuestBoardHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_DissonanceQuestBoardHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates the displayed quest contracts and dissonance state */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|CSE")
	void UpdateQuestBoardHUD(float DissonanceIndex, ECognitiveDissonanceTier Tier, const TArray<FDissonanceQuestContract>& Contracts);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|CSE")
	float DisplayedDissonance = 0.15f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|CSE")
	ECognitiveDissonanceTier DisplayedTier = ECognitiveDissonanceTier::HarmonicConsensus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|CSE")
	TArray<FDissonanceQuestContract> DisplayedContracts;
};
