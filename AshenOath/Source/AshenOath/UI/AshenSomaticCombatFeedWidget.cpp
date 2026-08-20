// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 679: Ashen Somatic Combat Feed Widget

#include "AshenSomaticCombatFeedWidget.h"

void UAshenSomaticCombatFeedWidget::DisplaySomaticCombatFeed(FText FeedMessage, bool bIsWhiteFlameSurge)
{
	ActiveFeedMessageText = FeedMessage;
	bIsSurgeAlert = bIsWhiteFlameSurge;

	UE_LOG(LogTemp, Warning, TEXT("UAshenSomaticCombatFeedWidget: SOMATIC COMBAT FEED DISPLAYED -> Message: '%s' | Surge Alert: %s."),
		*FeedMessage.ToString(), bIsWhiteFlameSurge ? TEXT("WHITE FLAME SURGE") : TEXT("BLACK STAIN ATROPHY"));
}
