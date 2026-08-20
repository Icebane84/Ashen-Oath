// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 326: Ashen Soul Remnants Component

#include "AshenSoulRemnantsComponent.h"
#include "AshenOath_CurrencyComponent.h"

UAshenSoulRemnantsComponent::UAshenSoulRemnantsComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSoulRemnantsComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenSoulRemnantsComponent::ResolveRemnant(EAshenRemnantResolution Resolution, AActor* ResolvingActor)
{
	float Amount = 50.0f;

	if (Resolution == EAshenRemnantResolution::ShatterForEmbers && ResolvingActor)
	{
		UAshenOath_CurrencyComponent* Currency = ResolvingActor->FindComponentByClass<UAshenOath_CurrencyComponent>();
		if (Currency)
		{
			Currency->AddEmbers(Amount);
		}
	}

	OnSoulRemnantResolved.Broadcast(Resolution, Amount);

	UE_LOG(LogTemp, Warning, TEXT("UAshenSoulRemnantsComponent: SOUL REMNANT RESOLVED %d by '%s' (Amount: %.0f)."),
		(int32)Resolution, ResolvingActor ? *ResolvingActor->GetName() : TEXT("Unknown"), Amount);
}
