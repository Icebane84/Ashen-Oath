// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Engine/PostProcessVolume.h"
#include "AshenSlateGreySilhouettePostProcessVolume.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSlateGreyPostProcessTriggeredSignature, float, DesaturationAmount, bool, bSilhouettesActive);

/**
 * AAshenSlateGreySilhouettePostProcessVolume
 *
 * World PostProcess Volume applying high-contrast silhouette rendering during crisis dilation (PRS-001-UI-006).
 */
UCLASS()
class ASHENOATH_API AAshenSlateGreySilhouettePostProcessVolume : public APostProcessVolume
{
	GENERATED_BODY()

public:
	AAshenSlateGreySilhouettePostProcessVolume();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|SlateGreyPostProcess")
	void TriggerSlateGreySilhouettes(bool bEnableSilhouettes);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SlateGreyPostProcess|Events")
	FOnSlateGreyPostProcessTriggeredSignature OnPostProcessTriggered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|SlateGreyPostProcess")
	bool bIsSilhouettesActive = false;
};
