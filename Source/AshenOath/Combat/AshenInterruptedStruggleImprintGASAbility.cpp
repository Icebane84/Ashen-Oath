// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenInterruptedStruggleImprintGASAbility.h"
#include "Engine/World.h"

UAshenInterruptedStruggleImprintGASAbility::UAshenInterruptedStruggleImprintGASAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
	BaseInterruptedTraumaMagnitude = 0.45f;
}

void UAshenInterruptedStruggleImprintGASAbility::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}

FMemoryImprintPayload UAshenInterruptedStruggleImprintGASAbility::CreateInterruptedStruggleImprint(
	const FWillTrialSessionSnapshot& SessionSnapshot,
	EWillContext Context,
	float CompletionRatio,
	FName MemorySiteId,
	FName EncounterId)
{
	FMemoryImprintPayload Imprint;
	Imprint.ImprintId = FGuid::NewGuid();
	Imprint.OriginTransactionId = SessionSnapshot.InitialTransactionId;
	Imprint.MemorySiteId = MemorySiteId;
	Imprint.EncounterId = EncounterId;
	Imprint.ImprintType = EMemoryImprintType::WillTrialFailure;
	
	// Emotional magnitude is scaled by how close Kaelen came to completing the trial before choking
	Imprint.EmotionalMagnitude = FMath::Clamp(BaseInterruptedTraumaMagnitude * (1.0f + (0.50f * CompletionRatio)), 0.0f, 1.0f);
	Imprint.ThreatMagnitude = 0.30f;
	Imprint.RelationalSignificance = 0.60f;
	Imprint.IdentitySignificance = 0.50f;
	
	Imprint.ContextTags.AddTag(FGameplayTag::RequestGameplayTag(FName(TEXT("Memory.InterruptedStruggle")), false));
	Imprint.ContextTags.AddTag(FGameplayTag::RequestGameplayTag(FName(TEXT("Memory.ChokedDialogue")), false));
	
	Imprint.GameTimeSeconds = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0;
	Imprint.bHasBeenCompiledAtHeartstone = false;
	Imprint.InterpretedLens = EOntologicalLens::Uncompiled;

	return Imprint;
}
