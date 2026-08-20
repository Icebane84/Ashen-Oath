// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenTraumaPostProcessComponent.h"
#include "AshenTraumaMatrixComponent.h"
#include "GameFramework/Actor.h"

UAshenTraumaPostProcessComponent::UAshenTraumaPostProcessComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	CurrentTraumaLevel = 0.0f;
}

void UAshenTraumaPostProcessComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenTraumaPostProcessComponent::SetTraumaLevel(float NewTrauma)
{
	CurrentTraumaLevel = FMath::Clamp(NewTrauma, 0.0f, 1.0f);
	TargetChromaticAberration = FMath::Lerp(0.0f, 1.5f, CurrentTraumaLevel);
	TargetVignetteIntensity = FMath::Lerp(0.0f, 0.8f, CurrentTraumaLevel);
}

void UAshenTraumaPostProcessComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* OwnerActor = GetOwner();
	if (OwnerActor)
	{
		if (UAshenTraumaMatrixComponent* TraumaComp = OwnerActor->FindComponentByClass<UAshenTraumaMatrixComponent>())
		{
			SetTraumaLevel(FMath::Clamp(TraumaComp->DisruptionMultiplier / 3.0f, 0.0f, 1.0f));
		}
	}

	CurrentChromaticAberration = FMath::FInterpTo(CurrentChromaticAberration, TargetChromaticAberration, DeltaTime, 4.0f);
	CurrentVignetteIntensity = FMath::FInterpTo(CurrentVignetteIntensity, TargetVignetteIntensity, DeltaTime, 4.0f);

	OnTraumaVisualsUpdated.Broadcast(CurrentChromaticAberration, CurrentVignetteIntensity);
}
