// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenWeaveTraumaBridgeGASAbility.h"
#include "Combat/AshenOath_SanityComponent.h"
#include "Companions/AshenCompanionFatigueSubsystem.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

UAshenWeaveTraumaBridgeGASAbility::UAshenWeaveTraumaBridgeGASAbility()
{
	MaxBridgeSpanUnits = 1200.0f;
	SanityHealAmount = 15.0f;
	SerafinaFatigueCost = 0.15f;
}

bool UAshenWeaveTraumaBridgeGASAbility::ManifestTraumaBridge(
	AActor* InstigatorActor,
	FVector StartLocation,
	FVector EndLocation)
{
	const float Span = FVector::Dist(StartLocation, EndLocation);
	if (Span > MaxBridgeSpanUnits)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenWeaveTraumaBridgeGASAbility: Bridge span %.1fuu exceeds max %.1fuu!"), Span, MaxBridgeSpanUnits);
		return false;
	}

	if (!InstigatorActor)
	{
		return false;
	}

	UWorld* World = InstigatorActor->GetWorld();
	if (!World)
	{
		return false;
	}

	// 1. Heal Kaelen's Sanity on successful chasm stitching
	if (UAshenOath_SanityComponent* SanityComp = InstigatorActor->FindComponentByClass<UAshenOath_SanityComponent>())
	{
		SanityComp->HealSanity(SanityHealAmount);
	}

	// 2. Add Serafina Fatigue
	if (UGameInstance* GI = World->GetGameInstance())
	{
		if (UAshenCompanionFatigueSubsystem* FatigueSubsystem = GI->GetSubsystem<UAshenCompanionFatigueSubsystem>())
		{
			FatigueSubsystem->AccumulateFatigue(TEXT("Serafina"), SerafinaFatigueCost);
		}
	}

	if (OnTraumaBridgeManifested.IsBound())
	{
		OnTraumaBridgeManifested.Broadcast(Span, SanityHealAmount, SerafinaFatigueCost);
	}

	UE_LOG(LogTemp, Warning, TEXT("UAshenWeaveTraumaBridgeGASAbility: TRAUMA LIGHT BRIDGE MANIFESTED! (Span: %.1fuu | +%.1f Sanity | +%.2f Serafina Fatigue)!"),
		Span, SanityHealAmount, SerafinaFatigueCost);

	return true;
}
