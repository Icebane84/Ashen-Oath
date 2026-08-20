// Copyright Phoenix Protocol. All rights reserved.

#include "AshenOath_StaminaComponent.h"
#include "Engine/World.h"

UAshenOath_StaminaComponent::UAshenOath_StaminaComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;

	MaxStamina = 100.0f;
	RegenRate = 15.0f;
	RegenPauseTime = 1.0f;
	CurrentStamina = 0.0f;
	RegenTimer = 0.0f;
}

void UAshenOath_StaminaComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentStamina = MaxStamina;
	OnStaminaChanged.Broadcast(CurrentStamina, MaxStamina);
}

void UAshenOath_StaminaComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (RegenTimer > 0.0f)
	{
		RegenTimer -= DeltaTime;
		return;
	}

	if (CurrentStamina < MaxStamina)
	{
		CurrentStamina = FMath::Clamp(CurrentStamina + RegenRate * DeltaTime, 0.0f, MaxStamina);
		OnStaminaChanged.Broadcast(CurrentStamina, MaxStamina);
	}
}

bool UAshenOath_StaminaComponent::ConsumeStamina(float Amount)
{
	if (CurrentStamina < Amount)
	{
		return false;
	}

	CurrentStamina -= Amount;
	RegenTimer = RegenPauseTime;

	OnStaminaChanged.Broadcast(CurrentStamina, MaxStamina);

	if (CurrentStamina <= 0.0f)
	{
		OnStaminaDepleted.Broadcast();
	}

	return true;
}

void UAshenOath_StaminaComponent::SetCurrentStamina(float NewStamina)
{
	CurrentStamina = FMath::Clamp(NewStamina, 0.0f, MaxStamina);
	OnStaminaChanged.Broadcast(CurrentStamina, MaxStamina);
}

void UAshenOath_StaminaComponent::SetMaxStamina(float NewMaxStamina)
{
	MaxStamina = FMath::Max(1.0f, NewMaxStamina);
	OnStaminaChanged.Broadcast(CurrentStamina, MaxStamina);
}
