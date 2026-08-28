// Fill out your copyright notice in the Description page of Project Settings.

#include "AshenOath_HurtboxComponent.h"
#include "AshenOathCharacter.h"
#include "AshenOath_HealthComponent.h"
#include "AshenCharacterInterface.h"
#include "AshenOath_PoiseComponent.h"
#include "Soul/AshenSoulConstellationSubsystem.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "AshenGameSettings.h"

UAshenOath_HurtboxComponent::UAshenOath_HurtboxComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	TeamId = 1;
	HealthComponent = nullptr;
	bIsParryWindow = false;

	SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	SetGenerateOverlapEvents(true);
}

void UAshenOath_HurtboxComponent::BeginPlay()
{
	Super::BeginPlay();

	if (GetOwner())
	{
		HealthComponent = GetOwner()->FindComponentByClass<UAshenOath_HealthComponent>();
	}
}

float UAshenOath_HurtboxComponent::ReceiveDamage(float DamageAmount, float PoiseAmount, AActor* DamageSource)
{
	// 0. Invulnerability Frames (i-Frames) during active Dodge Roll
	if (AActor* OwnerActor = GetOwner())
	{
		if (AAshenOathCharacter* AshenChar = Cast<AAshenOathCharacter>(OwnerActor))
		{
			if (AshenChar->IsDodging())
			{
				// Total damage & poise immunity during invincibility roll frames
				return 0.0f;
			}
		}
	}

	// 1. Parry Window check with Integration Debt (Runtime Noise) degradation
	if (bIsParryWindow)
	{
		bool bParrySucceeded = true;
		if (UWorld* World = GetWorld())
		{
			if (UGameInstance* GI = World->GetGameInstance())
			{
				if (UAshenSoulConstellationSubsystem* Kernel = GI->GetSubsystem<UAshenSoulConstellationSubsystem>())
				{
					// ENGINE-SPEC-001 Section 2: Runtime Noise narrows parry window by 15%
					if (Kernel->GetDebtStage() == EAshenIntegrationDebtStage::RuntimeNoise || Kernel->GetDebtStage() == EAshenIntegrationDebtStage::ForcedCollapse)
					{
						if (FMath::FRand() < 0.15f)
						{
							bParrySucceeded = false; // Runtime Noise caused parry timing window slip
						}
					}
				}
			}
		}

		if (bParrySucceeded)
		{
			OnParryTriggered.Broadcast(DamageSource);
			return 0.0f;
		}
	}

	// 2. Normal Damage Application

	float ActualDamage = 0.0f;
	if (HealthComponent)
	{
		ActualDamage = HealthComponent->ReceiveDamage(DamageAmount, DamageSource);
	}

	// 3. Poise Damage Application
	if (GetOwner() && GetOwner()->Implements<UAshenCharacterInterface>())
	{
		UAshenOath_PoiseComponent* Poise = IAshenCharacterInterface::Execute_GetPoiseComponent(GetOwner());
		if (Poise)
		{
			Poise->ApplyPoiseDamage(PoiseAmount);
		}
	}

	// 4. Hitstop & Time Dilation (Game Feel)
	if (GetWorld())
	{
		float HitstopDuration = 0.08f; // light hit default
		float TimeScale = 0.08f;

		if (PoiseAmount >= 50.0f)
		{
			HitstopDuration = 0.20f; // heavy poise break/impact
			TimeScale = 0.02f;
		}
		else if (DamageAmount >= 25.0f)
		{
			HitstopDuration = 0.12f; // medium hit
			TimeScale = 0.05f;
		}

		UGameplayStatics::SetGlobalTimeDilation(GetWorld(), TimeScale);

		FTimerHandle HitstopTimerHandle;
		float FinalDuration = HitstopDuration * GetDefault<UAshenGameSettings>()->HitstopDurationMultiplier;
		float CompensatedTime = FinalDuration * TimeScale; // adjust for dilated time scale
		GetWorld()->GetTimerManager().SetTimer(
			HitstopTimerHandle,
			FTimerDelegate::CreateUObject(this, &UAshenOath_HurtboxComponent::ResetHitstop),
			CompensatedTime,
			false
		);
	}

	return ActualDamage;
}

void UAshenOath_HurtboxComponent::ResetHitstop()
{
	if (GetWorld())
	{
		UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 1.0f);
	}
}
