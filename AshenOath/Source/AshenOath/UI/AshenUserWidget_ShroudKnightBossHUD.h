// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Combat/AshenShroudKnightTypes.h"
#include "AshenUserWidget_ShroudKnightBossHUD.generated.h"

/**
 * UAshenUserWidget_ShroudKnightBossHUD
 * 
 * UMG widget displaying the Shroud-Knight's 3-segment health bar, Creeping Paranoia infection gauge, and Trinity Strike combo prompts.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_ShroudKnightBossHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_ShroudKnightBossHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates boss HUD state */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Boss")
	void UpdateBossHUD(const FShroudKnightBossVector& BossVector);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Boss")
	FShroudKnightBossVector DisplayedBossVector;
};
