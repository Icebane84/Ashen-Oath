// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_CognitiveAIDebugHUD.generated.h"

/**
 * UAshenUserWidget_CognitiveAIDebugHUD
 * UMG backing widget visualizing AI Markovian utility values, LAW-041 decay factors, and input reading probabilities.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_CognitiveAIDebugHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float DisplayedUtilityValue = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void RefreshCognitiveAIDebugTelemetry(float Utility, float ReactionProb);
};
