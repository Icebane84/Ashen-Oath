// Copyright Phoenix Protocol. All rights reserved.

#include "AshenOath_LockOnComponent.h"
#include "AshenOath_HurtboxComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"
#include "CollisionQueryParams.h"
#include "AshenGameSettings.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/OverlapResult.h"

UAshenOath_LockOnComponent::UAshenOath_LockOnComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	LockOnRange = 1500.0f;
	RotationInterpolationSpeed = 5.0f;
	bIsLockedOn = false;
	LockedTarget = nullptr;
}

void UAshenOath_LockOnComponent::BeginPlay()
{
	Super::BeginPlay();

	// Load configuration-driven settings
	if (const UAshenGameSettings* Settings = GetDefault<UAshenGameSettings>())
	{
		LockOnRange = Settings->LockOnRange;
		RotationInterpolationSpeed = Settings->RotationInterpolationSpeed;
	}
}

void UAshenOath_LockOnComponent::ToggleLockOn()
{
	if (bIsLockedOn)
	{
		ClearLockOn();
	}
	else
	{
		AActor* FoundTarget = ScanForTargets();
		if (FoundTarget)
		{
			SetLockedTarget(FoundTarget);
		}
	}
}

void UAshenOath_LockOnComponent::UpdateLockOnRotation(float DeltaTime)
{
	if (!bIsLockedOn || !LockedTarget.IsValid())
	{
		return;
	}

	AActor* OwnerActor = GetOwner();
	if (!OwnerActor) return;

	// Range Check
	float Distance = FVector::Dist(OwnerActor->GetActorLocation(), LockedTarget->GetActorLocation());
	if (Distance > LockOnRange)
	{
		ClearLockOn();
		return;
	}

	// Resolve Controller
	APawn* OwnerPawn = Cast<APawn>(OwnerActor);
	if (!OwnerPawn) return;

	APlayerController* PC = Cast<APlayerController>(OwnerPawn->GetController());
	if (!PC) return;

	// Calculate LookAt Rotation
	FVector StartLoc = PC->PlayerCameraManager ? PC->PlayerCameraManager->GetCameraLocation() : OwnerActor->GetActorLocation();
	FVector TargetLoc = LockedTarget->GetActorLocation();

	// Smoothly interpolate camera look-at
	FRotator TargetRot = UKismetMathLibrary::FindLookAtRotation(StartLoc, TargetLoc);
	FRotator CurrentRot = PC->GetControlRotation();

	// Keep roll and pitch movements clean
	TargetRot.Roll = CurrentRot.Roll;

	FRotator NewRot = FMath::RInterpTo(CurrentRot, TargetRot, DeltaTime, RotationInterpolationSpeed);
	PC->SetControlRotation(NewRot);
}

void UAshenOath_LockOnComponent::SetLockedTarget(AActor* Target)
{
	if (Target && Target != GetOwner())
	{
		LockedTarget = Target;
		bIsLockedOn = true;
		OnLockOnTargetChanged.Broadcast(Target, true);
	}
	else
	{
		ClearLockOn();
	}
}

void UAshenOath_LockOnComponent::ClearLockOn()
{
	LockedTarget.Reset();
	bIsLockedOn = false;
	OnLockOnTargetChanged.Broadcast(nullptr, false);
}

AActor* UAshenOath_LockOnComponent::GetLockedTarget() const
{
	return LockedTarget.IsValid() ? LockedTarget.Get() : nullptr;
}

AActor* UAshenOath_LockOnComponent::ScanForTargets()
{
	AActor* OwnerActor = GetOwner();
	if (!OwnerActor) return nullptr;

	FVector Start = OwnerActor->GetActorLocation();
	FCollisionShape Sphere = FCollisionShape::MakeSphere(LockOnRange);

	TArray<FOverlapResult> Overlaps;
	FCollisionObjectQueryParams ObjectParams(FCollisionObjectQueryParams::AllObjects);
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(OwnerActor);

	bool bHit = GetWorld()->OverlapMultiByObjectType(
		Overlaps,
		Start,
		FQuat::Identity,
		ObjectParams,
		Sphere,
		Params
	);

	if (!bHit) return nullptr;

	AActor* BestTarget = nullptr;
	float BestScore = -1.0f; // Dot product score (closer to 1 is better)

	FVector ViewDir = OwnerActor->GetActorForwardVector();

	for (const FOverlapResult& Overlap : Overlaps)
	{
		AActor* Candidate = Overlap.GetActor();
		if (!Candidate || Candidate == OwnerActor) continue;

		// Make sure it implements IAshenCharacterInterface or has a Hurtbox
		if (!Candidate->FindComponentByClass<UAshenOath_HurtboxComponent>()) continue;

		FVector TargetDir = (Candidate->GetActorLocation() - Start).GetSafeNormal();
		float AngleScore = FVector::DotProduct(ViewDir, TargetDir);

		if (AngleScore > BestScore)
		{
			BestScore = AngleScore;
			BestTarget = Candidate;
		}
	}

	return BestTarget;
}
