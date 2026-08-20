// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 337: Ashen Inner Demons System Component

#include "AshenInnerDemonsSystemComponent.h"

UAshenInnerDemonsSystemComponent::UAshenInnerDemonsSystemComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bBargainAccepted = false;
}

void UAshenInnerDemonsSystemComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenInnerDemonsSystemComponent::OfferDemonBargain(FName DemonID, float Multiplier)
{
	OnDemonBargainOffered.Broadcast(DemonID, Multiplier);

	UE_LOG(LogTemp, Warning, TEXT("UAshenInnerDemonsSystemComponent: INNER DEMON BARGAIN OFFERED — '%s' (%.2fx Power Boon)."),
		*DemonID.ToString(), Multiplier);
}

bool UAshenInnerDemonsSystemComponent::AcceptDemonBargain(FName DemonID)
{
	bBargainAccepted = true;

	UE_LOG(LogTemp, Warning, TEXT("UAshenInnerDemonsSystemComponent: BARGAIN ACCEPTED — '%s' (Accruing Taint & Virtue Fracture Risk)."),
		*DemonID.ToString());

	return true;
}
