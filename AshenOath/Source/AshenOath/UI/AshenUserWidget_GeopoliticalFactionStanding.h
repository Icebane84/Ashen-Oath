// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_GeopoliticalFactionStanding.generated.h"

/**
 * UAshenUserWidget_GeopoliticalFactionStanding
 *
 * UMG backing widget rendering faction standing meters and presented Solidified Memory reputation gains.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_GeopoliticalFactionStanding : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateFactionStandingDisplay(FName FactionID, float FactionStanding);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName DisplayedFactionID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DisplayedStanding = 0.0f;
};
