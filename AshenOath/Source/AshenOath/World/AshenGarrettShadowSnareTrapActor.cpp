// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 703: Ashen Garrett Shadow Snare Trap Actor

#include "AshenGarrettShadowSnareTrapActor.h"

AAshenGarrettShadowSnareTrapActor::AAshenGarrettShadowSnareTrapActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsArmed = true;
}

void AAshenGarrettShadowSnareTrapActor::TriggerShadowSnare(AActor* TargetEnemy)
{
	if (!bIsArmed || !TargetEnemy) return;

	bIsArmed = false;
	const float RootDuration = 4.5f; // 4.5 sec root duration
	OnShadowSnareTriggered.Broadcast(TargetEnemy, RootDuration);

	UE_LOG(LogTemp, Warning, TEXT("AAshenGarrettShadowSnareTrapActor: SHADOW SNARE TRIGGERED -> Enemy '%s' rooted for %.1fs."),
		*TargetEnemy->GetName(), RootDuration);
}
