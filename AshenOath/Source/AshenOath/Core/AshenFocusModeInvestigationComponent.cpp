// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Core/AshenFocusModeInvestigationComponent.h"
#include "Combat/AshenCombatCharacter.h"
#include "Combat/AshenOath_SanityComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

UAshenFocusModeInvestigationComponent::UAshenFocusModeInvestigationComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
	bFocusModeActive = false;
	TimeDilationMultiplier = 0.35f;
	SanityDrainRate = 4.0f;
	InvestigationRange = 1200.0f;
}

void UAshenFocusModeInvestigationComponent::TickComponent(
	float DeltaTime,
	ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!bFocusModeActive)
	{
		return;
	}

	AActor* Owner = GetOwner();
	if (!Owner)
	{
		return;
	}

	// Drain sanity while active
	if (UAshenOath_SanityComponent* SanityComp = Owner->FindComponentByClass<UAshenOath_SanityComponent>())
	{
		SanityComp->SufferMentalDamage(SanityDrainRate * DeltaTime);

		if (SanityComp->GetCurrentSanity() <= 0.0f)
		{
			// Auto-disable when sanity is completely exhausted
			ToggleFocusMode(false);
			UE_LOG(LogTemp, Warning, TEXT("UAshenFocusModeInvestigationComponent: Focus mode forcefully collapsed due to sanity depletion."));
		}
	}
}

void UAshenFocusModeInvestigationComponent::ToggleFocusMode(bool bEnable)
{
	if (bFocusModeActive == bEnable)
	{
		return;
	}

	bFocusModeActive = bEnable;
	UWorld* World = GetWorld();

	if (World)
	{
		UGameplayStatics::SetGlobalTimeDilation(World, bEnable ? TimeDilationMultiplier : 1.0f);
	}

	AActor* Owner = GetOwner();
	if (AAshenCombatCharacter* CombatChar = Cast<AAshenCombatCharacter>(Owner))
	{
		CombatChar->HandleRunicSeamColorUpdated(
			bEnable ? FLinearColor(0.2f, 0.7f, 1.0f, 1.0f) : FLinearColor::White,
			bEnable ? 2.5f : 1.0f);
	}

	const float Range = bEnable ? InvestigationRange : 0.0f;
	OnFocusModeStateChanged.Broadcast(bEnable, Range);

	UE_LOG(LogTemp, Warning, TEXT("UAshenFocusModeInvestigationComponent: FOCUS MODE TOGGLED -> Active: %s (Dilation: %.2fx, Range: %.0fu)."),
		bEnable ? TEXT("TRUE") : TEXT("FALSE"), bEnable ? TimeDilationMultiplier : 1.0f, Range);
}
