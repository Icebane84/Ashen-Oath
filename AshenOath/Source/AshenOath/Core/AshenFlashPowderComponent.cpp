// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenFlashPowderComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TimerManager.h"
#include "Engine/World.h"

UAshenFlashPowderComponent::UAshenFlashPowderComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bIsBlinded = false;
}

void UAshenFlashPowderComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenFlashPowderComponent::ApplyFlashBlindness(float Duration)
{
	bIsBlinded = true;
	AActor* OwnerActor = GetOwner();

	// Apply move speed penalty if owner is a character
	if (ACharacter* Char = Cast<ACharacter>(OwnerActor))
	{
		if (UCharacterMovementComponent* MoveComp = Char->GetCharacterMovement())
		{
			MoveComp->MaxWalkSpeed *= 0.5f; // 50% slow penalty
		}
	}

	if (GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(BlindnessTimerHandle);
		GetWorld()->GetTimerManager().SetTimer(BlindnessTimerHandle, this, &UAshenFlashPowderComponent::ClearFlashBlindness, Duration, false);
	}

	OnBlindnessStateChanged.Broadcast(true);
	UE_LOG(LogTemp, Warning, TEXT("UAshenFlashPowderComponent: Enemy '%s' blinded for %.1fs!"),
		OwnerActor ? *OwnerActor->GetName() : TEXT("None"), Duration);
}

void UAshenFlashPowderComponent::ClearFlashBlindness()
{
	if (!bIsBlinded) return;

	bIsBlinded = false;
	AActor* OwnerActor = GetOwner();

	if (ACharacter* Char = Cast<ACharacter>(OwnerActor))
	{
		if (UCharacterMovementComponent* MoveComp = Char->GetCharacterMovement())
		{
			MoveComp->MaxWalkSpeed *= 2.0f; // Restore move speed
		}
	}

	if (GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(BlindnessTimerHandle);
	}

	OnBlindnessStateChanged.Broadcast(false);
	UE_LOG(LogTemp, Log, TEXT("UAshenFlashPowderComponent: Flash blindness expired. Movement speed restored."));
}
