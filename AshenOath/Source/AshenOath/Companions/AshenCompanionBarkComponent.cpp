// AshenCompanionBarkComponent.cpp
// Copyright Ashen Oath. All rights reserved.

#include "AshenCompanionBarkComponent.h"
#include "AshenSoulConstellationSubsystem.h"
#include "AshenOath_GameEventSubsystem.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "GameFramework/Actor.h"

UAshenCompanionBarkComponent::UAshenCompanionBarkComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CompanionType = ECompanionType::Garrett;
	BarkCooldownSeconds = 12.0f;
	bCanSpeak = true;
	LastDebtStage = EIntegrationDebtStage::Dormant;
}

void UAshenCompanionBarkComponent::BeginPlay()
{
	Super::BeginPlay();

	if (UWorld* World = GetWorld())
	{
		if (UGameInstance* GI = World->GetGameInstance())
		{
			if (UAshenSoulConstellationSubsystem* Kernel = GI->GetSubsystem<UAshenSoulConstellationSubsystem>())
			{
				Kernel->OnStateVectorInvalidated.AddDynamic(this, &UAshenCompanionBarkComponent::HandleStateVectorInvalidated);
			}

			if (UAshenOath_GameEventSubsystem* EventBus = GI->GetSubsystem<UAshenOath_GameEventSubsystem>())
			{
				EventBus->OnCombatEventFired.AddDynamic(this, &UAshenCompanionBarkComponent::HandleCombatEventFired);
			}
		}
	}
}

void UAshenCompanionBarkComponent::HandleStateVectorInvalidated(const FSoulStateVector& NewState)
{
	const EIntegrationDebtStage CurrentDebtStage = NewState.GetDebtStage();

	if (CurrentDebtStage != LastDebtStage)
	{
		LastDebtStage = CurrentDebtStage;

		if (CurrentDebtStage == EIntegrationDebtStage::MemoryBleed)
		{
			if (CompanionType == ECompanionType::Garrett)
			{
				SpeakBarkLine(TEXT("Garrett: 'Kaelen... your mind is slipping. Stay focused on the objective.'"));
			}
			else
			{
				SpeakBarkLine(TEXT("Serafina: 'Kaelen, I can hear the echoes bleeding into your thoughts. Hold on.'"));
			}
		}
		else if (CurrentDebtStage == EIntegrationDebtStage::RuntimeNoise)
		{
			if (CompanionType == ECompanionType::Garrett)
			{
				SpeakBarkLine(TEXT("Garrett: 'Kaelen, stop! The corruption is overwhelming your mind! Find a sanctuary!'"));
			}
			else
			{
				SpeakBarkLine(TEXT("Serafina: 'Kaelen, please! We're losing you! Reach a Heartstone before it collapses!'"));
			}
		}
	}
}

void UAshenCompanionBarkComponent::HandleCombatEventFired(FString EventType, AActor* Instigator, AActor* Target, float Magnitude)
{
	if (EventType == TEXT("PlayerLowHealth") || Magnitude < 0.25f)
	{
		if (CompanionType == ECompanionType::Garrett)
		{
			SpeakBarkLine(TEXT("Garrett: 'Hold the line, Kaelen! Stand your ground!'"));
		}
		else
		{
			SpeakBarkLine(TEXT("Serafina: 'Kaelen! Step back! Don't let them fall you!'"));
		}
	}
}


void UAshenCompanionBarkComponent::SpeakBarkLine(const FString& Line)
{
	if (!bCanSpeak) return;

	bCanSpeak = false;
	UE_LOG(LogTemp, Warning, TEXT("[VOICE BARK] %s"), *Line);

	// Broadcast audio request via GameEventSubsystem
	if (UWorld* World = GetWorld())
	{
		if (UGameInstance* GI = World->GetGameInstance())
		{
			if (UAshenOath_GameEventSubsystem* EventBus = GI->GetSubsystem<UAshenOath_GameEventSubsystem>())
			{
				const FVector SpeakerLoc = GetOwner() ? GetOwner()->GetActorLocation() : FVector::ZeroVector;
				EventBus->BroadcastSpatialSoundRequested(nullptr, SpeakerLoc, 1.0f, 1.0f);
			}
		}

		World->GetTimerManager().SetTimer(BarkCooldownTimerHandle, [this]()
		{
			bCanSpeak = true;
		}, BarkCooldownSeconds, false);
	}
}
