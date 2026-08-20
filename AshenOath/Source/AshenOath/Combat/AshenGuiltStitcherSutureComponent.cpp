// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenGuiltStitcherSutureComponent.h"

UAshenGuiltStitcherSutureComponent::UAshenGuiltStitcherSutureComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenGuiltStitcherSutureComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenGuiltStitcherSutureComponent::EstablishSympatheticSuture()
{
	bIsSutureActive = true;
	UE_LOG(LogTemp, Warning, TEXT("UAshenGuiltStitcherSutureComponent: Sympathetic Viscera suture established! 50 percent damage reflection active."));
}

bool UAshenGuiltStitcherSutureComponent::SeverSympatheticSuture()
{
	if (!bIsSutureActive) return false;
	bIsSutureActive = false;
	if (OnSympatheticSutureSevered.IsBound())
	{
		OnSympatheticSutureSevered.Broadcast();
	}
	UE_LOG(LogTemp, Warning, TEXT("UAshenGuiltStitcherSutureComponent: THE SEVERED TETHER! Sympathetic suture snipped and burned away."));
	return true;
}
