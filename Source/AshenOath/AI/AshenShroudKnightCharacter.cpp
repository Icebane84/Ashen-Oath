// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenShroudKnightCharacter.h"

AAshenShroudKnightCharacter::AAshenShroudKnightCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenShroudKnightCharacter::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenShroudKnightCharacter: Shroud Knight elite spirit character initialized."));
}

void AAshenShroudKnightCharacter::SetShroudKnightState(EAshenShroudSpiritState NewState)
{
	CurrentState = NewState;
	if (OnShroudKnightStateChanged.IsBound())
	{
		OnShroudKnightStateChanged.Broadcast(CurrentState);
	}
	UE_LOG(LogTemp, Log, TEXT("AAshenShroudKnightCharacter: State transitioned to %d."), (int32)CurrentState);
}

bool AAshenShroudKnightCharacter::InitiateSpectralPhase()
{
	SetShroudKnightState(EAshenShroudSpiritState::SpectralPhasing);
	UE_LOG(LogTemp, Warning, TEXT("AAshenShroudKnightCharacter: SPECTRAL PHASING ACTIVE! Wall collision ignored."));
	return true;
}
