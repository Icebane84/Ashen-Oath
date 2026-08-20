// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenRelationalContextBarkDispatcher.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundBase.h"

UAshenRelationalContextBarkDispatcher::UAshenRelationalContextBarkDispatcher()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenRelationalContextBarkDispatcher::DispatchBark(
	const FCompanionIntentEvaluationResult& Evaluation,
	USoundBase* BarkSound)
{
	LastDispatchedDialogue = Evaluation.ContextualBarkDialogue;

	if (BarkSound && BarkAudioComponent)
	{
		BarkAudioComponent->SetSound(BarkSound);
		BarkAudioComponent->Play();
	}
}
