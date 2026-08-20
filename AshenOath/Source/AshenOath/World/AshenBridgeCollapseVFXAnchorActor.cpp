// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 767: Ashen Bridge Collapse VFX Anchor Actor

#include "AshenBridgeCollapseVFXAnchorActor.h"

AAshenBridgeCollapseVFXAnchorActor::AAshenBridgeCollapseVFXAnchorActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsDebrisActive = false;
}

void AAshenBridgeCollapseVFXAnchorActor::TriggerBridgeCollapseVFX(float Scale)
{
	bIsDebrisActive = true;
	OnCollapseVFXTriggered.Broadcast(GetActorLocation(), Scale);

	UE_LOG(LogTemp, Warning, TEXT("AAshenBridgeCollapseVFXAnchorActor: BRIDGE COLLAPSE VFX TRIGGERED -> Center: (%s) | Scale: %.2fx."),
		*GetActorLocation().ToString(), Scale);
}
