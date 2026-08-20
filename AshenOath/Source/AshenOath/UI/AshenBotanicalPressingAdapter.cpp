// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenBotanicalPressingAdapter.h"

UAshenBotanicalPressingAdapter::UAshenBotanicalPressingAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentOpacity = 0.85f;
}

void UAshenBotanicalPressingAdapter::PressHerbToJournal(
	FName HerbId,
	UTexture2D* HerbTexture,
	float Opacity)
{
	ActiveHerbId = HerbId;
	CurrentOpacity = FMath::Clamp(Opacity, 0.0f, 1.0f);
}
