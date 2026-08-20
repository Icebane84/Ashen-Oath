// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenSerafinaBurnoutComponent.h"

UAshenSerafinaBurnoutComponent::UAshenSerafinaBurnoutComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenSerafinaBurnoutComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenSerafinaBurnoutComponent::AddBurnout(float Amount)
{
	const float PrevBurnout = CurrentBurnout;
	CurrentBurnout = FMath::Clamp(CurrentBurnout + Amount, 0.0f, 100.0f);
	bIsBurnedOut = (CurrentBurnout >= FeverThreshold);

	if (OnBurnoutLevelChanged.IsBound())
	{
		OnBurnoutLevelChanged.Broadcast(CurrentBurnout);
	}

	if (PrevBurnout < FeverThreshold && CurrentBurnout >= FeverThreshold)
	{
		if (OnBurnoutFeverThresholdCrossed.IsBound())
		{
			OnBurnoutFeverThresholdCrossed.Broadcast();
		}
		UE_LOG(LogTemp, Warning, TEXT("UAshenSerafinaBurnoutComponent: FEVER THRESHOLD CROSSED! Burnout: %.1f"), CurrentBurnout);
	}
}

void UAshenSerafinaBurnoutComponent::AccumulateEmpathicBurnout(float Amount)
{
	AddBurnout(Amount);
}

void UAshenSerafinaBurnoutComponent::DissipateBurnout(float DeltaTime, float DissipationRate)
{
	CurrentBurnout = FMath::Clamp(CurrentBurnout - (DissipationRate * DeltaTime), 0.0f, 100.0f);
	bIsBurnedOut = (CurrentBurnout >= FeverThreshold);
	if (OnBurnoutLevelChanged.IsBound())
	{
		OnBurnoutLevelChanged.Broadcast(CurrentBurnout);
	}
}
