// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenEldrinDialogueBridge.h"

UAshenEldrinDialogueBridge::UAshenEldrinDialogueBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenEldrinDialogueBridge::FormatEldrinWhisper(float Corruption01, EPommelGazeTarget GazeTarget) const
{
	if (Corruption01 >= 0.70f)
	{
		switch (GazeTarget)
		{
		case EPommelGazeTarget::GarrettSentinel:
			return FText::FromString(TEXT("[Nyx]: 'He is calculating your expiration, Kaelen. A sentinel only watches what he intends to put down.'"));
		case EPommelGazeTarget::SerafinaWarden:
			return FText::FromString(TEXT("[Eldrin]: 'Every touch of her golden flame drinks your poison. You are killing her, boy.'"));
		default:
			return FText::FromString(TEXT("[Nyx]: 'Let go of the White Flame. Embrace the nightsteel—it is feather-light in the dark.'"));
		}
	}
	else if (Corruption01 >= 0.30f)
	{
		return FText::FromString(TEXT("[Eldrin]: 'I was the Order's brightest star... and this blade was my glorious cage. Listen to the hum, Kaelen.'"));
	}

	return FText::FromString(TEXT("[Oathbringer]: *A distant, cold hum vibrates through the grip.*"));
}
