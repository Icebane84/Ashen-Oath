// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Memory/AshenPsychicEchoResolverComponent.h"

UAshenPsychicEchoResolverComponent::UAshenPsychicEchoResolverComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenPsychicEchoResolverComponent::BeginPlay() { Super::BeginPlay(); }

float UAshenPsychicEchoResolverComponent::ResolvePsychicEcho(FName EchoID, float ImprintWeight, bool bVictory)
{
	float HarmonyDelta = bVictory ? (ImprintWeight * 25.0f) : 5.0f;
	if (OnPsychicEchoResolved.IsBound())
	{
		OnPsychicEchoResolved.Broadcast(EchoID, HarmonyDelta);
	}
	UE_LOG(LogTemp, Warning, TEXT("UAshenPsychicEchoResolverComponent: Resolved Echo '%s' (Victory: %s, Harmony Reward: +%.1f)."),
		*EchoID.ToString(), bVictory ? TEXT("YES") : TEXT("NO"), HarmonyDelta);
	return HarmonyDelta;
}
