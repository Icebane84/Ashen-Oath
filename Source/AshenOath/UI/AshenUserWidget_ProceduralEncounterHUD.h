// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_ProceduralEncounterHUD.generated.h"

/**
 * UAshenUserWidget_ProceduralEncounterHUD
 *
 * UMG backing widget rendering dynamic threat level and director state.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_ProceduralEncounterHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateEncounterHUDDisplay(int32 ThreatTier, int32 EnemyCount);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	int32 DisplayedThreatTier = 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	int32 DisplayedEnemyCount = 3;
};
