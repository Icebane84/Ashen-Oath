// AshenEmberEchoActor.cpp
// Copyright Ashen Oath. All rights reserved.

#include "AshenEmberEchoActor.h"
#include "AshenOath_CurrencyComponent.h"

AAshenEmberEchoActor::AAshenEmberEchoActor()
{
	PrimaryActorTick.bCanEverTick = false;
	InteractionText = TEXT("Retrieve Lost Embers");
	StoredEmbers = 0.0f;
}

void AAshenEmberEchoActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAshenEmberEchoActor::Interact_Implementation(APawn* Player)
{
	if (!Player) return;

	if (UAshenOath_CurrencyComponent* Currency = Player->FindComponentByClass<UAshenOath_CurrencyComponent>())
	{
		Currency->AddEmbers(StoredEmbers);
		UE_LOG(LogTemp, Log, TEXT("AAshenEmberEchoActor: Restored %.1f Embers to player."), StoredEmbers);
		Destroy();
	}
}

