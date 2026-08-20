// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenSomaticCombatFeedWidget.generated.h"

/**
 * UAshenSomaticCombatFeedWidget
 *
 * UMG widget presenting diegetic combat feedback (White Flame Surge alerts vs Black Stain notifications).
 */
UCLASS()
class ASHENOATH_API UAshenSomaticCombatFeedWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void DisplaySomaticCombatFeed(FText FeedMessage, bool bIsWhiteFlameSurge);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FText ActiveFeedMessageText;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	bool bIsSurgeAlert = false;
};
