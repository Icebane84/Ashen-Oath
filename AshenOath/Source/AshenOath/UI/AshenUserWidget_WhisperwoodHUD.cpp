// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_WhisperwoodHUD.h"

UAshenUserWidget_WhisperwoodHUD::UAshenUserWidget_WhisperwoodHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedSanity = 1.0f;
	DisplayedSootOpacity = 0.0f;
	DisplayedLociCount = 0;
}

void UAshenUserWidget_WhisperwoodHUD::UpdatePsychologicalState(
	float Sanity,
	float SootOpacity,
	int32 LociCount)
{
	DisplayedSanity = Sanity;
	DisplayedSootOpacity = SootOpacity;
	DisplayedLociCount = LociCount;
}
