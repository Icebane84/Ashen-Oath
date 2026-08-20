// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_IdentityResonanceInspector.generated.h"

/**
 * UAshenUserWidget_IdentityResonanceInspector
 * UMG backing widget rendering somatic identity fragment inspection and psychological resonance telemetry.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_IdentityResonanceInspector : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	int32 ActiveIdentityFragmentCount = 0;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void RefreshIdentityFragmentDisplay(int32 FragmentCount);
};
