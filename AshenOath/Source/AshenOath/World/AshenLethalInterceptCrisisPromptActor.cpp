// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 672: Ashen Lethal Intercept Crisis Prompt Actor

#include "AshenLethalInterceptCrisisPromptActor.h"

AAshenLethalInterceptCrisisPromptActor::AAshenLethalInterceptCrisisPromptActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsPromptActive = false;
	ActiveCrisisReason = FName(TEXT("Crisis.KaelenZeroHP"));
}

void AAshenLethalInterceptCrisisPromptActor::TriggerCrisisPrompt(FName Reason, float TimeLimit)
{
	ActiveCrisisReason = Reason;
	bIsPromptActive = true;
	OnCrisisTriggered.Broadcast(ActiveCrisisReason, TimeLimit);

	UE_LOG(LogTemp, Warning, TEXT("AAshenLethalInterceptCrisisPromptActor: CRISIS PROMPT TRIGGERED -> Reason: '%s' | Time Limit: %.1fs [DEVIL'S BARGAIN PROMPT ACTIVE]."),
		*ActiveCrisisReason.ToString(), TimeLimit);
}
