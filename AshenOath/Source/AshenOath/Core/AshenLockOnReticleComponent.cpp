// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenLockOnReticleComponent.h"
#include "AshenOath_LockOnComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"

UAshenLockOnReticleComponent::UAshenLockOnReticleComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	bIsLockedOn = false;
	CurrentScreenPosition = FVector2D::ZeroVector;
}

void UAshenLockOnReticleComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenLockOnReticleComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* OwnerActor = GetOwner();
	if (!OwnerActor) return;

	UAshenOath_LockOnComponent* LockOnComp = OwnerActor->FindComponentByClass<UAshenOath_LockOnComponent>();
	if (!LockOnComp) return;

	AActor* LockedTarget = LockOnComp->GetLockedTarget();
	bIsLockedOn = (LockedTarget != nullptr);

	if (bIsLockedOn && GetWorld())
	{
		APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		if (PC)
		{
			FVector TargetLocation = LockedTarget->GetActorLocation() + FVector(0.0f, 0.0f, 50.0f);
			PC->ProjectWorldLocationToScreen(TargetLocation, CurrentScreenPosition);
		}
	}
	else
	{
		CurrentScreenPosition = FVector2D::ZeroVector;
	}

	OnTargetReticleUpdated.Broadcast(bIsLockedOn, CurrentScreenPosition, LockedTarget);
}
