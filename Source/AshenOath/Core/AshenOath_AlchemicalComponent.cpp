// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenOath_AlchemicalComponent.h"
#include "AshenCharacterInterface.h"
#include "AshenOath_PoiseComponent.h"
#include "AshenOath_SanityComponent.h"
#include "AshenOath_GameEventSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

UAshenOath_AlchemicalComponent::UAshenOath_AlchemicalComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	BurningSteelOilCharges = 3;
	GloomwoodDampenerCharges = 2;
	SulfurousSmokeBalmCharges = 4;
	GhostbloomTripwireCharges = 3;
}

void UAshenOath_AlchemicalComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenOath_AlchemicalComponent::DeployBurningSteelOil(AActor* TargetActor)
{
	if (BurningSteelOilCharges <= 0 || !TargetActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("DeployBurningSteelOil failed: No charges or null target."));
		return false;
	}

	BurningSteelOilCharges--;
	UE_LOG(LogTemp, Log, TEXT("DeployBurningSteelOil: Burning Steel Oil applied! +35 Posture Damage, -15%% Armor. Charges left: %d"), BurningSteelOilCharges);

	if (TargetActor->Implements<UAshenCharacterInterface>())
	{
		if (UAshenOath_PoiseComponent* Poise = IAshenCharacterInterface::Execute_GetPoiseComponent(TargetActor))
		{
			Poise->ApplyPoiseDamage(35.0f);
		}
	}


	OnMatrixDeployed.Broadcast(TEXT("BurningSteelOil"), TargetActor->GetActorLocation());
	return true;
}

bool UAshenOath_AlchemicalComponent::AdministerGloomwoodDampener(AActor* KaelenActor)
{
	if (GloomwoodDampenerCharges <= 0 || !KaelenActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("AdministerGloomwoodDampener failed: No charges or null target."));
		return false;
	}

	GloomwoodDampenerCharges--;
	UE_LOG(LogTemp, Log, TEXT("AdministerGloomwoodDampener: Suppressed Shadow Sickness! Restored +30 Sanity. Charges left: %d"), GloomwoodDampenerCharges);

	if (KaelenActor->Implements<UAshenCharacterInterface>())
	{
		if (UAshenOath_SanityComponent* Sanity = IAshenCharacterInterface::Execute_GetSanityComponent(KaelenActor))
		{
			Sanity->HealSanity(30.0f);
		}
	}


	OnMatrixDeployed.Broadcast(TEXT("GloomwoodDampener"), KaelenActor->GetActorLocation());
	return true;
}

bool UAshenOath_AlchemicalComponent::ThrowSulfurousSmokeBalm(FVector TargetLocation)
{
	if (SulfurousSmokeBalmCharges <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("ThrowSulfurousSmokeBalm failed: Out of charges."));
		return false;
	}

	SulfurousSmokeBalmCharges--;
	UE_LOG(LogTemp, Log, TEXT("ThrowSulfurousSmokeBalm: Sulfurous smoke cloud spawned at %s (400uu radius blind). Charges left: %d"), *TargetLocation.ToString(), SulfurousSmokeBalmCharges);

	if (GetWorld() && GetWorld()->GetGameInstance())
	{
		if (UAshenOath_GameEventSubsystem* EventBus = GetWorld()->GetGameInstance()->GetSubsystem<UAshenOath_GameEventSubsystem>())
		{
			EventBus->BroadcastSpatialSoundRequested(nullptr, TargetLocation, 0.8f, 1.0f);
		}
	}

	OnMatrixDeployed.Broadcast(TEXT("SulfurousSmokeBalm"), TargetLocation);
	return true;
}

bool UAshenOath_AlchemicalComponent::DeployGhostbloomTripwire(FVector TripwireLocation)
{
	if (GhostbloomTripwireCharges <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("DeployGhostbloomTripwire failed: Out of charges."));
		return false;
	}

	GhostbloomTripwireCharges--;
	UE_LOG(LogTemp, Log, TEXT("DeployGhostbloomTripwire: Ghostbloom flash tripwire seeded at %s (600uu stun flare). Charges left: %d"), *TripwireLocation.ToString(), GhostbloomTripwireCharges);

	OnMatrixDeployed.Broadcast(TEXT("GhostbloomTripwire"), TripwireLocation);
	return true;
}
