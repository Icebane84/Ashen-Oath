// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_AudioAccessibilitySubtitleHUD.h"

void UAshenUserWidget_AudioAccessibilitySubtitleHUD::DisplayOriginTaggedSubtitle(const FString& Line, EAudioConsciousnessChannel Channel)
{
	DisplayedSubtitle = Line;
	DisplayedChannel = Channel;

	FString ChannelTag = TEXT("[World]");
	if (Channel == EAudioConsciousnessChannel::PersonalAction)
	{
		ChannelTag = TEXT("[Controller]");
	}
	else if (Channel == EAudioConsciousnessChannel::InternalSomatic)
	{
		ChannelTag = TEXT("[Internal]");
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_AudioAccessibilitySubtitleHUD: %s %s"),
		*ChannelTag, *DisplayedSubtitle);
}
