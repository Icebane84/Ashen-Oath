// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_LivingOathStatus.generated.h"

/**
 * UAshenUserWidget_LivingOathStatus
 *
 * UMG backing widget rendering active party Living Oaths, pact multipliers, and break risk warnings.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_LivingOathStatus : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateLivingOathDisplay(FName OathPactID, bool bInOathBound);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName DisplayedOathPactID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	bool bOathBound = false;
};
