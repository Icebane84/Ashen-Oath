// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_CognitiveAIDebugOverlay.generated.h"

/**
 * UAshenUserWidget_CognitiveAIDebugOverlay
 *
 * UMG backing widget rendering AI threat tables, entropy decay multipliers, and active utility evaluation.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_CognitiveAIDebugOverlay : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateCognitiveDebugDisplay(FName PrimaryThreatName, float TopUtility, float EntropyDecay);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName DisplayedPrimaryThreat;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DisplayedUtility = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DisplayedEntropy = 1.0f;
};
