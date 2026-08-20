// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Narrative/AshenLivingCodexTypes.h"
#include "AshenUserWidget_LivingCodexHUD.generated.h"

/**
 * UAshenUserWidget_LivingCodexHUD
 * Somatic UI journal widget displaying categorized faction lore, unsealed records, and permanent stat rewards.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_LivingCodexHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	ECodexFaction ActiveFactionTab = ECodexFaction::Oathsworn;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	int32 DisplayedUnlockedCount = 0;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void SwitchFactionTab(ECodexFaction NewFaction, int32 UnlockedCount);
};
