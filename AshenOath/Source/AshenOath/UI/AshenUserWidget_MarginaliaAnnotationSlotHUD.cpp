// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_MarginaliaAnnotationSlotHUD.h"

UAshenUserWidget_MarginaliaAnnotationSlotHUD::UAshenUserWidget_MarginaliaAnnotationSlotHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	CurrentSlot = EMarginAnchorSlot::RightMargin_Lower;
}

void UAshenUserWidget_MarginaliaAnnotationSlotHUD::ConfigureSlot(const FMarginaliaEntry& Entry)
{
	CurrentEntry = Entry;
	CurrentSlot = Entry.AnchorSlot;
}
