// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 816: Ashen Devil's Bargain Diegetic UI Prompt Subsystem

#include "AshenDevilsBargainDiegeticUIPromptSubsystem.h"

void UAshenDevilsBargainDiegeticUIPromptSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	bIsPromptActive = false;
	UE_LOG(LogTemp, Log, TEXT("UAshenDevilsBargainDiegeticUIPromptSubsystem: Initialized — Diegetic UI Prompt Subsystem ONLINE."));
}

void UAshenDevilsBargainDiegeticUIPromptSubsystem::TriggerDiegeticCrisisPrompt(bool bActivate)
{
	bIsPromptActive = bActivate;
	const float Dilation = bIsPromptActive ? 0.10f : 1.0f; // 10% speed during prompt

	OnDiegeticPromptTriggered.Broadcast(bIsPromptActive, Dilation);

	UE_LOG(LogTemp, Warning, TEXT("UAshenDevilsBargainDiegeticUIPromptSubsystem: DIEGETIC CRISIS PROMPT TRIGGERED -> Active: %s | Time Dilation: %.2fx | HUD Clean: TRUE."),
		bIsPromptActive ? TEXT("TRUE") : TEXT("FALSE"), Dilation);
}
