// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenDynamicCameraFOVComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Actor.h"

UAshenDynamicCameraFOVComponent::UAshenDynamicCameraFOVComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	CurrentFOV = 75.0f;
	TargetFOV = 75.0f;
	DefaultFOV = 75.0f;
	SprintFOV = 95.0f;
	CurrentInterpSpeed = 3.0f;
}

void UAshenDynamicCameraFOVComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenDynamicCameraFOVComponent::SetTargetFOV(float InTargetFOV, float InterpSpeed)
{
	TargetFOV = FMath::Clamp(InTargetFOV, 60.0f, 120.0f);
	CurrentInterpSpeed = FMath::Max(0.1f, InterpSpeed);
}

void UAshenDynamicCameraFOVComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!FMath::IsNearlyEqual(CurrentFOV, TargetFOV, 0.01f))
	{
		CurrentFOV = FMath::FInterpTo(CurrentFOV, TargetFOV, DeltaTime, CurrentInterpSpeed);

		AActor* OwnerActor = GetOwner();
		if (OwnerActor)
		{
			if (UCameraComponent* CameraComp = OwnerActor->FindComponentByClass<UCameraComponent>())
			{
				CameraComp->SetFieldOfView(CurrentFOV);
			}
		}

		OnFOVUpdated.Broadcast(CurrentFOV);
	}
}
