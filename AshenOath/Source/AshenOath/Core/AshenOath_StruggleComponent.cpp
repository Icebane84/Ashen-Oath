// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenOath_StruggleComponent.h"
#include "AshenCharacterInterface.h"
#include "AshenOath_SanityComponent.h"
#include "AshenOath_PoiseComponent.h"
#include "AshenOath_GameEventSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

UAshenOath_StruggleComponent::UAshenOath_StruggleComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	CurrentPhase = EAshenStrugglePhase::None;
	StruggleProgress = 0.5f;
	StruggleDuration = 6.0f;
	TimerTracker = 0.0f;
}

void UAshenOath_StruggleComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenOath_StruggleComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (CurrentPhase == EAshenStrugglePhase::None)
	{
		return;
	}

	TimerTracker += DeltaTime;

	// Passive decay over time pushing progress down towards 0 (failure)
	StruggleProgress = FMath::Clamp(StruggleProgress - (0.08f * DeltaTime), 0.0f, 1.0f);
	OnStruggleStateChanged.Broadcast(CurrentPhase, StruggleProgress);

	if (StruggleProgress >= 1.0f)
	{
		ResolveStruggle(true); // Player won!
	}
	else if (StruggleProgress <= 0.0f || TimerTracker >= StruggleDuration)
	{
		ResolveStruggle(false); // Player lost!
	}
}

void UAshenOath_StruggleComponent::StartStrugglePhase(EAshenStrugglePhase NewPhase)
{
	if (NewPhase == EAshenStrugglePhase::None)
	{
		return;
	}

	CurrentPhase = NewPhase;
	StruggleProgress = 0.5f;
	TimerTracker = 0.0f;

	UE_LOG(LogTemp, Log, TEXT("StartStrugglePhase: Initiated struggle phase %d"), static_cast<int32>(CurrentPhase));
	OnStruggleStateChanged.Broadcast(CurrentPhase, StruggleProgress);

	AActor* Owner = GetOwner();
	if (GetWorld() && GetWorld()->GetGameInstance() && Owner)
	{
		if (UAshenOath_GameEventSubsystem* EventBus = GetWorld()->GetGameInstance()->GetSubsystem<UAshenOath_GameEventSubsystem>())
		{
			EventBus->BroadcastSpatialSoundRequested(nullptr, Owner->GetActorLocation(), 0.9f, 0.9f);
		}
	}

}

void UAshenOath_StruggleComponent::SubmitStruggleInput(float ResistanceAmount)
{
	if (CurrentPhase == EAshenStrugglePhase::None)
	{
		return;
	}

	StruggleProgress = FMath::Clamp(StruggleProgress + ResistanceAmount, 0.0f, 1.0f);
	UE_LOG(LogTemp, Verbose, TEXT("SubmitStruggleInput: +%.2f (Progress: %.2f)"), ResistanceAmount, StruggleProgress);
	OnStruggleStateChanged.Broadcast(CurrentPhase, StruggleProgress);
}

void UAshenOath_StruggleComponent::ResolveStruggle(bool bPlayerWon)
{
	if (CurrentPhase == EAshenStrugglePhase::None)
	{
		return;
	}

	AActor* Owner = GetOwner();
	if (bPlayerWon)
	{
		UE_LOG(LogTemp, Log, TEXT("ResolveStruggle: VICTORY! Kaelen broke the shadow grip!"));
		if (Owner && Owner->Implements<UAshenCharacterInterface>())
		{
			if (UAshenOath_PoiseComponent* Poise = IAshenCharacterInterface::Execute_GetPoiseComponent(Owner))
			{
				Poise->ResetPoise(); // Full poise recovery on struggle victory
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ResolveStruggle: FAILURE! Kaelen overwhelmed by shadow whispers."));
		if (Owner && Owner->Implements<UAshenCharacterInterface>())
		{
			if (UAshenOath_SanityComponent* Sanity = IAshenCharacterInterface::Execute_GetSanityComponent(Owner))
			{
				Sanity->SufferMentalDamage(25.0f);
			}
		}
	}

	CurrentPhase = EAshenStrugglePhase::None;
	StruggleProgress = 0.0f;
	TimerTracker = 0.0f;

	OnStruggleResolved.Broadcast(bPlayerWon);
}
