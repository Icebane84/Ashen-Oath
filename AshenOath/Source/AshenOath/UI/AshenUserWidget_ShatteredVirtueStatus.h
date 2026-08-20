// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_ShatteredVirtueStatus.generated.h"

/**
 * UAshenUserWidget_ShatteredVirtueStatus
 *
 * UMG backing widget rendering active Virtue Fractures, Redemption Quest progress, and Inner Demon bargain prompts.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_ShatteredVirtueStatus : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateVirtueStatusDisplay(FName FractureID, bool bIsActive);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName DisplayedFractureID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	bool bFractureActive = false;
};
