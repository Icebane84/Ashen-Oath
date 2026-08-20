// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_SymbioticResonanceHUD.generated.h"

/**
 * UAshenUserWidget_SymbioticResonanceHUD
 * Somatic UI controller that fades out HUD elements during Symbiotic Resonance to create a pure UI-less immersion loop.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_SymbioticResonanceHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float HUDOpacity = 1.0f; // 1.0 (Normal) down to 0.0 (Full UI-less Resonance)

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void SetHUDResonanceFade(bool bInResonance);
};
