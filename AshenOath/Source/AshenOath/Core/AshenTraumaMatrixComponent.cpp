// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenTraumaMatrixComponent.h"
#include "AshenCharacterInterface.h"
#include "AshenOath_SanityComponent.h"
#include "AshenOath_WardenComponent.h"
#include "AshenOath_GameEventSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

UAshenTraumaMatrixComponent::UAshenTraumaMatrixComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	TargetVector = EAshenOathCompanion::Kaelen;
	AdversarialArgument = TEXT("Preparation is an illusion");
	DisruptionMultiplier = 1.5f;
}

void UAshenTraumaMatrixComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenTraumaMatrixComponent::EvaluateTraumaDisruption(AActor* TargetActor)
{
	if (!TargetActor)
	{
		return;
	}

	float DisruptionMagnitude = 20.0f * DisruptionMultiplier;
	UE_LOG(LogTemp, Log, TEXT("UAshenTraumaMatrixComponent: Evaluating trauma vector against Companion %d ('%s'). Disruption: %.1f"),
		static_cast<int32>(TargetVector), *AdversarialArgument, DisruptionMagnitude);

	OnTraumaDisruptionEvaluated.Broadcast(TargetVector, AdversarialArgument, DisruptionMagnitude);
}

void UAshenTraumaMatrixComponent::ApplyTraumaExpenditure(AActor* TargetActor, float RawToll)
{
	if (!TargetActor)
	{
		return;
	}

	float ScaledToll = RawToll * DisruptionMultiplier;

	if (TargetActor->Implements<UAshenCharacterInterface>())
	{
		if (UAshenOath_SanityComponent* Sanity = IAshenCharacterInterface::Execute_GetSanityComponent(TargetActor))
		{
			Sanity->SufferMentalDamage(ScaledToll);
		}
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenTraumaMatrixComponent: Applied trauma expenditure (Raw: %.1f -> Scaled: %.1f) to target."), RawToll, ScaledToll);
}
