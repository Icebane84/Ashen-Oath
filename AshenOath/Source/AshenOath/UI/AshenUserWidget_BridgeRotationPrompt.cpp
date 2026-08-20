// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 269: Ashen Bridge Rotation Prompt UMG Widget

#include "AshenUserWidget_BridgeRotationPrompt.h"

void UAshenUserWidget_BridgeRotationPrompt::ShowBridgePrompt(float CurrentAngle, bool bIsAligned)
{
	DisplayedAngle = CurrentAngle;
	bBridgeAligned = bIsAligned;
	bPromptVisible = true;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_BridgeRotationPrompt: Bridge prompt displayed — Angle: %.0f°, Aligned: %s."),
		CurrentAngle, bIsAligned ? TEXT("TRUE") : TEXT("FALSE"));
}

void UAshenUserWidget_BridgeRotationPrompt::HideBridgePrompt()
{
	bPromptVisible = false;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_BridgeRotationPrompt: Bridge prompt hidden."));
}
