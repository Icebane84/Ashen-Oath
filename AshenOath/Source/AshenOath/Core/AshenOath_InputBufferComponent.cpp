// Copyright Phoenix Protocol. All rights reserved.

#include "AshenOath_InputBufferComponent.h"
#include "AshenGameSettings.h"
#include "Engine/World.h"

UAshenOath_InputBufferComponent::UAshenOath_InputBufferComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	BufferValidityDuration = 0.3f;
	CurrentBufferedInput = FAshenBufferedInput();
}

void UAshenOath_InputBufferComponent::BeginPlay()
{
	Super::BeginPlay();

	// Load configuration-driven settings
	if (const UAshenGameSettings* Settings = GetDefault<UAshenGameSettings>())
	{
		BufferValidityDuration = Settings->InputBufferValidityDuration;
	}
}

void UAshenOath_InputBufferComponent::BufferAction(FName ActionName)
{
	if (GetWorld())
	{
		CurrentBufferedInput = FAshenBufferedInput(ActionName, GetWorld()->GetTimeSeconds());
	}
}

bool UAshenOath_InputBufferComponent::HasBufferedAction(FName ActionName) const
{
	if (CurrentBufferedInput.ActionName == ActionName && GetWorld())
	{
		float ElapsedTime = GetWorld()->GetTimeSeconds() - CurrentBufferedInput.Timestamp;
		return ElapsedTime <= BufferValidityDuration;
	}
	return false;
}

bool UAshenOath_InputBufferComponent::ConsumeBufferedAction(FName ActionName)
{
	if (HasBufferedAction(ActionName))
	{
		ClearBuffer();
		return true;
	}
	return false;
}

void UAshenOath_InputBufferComponent::ClearBuffer()
{
	CurrentBufferedInput = FAshenBufferedInput(NAME_None, 0.0f);
}

void UAshenOath_InputBufferComponent::BufferInput(FName ActionName, bool bPressed)
{
	if (bPressed)
	{
		BufferAction(ActionName);
	}
}
