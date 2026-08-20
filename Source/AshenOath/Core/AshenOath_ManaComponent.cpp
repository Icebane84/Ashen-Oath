// Copyright Phoenix Protocol. All rights reserved.

#include "AshenOath_ManaComponent.h"
#include "AshenOath_GameEventSubsystem.h"
#include "AshenOath_DirectorSubsystem.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

UAshenOath_ManaComponent::UAshenOath_ManaComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	MaxMana = 100.0f;
	CurrentMana = 0.0f;
}

void UAshenOath_ManaComponent::BeginPlay()
{
	Super::BeginPlay();

	UpdateManaValue(MaxMana);
}

bool UAshenOath_ManaComponent::ConsumeMana(float Amount)
{
	if (CurrentMana < Amount)
	{
		return false;
	}

	UpdateManaValue(CurrentMana - Amount);
	return true;
}

void UAshenOath_ManaComponent::SetCurrentMana(float NewMana)
{
	UpdateManaValue(NewMana);
}

void UAshenOath_ManaComponent::SetMaxMana(float NewMaxMana)
{
	MaxMana = FMath::Max(1.0f, NewMaxMana);
	UpdateManaValue(CurrentMana);
}

void UAshenOath_ManaComponent::UpdateManaValue(float TargetValue)
{
	float Clamped = FMath::Clamp(TargetValue, 0.0f, MaxMana);
	if (Clamped != CurrentMana)
	{
		CurrentMana = Clamped;
		OnManaChanged.Broadcast(CurrentMana, MaxMana);

		if (GetWorld() && GetWorld()->GetGameInstance())
		{
			UAshenOath_GameEventSubsystem* EventBus = GetWorld()->GetGameInstance()->GetSubsystem<UAshenOath_GameEventSubsystem>();
			UAshenOath_DirectorSubsystem* Director = GetWorld()->GetGameInstance()->GetSubsystem<UAshenOath_DirectorSubsystem>();
			if (EventBus && Director)
			{
				if (Director->GetPlayerPawn() == GetOwner())
				{
					EventBus->BroadcastPlayerManaChanged(CurrentMana, MaxMana);
				}
			}
		}
	}
}
