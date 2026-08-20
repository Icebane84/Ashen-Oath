// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenStaminaExhaustionComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"

UAshenStaminaExhaustionComponent::UAshenStaminaExhaustionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bIsExhausted = false;
	ExhaustionRecoveryThreshold = 0.25f;
	MovementSpeedPenalty = 0.5f;
}

void UAshenStaminaExhaustionComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenStaminaExhaustionComponent::CheckExhaustionState(float CurrentStamina, float MaxStamina)
{
	if (MaxStamina <= 0.0f) return;
	float StaminaRatio = CurrentStamina / MaxStamina;

	if (!bIsExhausted && CurrentStamina <= 0.0f)
	{
		// Enter exhaustion state
		bIsExhausted = true;

		if (ACharacter* OwnerChar = Cast<ACharacter>(GetOwner()))
		{
			if (UCharacterMovementComponent* Movement = OwnerChar->GetCharacterMovement())
			{
				Movement->MaxWalkSpeed *= MovementSpeedPenalty;
			}
		}

		OnExhaustionEntered.Broadcast();
		UE_LOG(LogTemp, Warning, TEXT("UAshenStaminaExhaustionComponent: Stamina depleted — exhaustion state ENTERED (50 pct speed penalty)."));
	}
	else if (bIsExhausted && StaminaRatio >= ExhaustionRecoveryThreshold)
	{
		// Exit exhaustion state
		bIsExhausted = false;

		if (ACharacter* OwnerChar = Cast<ACharacter>(GetOwner()))
		{
			if (UCharacterMovementComponent* Movement = OwnerChar->GetCharacterMovement())
			{
				Movement->MaxWalkSpeed /= MovementSpeedPenalty;
			}
		}

		OnExhaustionExited.Broadcast();
		UE_LOG(LogTemp, Warning, TEXT("UAshenStaminaExhaustionComponent: Stamina recovered above 25 pct — exhaustion state EXITED."));
	}
}
