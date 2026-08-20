// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenPurifierFlameBladeComponent.h"

UAshenPurifierFlameBladeComponent::UAshenPurifierFlameBladeComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenPurifierFlameBladeComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenPurifierFlameBladeComponent::SetBladeFlameState(EAshenPurifierBladeState NewState)
{
	BladeFlameState = NewState;
	bIsIgnited = (BladeFlameState != EAshenPurifierBladeState::Dormant);
	if (OnPurifierBladeStateChanged.IsBound())
	{
		OnPurifierBladeStateChanged.Broadcast(BladeFlameState);
	}
	UE_LOG(LogTemp, Warning, TEXT("UAshenPurifierFlameBladeComponent: Purifier blade ignited with state %d (Thermal Damage: %.1f)."),
		(int32)BladeFlameState, FlameThermalDamage);
}

void UAshenPurifierFlameBladeComponent::IgniteFlameBlade(float Duration)
{
	SetBladeFlameState(EAshenPurifierBladeState::HolyWhiteFlame);
}
