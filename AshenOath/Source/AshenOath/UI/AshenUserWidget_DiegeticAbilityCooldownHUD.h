// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenUserWidget_DiegeticAbilityCooldownHUD.generated.h"

/**
 * UAshenUserWidget_DiegeticAbilityCooldownHUD
 * UMG Widget displaying diegetic ability cooldown ring with opacity pulse.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_DiegeticAbilityCooldownHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	float GetCooldownPulseOpacity() const { return CooldownPulseOpacity; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|UI")
	float CooldownPulseOpacity = 1.0f;
};
