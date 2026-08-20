// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenPartyOrchestratorComponent.h"
#include "AshenCompanionBarkComponent.h"
#include "AshenOath_TrustAccumulationComponent.h"
#include "AshenOath_AlchemicalComponent.h"
#include "AshenOath_WardenComponent.h"
#include "AshenCompanionAIComponent.h"
#include "AshenCharacterInterface.h"
#include "AshenOath_PoiseComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

UAshenPartyOrchestratorComponent::UAshenPartyOrchestratorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenPartyOrchestratorComponent::BeginPlay()
{
	Super::BeginPlay();

	AActor* Owner = GetOwner();
	if (Owner)
	{
		if (!TrustComponent)
		{
			TrustComponent = Owner->FindComponentByClass<UAshenOath_TrustAccumulationComponent>();
		}
		if (!AlchemicalComponent)
		{
			AlchemicalComponent = Owner->FindComponentByClass<UAshenOath_AlchemicalComponent>();
		}
		if (!WardenComponent)
		{
			WardenComponent = Owner->FindComponentByClass<UAshenOath_WardenComponent>();
		}
		if (!CompanionAIComponent)
		{
			CompanionAIComponent = Owner->FindComponentByClass<UAshenCompanionAIComponent>();
		}
	}
}

bool UAshenPartyOrchestratorComponent::ExecuteSentinelsBulwarkCombo(AActor* TargetEnemy)
{
	if (!TargetEnemy)
	{
		UE_LOG(LogTemp, Warning, TEXT("ExecuteSentinelsBulwarkCombo failed: Null TargetEnemy."));
		return false;
	}

	FVector EnemyLoc = TargetEnemy->GetActorLocation();

	// 1. Garrett deploys smoke balm
	if (AlchemicalComponent)
	{
		AlchemicalComponent->ThrowSulfurousSmokeBalm(EnemyLoc);
	}

	// 2. Serafina casts Sun Pulse
	if (WardenComponent)
	{
		WardenComponent->CastSunPulse(600.0f);
	}

	// 3. Kaelen gains poise reset
	AActor* Owner = GetOwner();
	if (Owner && Owner->Implements<UAshenCharacterInterface>())
	{
		if (UAshenOath_PoiseComponent* Poise = IAshenCharacterInterface::Execute_GetPoiseComponent(Owner))
		{
			Poise->ResetPoise();
		}
	}

	UE_LOG(LogTemp, Log, TEXT("ExecuteSentinelsBulwarkCombo: Trio executed Sentinel's Bulwark Combo on target!"));
	OnPartyComboTriggered.Broadcast(TEXT("SentinelsBulwark"), TargetEnemy);
	return true;
}

bool UAshenPartyOrchestratorComponent::ExecuteResonantCleaveFinisher(AActor* TargetEnemy)
{
	if (!TargetEnemy)
	{
		UE_LOG(LogTemp, Warning, TEXT("ExecuteResonantCleaveFinisher failed: Null TargetEnemy."));
		return false;
	}

	if (!IsTrioSynchronized())
	{
		UE_LOG(LogTemp, Warning, TEXT("ExecuteResonantCleaveFinisher failed: Trio is not in Synchronized trust band."));
		return false;
	}

	// Deal 150 heavy finisher damage
	UGameplayStatics::ApplyDamage(TargetEnemy, 150.0f, nullptr, GetOwner(), UDamageType::StaticClass());

	// Trigger Symbiotic Resonance flow state for 8 seconds
	if (CompanionAIComponent)
	{
		CompanionAIComponent->TriggerSymbioticResonance();
	}

	UE_LOG(LogTemp, Log, TEXT("ExecuteResonantCleaveFinisher: TRIO FINISHER EXECUTED! 150 damage dealt + Symbiotic Flow activated!"));
	OnPartyComboTriggered.Broadcast(TEXT("ResonantCleaveFinisher"), TargetEnemy);
	return true;
}

bool UAshenPartyOrchestratorComponent::IsTrioSynchronized() const
{
	if (!TrustComponent)
	{
		return false;
	}

	FAshenOathTrustPairKey KaelenGarrett(EAshenOathCompanion::Kaelen, EAshenOathCompanion::Garrett);
	FAshenOathTrustPairKey KaelenSerafina(EAshenOathCompanion::Kaelen, EAshenOathCompanion::Serafina);

	EAshenOathTrustBand Band1 = TrustComponent->GetTrustBand(KaelenGarrett);
	EAshenOathTrustBand Band2 = TrustComponent->GetTrustBand(KaelenSerafina);

	return (Band1 == EAshenOathTrustBand::Synchronized || Band1 == EAshenOathTrustBand::Cooperative) &&
	       (Band2 == EAshenOathTrustBand::Synchronized || Band2 == EAshenOathTrustBand::Cooperative);
}
